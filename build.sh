#!/bin/bash
# AudioBox 22 VSL Enhanced Driver - Installation Script
# Copyright (c) 2025 grisuno (LazyOwn Project)
# License: GPL-2.0-or-later
#
# This script installs enhanced ALSA controls for PreSonus AudioBox 22 VSL
# using DKMS (Dynamic Kernel Module Support) for automatic kernel updates.

set -e  # Exit on error

# ============================================================================
# CONFIGURATION
# ============================================================================

DRIVER_NAME="snd-usb-audio-audiobox"
DRIVER_VERSION="2.0"
DRIVER_SOURCE_DIR="/usr/src/${DRIVER_NAME}-${DRIVER_VERSION}"

COLORS_SUPPORTED=true
if [ -t 1 ]; then
    RED='\033[0;31m'
    GREEN='\033[0;32m'
    YELLOW='\033[1;33m'
    BLUE='\033[0;34m'
    BOLD='\033[1m'
    NC='\033[0m' # No Color
else
    RED=''
    GREEN=''
    YELLOW=''
    BLUE=''
    BOLD=''
    NC=''
fi

# ============================================================================
# FUNCTIONS
# ============================================================================

print_header() {
    echo ""
    echo -e "${BLUE}=========================================="
    echo -e "$1"
    echo -e "==========================================${NC}"
    echo ""
}

print_success() {
    echo -e "${GREEN}✅ $1${NC}"
}

print_error() {
    echo -e "${RED}❌ ERROR: $1${NC}"
}

print_warning() {
    echo -e "${YELLOW}⚠️  WARNING: $1${NC}"
}

print_info() {
    echo -e "${BLUE}ℹ️  $1${NC}"
}

check_root() {
    if [ "$EUID" -ne 0 ]; then 
        print_error "This script must be run as root"
        echo "Please run: sudo $0"
        exit 1
    fi
}

