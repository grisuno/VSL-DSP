#!/bin/bash
# BDD hardware gate for audiobox_vsl. Requires root. Run AFTER `make modules`.
# Safe by design: bind-only probing, probe returns -ENODEV, snd-usb-audio
# keeps the interface at all times. No replug, no unbind.
# Pass criteria (all must print PASS):
#   1. modinfo version is 2.0.0 (single source from audiobox_vsl.h)
#   2. bind of interface 1.0 logs exactly one "detected" info line
#   3. no raw USB string line (manufacturer=) appears
#   4. snd-usb-audio still owns the card (ALSA intact)
set -u
DRV=audiobox_vsl
PASS=0
FAIL=0
ok()  { PASS=$((PASS+1)); echo "PASS $1"; }
bad() { FAIL=$((FAIL+1)); echo "FAIL $1"; }

[ "$(id -u)" = "0" ] || { echo "run as root"; exit 2; }
[ -f ./audiobox_vsl.ko ] || { echo "run from repo root after make modules"; exit 2; }
modprobe -r "$DRV" 2>/dev/null
insmod ./audiobox_vsl.ko || { bad "insmod"; exit 1; }

[ "$(modinfo -F version ./audiobox_vsl.ko)" = "2.0.0" ] && ok "version 2.0.0" || bad "version"

IFACE=$(ls -d /sys/bus/usb/devices/*:1.0 2>/dev/null | head -1 | xargs basename)
[ -n "$IFACE" ] || { bad "iface found"; exit 1; }
BEFORE=$(dmesg | wc -l)
echo "$IFACE" > /sys/bus/usb/drivers/$DRV/bind 2>/dev/null
sleep 1
NEW=$(dmesg | tail -n +"$((BEFORE+1))")
N=$(echo "$NEW" | grep -c "audiobox_vsl: detected 'AudioBox 22 VSL'")
[ "$N" = "1" ] && ok "exactly one detected line" || { bad "detected lines = $N"; echo "$NEW" | grep audiobox_vsl; }
echo "$NEW" | grep -q 'manufacturer=' && bad "raw USB strings logged" || ok "no raw USB strings"
aplay -l 2>/dev/null | grep -q 'VSL' && ok "ALSA card intact" || bad "ALSA card gone"
ls /sys/bus/usb/drivers/snd-usb-audio/ | grep -q "$IFACE" && ok "snd-usb-audio still bound" || bad "snd-usb-audio lost $IFACE"
rmmod "$DRV"
echo "== $PASS passed, $FAIL failed =="
[ "$FAIL" = "0" ]
