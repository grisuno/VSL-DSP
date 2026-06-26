#!/bin/bash
# SPDX-License-Identifier: GPL-2.0-or-later
# Install prerequisites for building the AudioBox 22 VSL kernel module

set -e

# Text colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo_title() {
    echo -e "${BLUE}=== $1 ===${NC}"
}

echo_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

echo_warn() {
    echo -e "${YELLOW}[WARN]${NC} $1"
}

echo_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

echo_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

# Check if running as root (needed for installing packages)
if [ "$EUID" -ne 0 ]; then
    echo_error "This script must be run as root (use sudo)."
    exit 1
fi

echo_title "Installing Prerequisites for AudioBox 22 VSL Driver"

# Update package list
echo_info "Updating package list..."
apt-get update -qq

# Install essential build tools
echo_info "Installing build tools..."
apt-get install -y -qq build-essential perl

# Determine kernel version and install headers
KERNEL_VERSION=$(uname -r)
echo_info "Kernel version: $KERNEL_VERSION"
echo_info "Installing Linux headers for $KERNEL_VERSION..."
apt-get install -y -qq "linux-headers-$KERNEL_VERSION"

# Verify installation
if [ ! -d "/lib/modules/$KERNEL_VERSION/build" ]; then
    echo_error "Failed to install Linux headers for $KERNEL_VERSION"
    exit 1
fi

echo_success "Prerequisites installed successfully!"
echo_info "You can now run:"
echo_info "  ./configure   (to verify)"
echo_info "  make          (to build the module)"
echo_info "  sudo make install (to install the module)"

exit 0