check_dependencies() {
    print_header "Checking Dependencies"
    
    local missing_deps=()
    
    # Check for required packages
    if ! command -v dkms &> /dev/null; then
        missing_deps+=("dkms")
    fi
    
    if ! command -v make &> /dev/null; then
        missing_deps+=("build-essential")
    fi
    
    if ! dpkg -l | grep -q "linux-headers-$(uname -r)"; then
        missing_deps+=("linux-headers-$(uname -r)")
    fi
    
    if [ ${#missing_deps[@]} -gt 0 ]; then
        print_warning "Missing dependencies: ${missing_deps[*]}"
        print_info "Installing dependencies..."
        apt update
        apt install -y "${missing_deps[@]}"
        print_success "Dependencies installed"
    else
        print_success "All dependencies satisfied"
    fi
}

detect_audiobox() {
    print_header "Detecting AudioBox 22 VSL"
    
    if lsusb | grep -q "194f:0101"; then
        print_success "AudioBox 22 VSL detected"
        lsusb | grep "194f:0101"
        return 0
    else
        print_warning "AudioBox 22 VSL not detected"
        print_info "Please connect your AudioBox and press Enter to continue..."
        read -r
        if lsusb | grep -q "194f:0101"; then
            print_success "AudioBox 22 VSL detected"
            return 0
        else
            print_error "AudioBox 22 VSL still not detected"
            print_info "Continuing anyway - you can connect it later"
            return 1
        fi
    fi
}

create_source_structure() {
    print_header "Creating Source Directory Structure"
    
    # Remove old installation if exists
    if [ -d "$DRIVER_SOURCE_DIR" ]; then
        print_info "Removing old installation..."
        dkms remove -m "$DRIVER_NAME" -v "$DRIVER_VERSION" --all 2>/dev/null || true
        rm -rf "$DRIVER_SOURCE_DIR"
    fi
    
    # Create directory
    mkdir -p "$DRIVER_SOURCE_DIR"
    print_success "Source directory created: $DRIVER_SOURCE_DIR"
}

copy_source_files() {
    print_header "Copying Source Files"
    
    local CURRENT_DIR="$(pwd)"
    
    # Check if source files exist in current directory
    if [ ! -f "audiobox_vsl.c" ] || [ ! -f "audiobox_vsl.h" ]; then
        print_error "Source files not found in current directory"
        print_info "Expected files: audiobox_vsl.c, audiobox_vsl.h"
        print_info "Current directory: $CURRENT_DIR"
        exit 1
    fi
    
    # Copy all necessary files from sound/usb
    print_info "Copying source files..."
    
    # Copy from current kernel source tree if available
    if [ -d "/usr/src/linux-headers-$(uname -r)/sound/usb" ]; then
        cp -v /usr/src/linux-headers-$(uname -r)/sound/usb/*.c "$DRIVER_SOURCE_DIR/" 2>/dev/null || true
        cp -v /usr/src/linux-headers-$(uname -r)/sound/usb/*.h "$DRIVER_SOURCE_DIR/" 2>/dev/null || true
    fi
    
    # Copy our custom files (will overwrite if exist)
    cp -v audiobox_vsl.c "$DRIVER_SOURCE_DIR/"
    cp -v audiobox_vsl.h "$DRIVER_SOURCE_DIR/"
    
    # Copy other necessary files from local directory if they exist
    for file in *.c *.h; do
        if [ -f "$file" ] && [ "$file" != "audiobox_vsl.c" ] && [ "$file" != "audiobox_vsl.h" ]; then
            cp -v "$file" "$DRIVER_SOURCE_DIR/" 2>/dev/null || true
        fi
    done
    
    print_success "Source files copied"
}

create_dkms_conf() {
    print_header "Creating DKMS Configuration"
    
    cat > "$DRIVER_SOURCE_DIR/dkms.conf" << 'EOF'
PACKAGE_NAME="snd-usb-audio-audiobox"
PACKAGE_VERSION="2.0"
BUILT_MODULE_NAME[0]="snd-usb-audio"
BUILT_MODULE_LOCATION[0]="."
DEST_MODULE_LOCATION[0]="/updates/dkms"
AUTOINSTALL="yes"
REMAKE_INITRD="no"

MAKE[0]="make -C /lib/modules/\${kernelver}/build M=\${dkms_tree}/\${PACKAGE_NAME}/\${PACKAGE_VERSION}/build modules"
CLEAN="make -C /lib/modules/\${kernelver}/build M=\${dkms_tree}/\${PACKAGE_NAME}/\${PACKAGE_VERSION}/build clean"
EOF
    
    print_success "DKMS configuration created"
}

create_makefile() {
    print_header "Creating Makefile"
    
    cat > "$DRIVER_SOURCE_DIR/Makefile" << 'EOF'
# AudioBox VSL - Enhanced ALSA USB Audio Driver
# Copyright (c) 2025 grisuno (LazyOwn Project)
# SPDX-License-Identifier: GPL-2.0-or-later

# Module objects
snd-usb-audio-objs := \
	card.o \
	clock.o \
	endpoint.o \
	fcp.o \
	format.o \
	helper.o \
	implicit.o \
	mixer.o \
	mixer_quirks.o \
	mixer_scarlett.o \
	mixer_scarlett2.o \
	mixer_us16x08.o \
	mixer_s1810c.o \
	pcm.o \
	power.o \
	proc.o \
	quirks.o \
	stream.o \
	audiobox_vsl.o \
	validate.o \
	midi2.o

snd-usbmidi-lib-objs := midi.o

# Kernel modules
obj-m += snd-usb-audio.o
obj-m += snd-usbmidi-lib.o

# Compilation flags
ccflags-y := -I$(src)
ccflags-y += -Wno-error=implicit-function-declaration
ccflags-y += -Wno-error=int-conversion

# Default target
all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules_install

.PHONY: all clean install
EOF
    
    print_success "Makefile created"
}

verify_mixer_quirks() {
    print_header "Verifying mixer_quirks.c"
    
    local MIXER_FILE="$DRIVER_SOURCE_DIR/mixer_quirks.c"
    
    if [ ! -f "$MIXER_FILE" ]; then
        print_error "mixer_quirks.c not found!"
        exit 1
    fi
    
    # Check for include
    if ! grep -q "audiobox_vsl.h" "$MIXER_FILE"; then
        print_warning "audiobox_vsl.h include not found, adding it..."
        
        # Find the last include line and add after it
        local last_include_line=$(grep -n "^#include" "$MIXER_FILE" | tail -1 | cut -d: -f1)
        sed -i "${last_include_line}a #include \"audiobox_vsl.h\"" "$MIXER_FILE"
        
        print_success "Include added"
    else
        print_success "Include already present"
    fi
    
    # Check for case statement
    if ! grep -q "0x194f.*0x0101" "$MIXER_FILE"; then
        print_error "AudioBox case statement not found in mixer_quirks.c"
        print_info "Please add the following code to snd_usb_mixer_apply_create_quirk():"
        echo ""
        echo "    /* PreSonus AudioBox 22 VSL */"
        echo "    case USB_ID(0x194f, 0x0101):"
        echo "        err = snd_audiobox_vsl_init(mixer);"
        echo "        break;"
        echo ""
        exit 1
    else
        print_success "Case statement found"
        
        # Show the case for verification
        print_info "Current implementation:"
        grep -A 3 "0x194f.*0x0101" "$MIXER_FILE" | head -4
    fi
}

build_with_dkms() {
    print_header "Building with DKMS"
    
    # Add to DKMS
    print_info "Adding module to DKMS tree..."
    dkms add -m "$DRIVER_NAME" -v "$DRIVER_VERSION"
    
    # Build
    print_info "Building module for kernel $(uname -r)..."
    dkms build -m "$DRIVER_NAME" -v "$DRIVER_VERSION" -k "$(uname -r)"
    
    print_success "Module built successfully"
}

install_module() {
    print_header "Installing Module"
    
    # Install with DKMS
    print_info "Installing module..."
    dkms install -m "$DRIVER_NAME" -v "$DRIVER_VERSION" -k "$(uname -r)"
    
    # Update module dependencies
    print_info "Updating module dependencies..."
    depmod -a
    
    print_success "Module installed"
}

reload_module() {
    print_header "Loading Module"
    
    # Unload old module if loaded
    if lsmod | grep -q "snd_usb_audio"; then
        print_info "Unloading old snd_usb_audio module..."
        rmmod snd_usb_audio 2>/dev/null || {
            print_warning "Could not unload module (device in use)"
            print_info "Please disconnect all USB audio devices and try again"
            print_info "Or reboot your system to load the new module"
            return 1
        }
    fi
    
    # Load new module
    print_info "Loading new snd_usb_audio module..."
    modprobe snd_usb_audio
    
    print_success "Module loaded"
}

verify_installation() {
    print_header "Verifying Installation"
    
    # Check DKMS status
    print_info "DKMS status:"
    dkms status "$DRIVER_NAME"
    
    # Check if module is loaded
    if lsmod | grep -q "snd_usb_audio"; then
        print_success "Module is loaded"
    else
        print_warning "Module is not loaded"
    fi
    
    # Check which module file is being used
    local mod_file=$(modinfo snd-usb-audio 2>/dev/null | grep filename | awk '{print $2}')
    print_info "Module file: $mod_file"
    
    if echo "$mod_file" | grep -q "updates/dkms"; then
        print_success "Using DKMS module (correct)"
    else
        print_warning "Using system module (not DKMS)"
    fi
    
    # Check for AudioBox
    if lsusb | grep -q "194f:0101"; then
        print_success "AudioBox detected"
        
        # Wait a moment for initialization
        sleep 2
        
        # Check kernel logs
        print_info "Recent kernel logs:"
        dmesg | grep -i "audiobox" | tail -10
        
        # Check ALSA controls
        print_info "Checking ALSA controls..."
        local card_num=$(cat /proc/asound/cards | grep "AudioBox 22 VSL" | awk '{print $1}')
        
        if [ -n "$card_num" ]; then
            print_success "AudioBox found as card $card_num"
            
            print_info "Available controls:"
            amixer -c "$card_num" scontrols | grep "AudioBox VSL" || print_warning "Custom controls not found"
        fi
    else
        print_warning "AudioBox not connected"
    fi
}

show_usage_info() {
    print_header "Installation Complete!"
    
    cat << EOF
${GREEN}✅ AudioBox 22 VSL Enhanced Driver installed successfully!${NC}

${BOLD}What was installed:${NC}
• Enhanced ALSA controls for AudioBox 22 VSL
• DKMS module for automatic kernel updates
• 4 custom mixer controls (Playback/Capture Volume & Switch)

${BOLD}Available controls:${NC}
• AudioBox VSL Playback Volume (Stereo L/R)
• AudioBox VSL Playback Switch (Mute)
• AudioBox VSL Capture Volume (Stereo L/R)
• AudioBox VSL Capture Switch (Mute)

${BOLD}Usage examples:${NC}
# List all AudioBox controls
amixer scontrols | grep "AudioBox VSL"

# Set playback volume to 75%
amixer sset 'AudioBox VSL Playback Volume' 75%

# Toggle mute
amixer sset 'AudioBox VSL Playback Switch' off
amixer sset 'AudioBox VSL Playback Switch' on

# Use alsamixer GUI
alsamixer -c \$(cat /proc/asound/cards | grep "AudioBox 22 VSL" | awk '{print \$1}')

${BOLD}DKMS Benefits:${NC}
✅ Automatically rebuilds on kernel updates
✅ Survives system updates
✅ No manual recompilation needed

${BOLD}Troubleshooting:${NC}
If controls don't appear:
1. Disconnect and reconnect the AudioBox
2. Check logs: dmesg | grep audiobox
3. Verify module: modinfo snd-usb-audio | grep filename

${BOLD}Uninstallation:${NC}
sudo dkms remove -m $DRIVER_NAME -v $DRIVER_VERSION --all
sudo rm -rf $DRIVER_SOURCE_DIR

${BOLD}Support:${NC}
GitHub: https://github.com/grisuno/audiobox-vsl-driver
Issues: Report bugs or request features on GitHub

${GREEN}Enjoy your enhanced AudioBox 22 VSL! 🎵${NC}
EOF
}

# ============================================================================
# MAIN EXECUTION
# ============================================================================

main() {
    clear
    
    cat << 'EOF'
╔═══════════════════════════════════════════════════════════════╗
║                                                               ║
║   AudioBox 22 VSL Enhanced Driver - Installation Script      ║
║   Version 2.0 - DKMS Edition                                  ║
║                                                               ║
║   Copyright (c) 2025 grisuno (LazyOwn Project)              ║
║   License: GPL-3.0-or-later                                   ║
║                                                               ║
╚═══════════════════════════════════════════════════════════════╝

EOF
    
    print_info "Kernel: $(uname -r)"
    print_info "Architecture: $(uname -m)"
    echo ""
    
    # Check if running as root
    check_root
    
    # Step 1: Check dependencies
    check_dependencies
    
    # Step 2: Detect AudioBox (optional)
    detect_audiobox
    
    # Step 3: Create source directory
    create_source_structure
    
    # Step 4: Copy source files
    copy_source_files
    
    # Step 5: Create DKMS configuration
    create_dkms_conf
    
    # Step 6: Create Makefile
    create_makefile
    
    # Step 7: Verify mixer_quirks.c
    verify_mixer_quirks
    
    # Step 8: Build with DKMS
    build_with_dkms
    
    # Step 9: Install module
    install_module
    
    # Step 10: Reload module
    reload_module || print_warning "Module reload failed, reboot may be required"
    
    # Step 11: Verify installation
    verify_installation
    
    # Step 12: Show usage info
    show_usage_info
    
    echo ""
    print_success "Installation script completed!"
}

# Run main function
main "$@"
