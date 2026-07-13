#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
# Thin wrapper that installs the build-time dependencies for the
# audiobox_vsl kernel module. All real build, install, and clean
# commands live in the top-level Makefile. This script is intentionally
# minimal: it only ensures the toolchain and kernel headers are
# present, then exits.

set -euo pipefail

if [ "$(id -u)" -ne 0 ]; then
    echo "This script must be run as root (use sudo)." >&2
    exit 1
fi

if ! command -v apt-get >/dev/null 2>&1; then
    echo "apt-get not found. This script targets Debian/Ubuntu/Kali." >&2
    exit 1
fi

KVER="$(uname -r)"

echo "Installing build dependencies for audiobox_vsl on kernel ${KVER}..."

apt-get update -qq
apt-get install -y -qq build-essential perl "linux-headers-${KVER}" \
    libusb-1.0-0-dev libcmocka-dev

if [ ! -d "/lib/modules/${KVER}/build" ]; then
    echo "Kernel headers for ${KVER} are still missing." >&2
    exit 1
fi

cp 99-audiobox-vsl.rules /etc/udev/rules.d/ 2>/dev/null || true
udevadm control --reload-rules 2>/dev/null || true
udevadm trigger 2>/dev/null || true

echo "Done. Next steps:"
echo "  make            build the kernel module and run the test suite"
echo "  sudo make install    install the module and run depmod"
echo "  sudo make modprobe   load the module"
echo "  src/vsl_cli gain 1 0.75   test VSL DSP control"
echo "  ./configure     verify the build environment"
