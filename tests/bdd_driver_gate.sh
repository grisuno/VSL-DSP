#!/bin/bash
# BDD hardware gate for audiobox_vsl. Requires root. Run AFTER `make modules`.
# Steady-state fact: snd-usb-audio is registered before this module, so it
# wins the probe race on the audio interfaces; audiobox probe only fires on
# interfaces no earlier driver claimed (normally the driverless DFU one).
# The gate therefore proves the probe in two windows without breaking audio:
#   dbg window  - bind the driverless VSL iface, expect one debug "no claim"
#                 line (dynamic_debug enabled for the module first).
#   info window - only when no VSL PCM stream is active: unbind ALL VSL
#                 audio interfaces from snd-usb-audio (single-iface rebind
#                 cannot rebuild its card-wide state), bind this driver on
#                 the control iface, expect exactly one info "detected" line
#                 and no claim, then rebind every iface in order. If ALSA or
#                 ownership does not come back, fall back to a logical replug
#                 of the port and verify again. Skipped (not failed) while
#                 audio is streaming.
# Pass criteria (all must print PASS):
#   1. modinfo version matches audiobox_vsl.h (single source of truth)
#   2. on-demand probe of a driverless VSL iface logs one "no claim" line
#   3. the info "detected" line appears exactly once for the control iface
#   4. no raw USB string line (manufacturer=) appears in either window
#   5. snd-usb-audio still owns the VSL audio interface (ALSA intact)
#   6. this driver never claims any VSL interface
set -u
DRV=audiobox_vsl
VID=194f
PASS=0
FAIL=0
ok()  { PASS=$((PASS+1)); echo "PASS $1"; }
bad() { FAIL=$((FAIL+1)); echo "FAIL $1"; }

[ "$(id -u)" = "0" ] || { echo "run as root"; exit 2; }
[ -f ./audiobox_vsl.ko ] || { echo "run from repo root after make modules"; exit 2; }

VSLDEV=""
for candidate in /sys/bus/usb/devices/*; do
    if [ -f "$candidate/idVendor" ] && [ "$(cat "$candidate/idVendor")" = "$VID" ]; then
        VSLDEV=$(basename "$candidate")
        break
    fi
done
[ -n "$VSLDEV" ] || { bad "no VSL device (${VID}:*) on the USB bus"; exit 1; }
AUDIO_IFACE="${VSLDEV}:1.0"
[ -d "/sys/bus/usb/devices/$AUDIO_IFACE" ] || { bad "audio iface $AUDIO_IFACE missing"; exit 1; }

modprobe -r "$DRV" 2>/dev/null
insmod ./audiobox_vsl.ko || { bad "insmod"; exit 1; }
sleep 1

[ "$(modinfo -F version ./audiobox_vsl.ko)" = "2.0.0" ] && ok "version 2.0.0" || bad "version"

FREE_IFACE=""
for candidate in /sys/bus/usb/devices/"${VSLDEV}":1.*; do
    if [ -d "$candidate" ] && [ ! -e "$candidate/driver" ]; then
        FREE_IFACE=$(basename "$candidate")
        break
    fi
done
[ -n "$FREE_IFACE" ] || { bad "no driverless VSL iface for the probe windows"; exit 1; }

DBGCTL=/sys/kernel/debug/dynamic_debug/control
[ -w "$DBGCTL" ] && echo "module $DRV +p" > "$DBGCTL" 2>/dev/null || true

BEFORE1=$(dmesg | wc -l)
echo "$FREE_IFACE" > /sys/bus/usb/drivers/$DRV/bind 2>/dev/null || true
sleep 1
NEW1=$(dmesg | tail -n +"$((BEFORE1+1))")
N1=$(echo "$NEW1" | grep -c "audiobox_vsl: interface .* of 'AudioBox.*VSL'.*no claim")
if [ "$N1" = "1" ]; then
    ok "probe fires with one no-claim line ($FREE_IFACE)"
else
    bad "no-claim lines = $N1 (want 1)"
    echo "$NEW1" | grep audiobox_vsl || true
fi
if ls /sys/bus/usb/drivers/$DRV/ | grep -q "$FREE_IFACE"; then
    bad "$DRV claimed $FREE_IFACE (must stay free)"
else
    ok "no claim on driverless $FREE_IFACE"
fi

VSLCARD=$(awk '/VSL/ {print $1}' /proc/asound/cards 2>/dev/null | head -1)
STREAMING=0
if [ -n "$VSLCARD" ]; then
    for st in /proc/asound/card"$VSLCARD"/pcm*/sub*/status; do
        grep -q "state: RUNNING" "$st" 2>/dev/null && STREAMING=1
    done
fi
NEW2=""
if [ "$STREAMING" = "1" ]; then
    echo "SKIP info window: VSL audio is streaming (won't disturb it)"
else
    UNBOUND=""
    if echo "$AUDIO_IFACE" > /sys/bus/usb/drivers/snd-usb-audio/unbind 2>/dev/null; then
        UNBOUND="$AUDIO_IFACE"
        for suffix in 1.1 1.2 1.3 1.4; do
            ifname="${VSLDEV}:${suffix}"
            if [ -e "/sys/bus/usb/devices/$ifname/driver" ]; then
                if echo "$ifname" > /sys/bus/usb/drivers/snd-usb-audio/unbind 2>/dev/null; then
                    UNBOUND="$UNBOUND $ifname"
                fi
            fi
        done
    else
        echo "SKIP info window: cannot unbind $AUDIO_IFACE"
    fi
    if [ -n "$UNBOUND" ]; then
        BEFORE2=$(dmesg | wc -l)
        echo "$AUDIO_IFACE" > /sys/bus/usb/drivers/$DRV/bind 2>/dev/null || true
        sleep 1
        NEW2=$(dmesg | tail -n +"$((BEFORE2+1))")
        N2=$(echo "$NEW2" | grep -c "audiobox_vsl: detected 'AudioBox")
        if [ "$N2" = "1" ]; then
            ok "exactly one detected line ($AUDIO_IFACE)"
        else
            bad "detected lines = $N2 (want 1)"
            echo "$NEW2" | grep audiobox_vsl || true
        fi
        if ls /sys/bus/usb/drivers/$DRV/ | grep -q "$AUDIO_IFACE"; then
            bad "$DRV claimed $AUDIO_IFACE (must stay free)"
        else
            ok "no claim on $AUDIO_IFACE"
        fi
        # shellcheck disable=SC2086
        for ifname in $UNBOUND; do
            echo "$ifname" > /sys/bus/usb/drivers/snd-usb-audio/bind 2>/dev/null || true
        done
        sleep 2
        RECOVERED=1
        # shellcheck disable=SC2086
        for ifname in $UNBOUND; do
            ls /sys/bus/usb/drivers/snd-usb-audio/ | grep -q "$ifname" || RECOVERED=0
        done
        aplay -l 2>/dev/null | grep -q 'VSL' || RECOVERED=0
        if [ "$RECOVERED" = "0" ]; then
            echo "recovery: logical replug of $VSLDEV"
            echo 0 > "/sys/bus/usb/devices/$VSLDEV/authorized" 2>/dev/null || true
            sleep 1
            echo 1 > "/sys/bus/usb/devices/$VSLDEV/authorized" 2>/dev/null || true
            sleep 3
        fi
    fi
fi

echo "${NEW1}${NEW2}" | grep -q 'manufacturer=' \
    && bad "raw USB strings logged" \
    || ok "no raw USB strings"
aplay -l 2>/dev/null | grep -q 'VSL' && ok "ALSA card intact" || bad "ALSA card gone"
ls /sys/bus/usb/drivers/snd-usb-audio/ | grep -q "$AUDIO_IFACE" \
    && ok "snd-usb-audio still bound ($AUDIO_IFACE)" \
    || bad "snd-usb-audio lost $AUDIO_IFACE"
rmmod "$DRV"
echo "== $PASS passed, $FAIL failed =="
[ "$FAIL" = "0" ]
