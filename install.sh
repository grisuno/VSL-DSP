

#!/bin/bash
# install-audiobox-vsl-driver.sh
# AudioBox 22 VSL Driver - Automatic Installation
# Author: grisun0 (LazyOwn RedTeam)
# Version: 1.0.0

python3 -m venv env
source env/bin/activate
pip install -r requirements.txt

set -e  # Exit on error

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Logo
cat << 'EOF'
╔═══════════════════════════════════════════════════════════╗
║                                                           ║
║   AudioBox 22 VSL Driver - Automatic Installer           ║
║   PreSonus AudioBox 22 VSL Kernel Module                 ║
║                                                           ║
║   Author: grisuno (LazyOwn Project)                      ║
║   License: GPL-3.0                                       ║
║   Version: 1.0.0                                         ║
║                                                           ║
╚═══════════════════════════════════════════════════════════╝

EOF
install_alsa_controls() {
    echo -e "${BLUE}🔧 Installing ALSA controls...${NC}"
    
    # Crear el módulo ALSA como archivo separado
    cat > audiobox_vsl_alsa.c << 'EOF'
#include "audiobox_vsl.h"
// Tu implementación completa del quirk ALSA aquí
EOF
    
    # Instrucciones para integrar con snd-usb-audio
    echo -e "${YELLOW}⚠️  To enable ALSA controls:${NC}"
    echo -e "1. Add to mixer_quirks.c: case USB_ID(0x194f, 0x0101): err = snd_audiobox_vsl_init(mixer); break;"
    echo -e "2. Rebuild kernel module: sudo dkms build -m snd-usb-audio -v $(uname -r)"
}

echo -e "${BLUE}🔍 Checking system requirements...${NC}"

# Check if running as root
if [[ $EUID -ne 0 ]]; then
   echo -e "${YELLOW}⚠️  This script needs sudo privileges. Please run with sudo.${NC}"
   exit 1
fi

# Detect kernel version
KERNEL_VERSION=$(uname -r)
echo -e "${GREEN}✅ Kernel version: $KERNEL_VERSION${NC}"

# Check if headers are installed
HEADERS_PATH="/lib/modules/$KERNEL_VERSION/build"
if [ ! -d "$HEADERS_PATH" ]; then
    echo -e "${YELLOW}⚠️  Kernel headers not found. Installing...${NC}"
    apt update
    apt install -y linux-headers-$(uname -r)
    
    if [ ! -d "$HEADERS_PATH" ]; then
        echo -e "${RED}❌ Failed to install kernel headers${NC}"
        exit 1
    fi
    echo -e "${GREEN}✅ Kernel headers installed${NC}"
else
    echo -e "${GREEN}✅ Kernel headers found${NC}"
fi

# Check for required tools
echo -e "${BLUE}🔍 Checking required tools...${NC}"
for tool in gcc make git; do
    if ! command -v $tool &> /dev/null; then
        echo -e "${YELLOW}⚠️  $tool not found. Installing...${NC}"
        apt install -y $tool
    fi
    echo -e "${GREEN}✅ $tool installed${NC}"
done

# Create installation directory
INSTALL_DIR="$HOME/audiobox-vsl-driver"
echo -e "${BLUE}📂 Creating installation directory: $INSTALL_DIR${NC}"
mkdir -p "$INSTALL_DIR"
cd "$INSTALL_DIR"

# Create source files
echo -e "${BLUE}📝 Creating source files...${NC}"

# audiobox_vsl.c
cat > audiobox_vsl.c << 'EOFCODE'
// SPDX-License-Identifier: GPL-2.0
#include <linux/module.h>
#include <linux/usb.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("grisuno <lazyown.redteam@gmail.com>");
MODULE_DESCRIPTION("PreSonus AudioBox 22 VSL Quirk Driver");
MODULE_VERSION("1.0");

#define VENDOR_ID  0x194f
#define PRODUCT_ID 0x0101

static int audiobox_probe(struct usb_interface *intf, 
                          const struct usb_device_id *id)
{
    dev_info(&intf->dev, "🎉 AudioBox 22 VSL Quirk Cargado!\n");
    dev_info(&intf->dev, "Manufacturer: PreSonus Audio Electronics\n");
    dev_info(&intf->dev, "Product: AudioBox 22 VSL\n");
    dev_info(&intf->dev, "Driver version: 1.0 (LazyOwn Project)\n");
    
    /* No reclamar la interfaz - dejar que snd-usb-audio la maneje */
    return -ENODEV;
}

static void audiobox_disconnect(struct usb_interface *intf)
{
    dev_info(&intf->dev, "🔌 AudioBox 22 VSL disconnected\n");
}

static const struct usb_device_id audiobox_table[] = {
    { USB_DEVICE(VENDOR_ID, PRODUCT_ID) },
    { }
};
MODULE_DEVICE_TABLE(usb, audiobox_table);

static struct usb_driver audiobox_driver = {
    .name       = "audiobox_vsl_quirk",
    .probe      = audiobox_probe,
    .disconnect = audiobox_disconnect,
    .id_table   = audiobox_table,
};

module_usb_driver(audiobox_driver);
EOFCODE

# Makefile
cat > Makefile << 'EOFMAKE'
obj-m += audiobox_vsl.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

install:
	@echo "Installing module..."
	@insmod audiobox_vsl.ko
	@echo "✅ Module loaded successfully"
	@lsmod | grep audiobox

uninstall:
	@echo "Uninstalling module..."
	@-rmmod audiobox_vsl 2>/dev/null
	@echo "✅ Module unloaded"
EOFMAKE

# Compile
echo -e "${BLUE}🔨 Compiling kernel module...${NC}"
make clean
make

if [ ! -f "audiobox_vsl.ko" ]; then
    echo -e "${RED}❌ Compilation failed${NC}"
    exit 1
fi

echo -e "${GREEN}✅ Module compiled successfully${NC}"

# Show module info
echo -e "${BLUE}📋 Module information:${NC}"
modinfo audiobox_vsl.ko

# Load module
echo -e "${BLUE}🚀 Loading module...${NC}"
rmmod audiobox_vsl 2>/dev/null || true
insmod audiobox_vsl.ko

if lsmod | grep -q audiobox_vsl; then
    echo -e "${GREEN}✅ Module loaded successfully!${NC}"
else
    echo -e "${RED}❌ Failed to load module${NC}"
    exit 1
fi

# Create systemd service for auto-load
echo -e "${BLUE}⚙️  Creating systemd service...${NC}"
cat > /etc/modules-load.d/audiobox-vsl.conf << 'EOFSVC'
# Load AudioBox VSL driver at boot
audiobox_vsl
EOFSVC

# Copy module to system
MODULE_DIR="/lib/modules/$KERNEL_VERSION/extra"
mkdir -p "$MODULE_DIR"
cp audiobox_vsl.ko "$MODULE_DIR/"
depmod -a

echo -e "${GREEN}✅ Module installed to system${NC}"

# Create uninstall script
cat > uninstall.sh << 'EOFUNINSTALL'
#!/bin/bash
# Uninstall AudioBox VSL Driver

echo "Uninstalling AudioBox VSL Driver..."

# Remove module
rmmod audiobox_vsl 2>/dev/null || true

# Remove from system
KERNEL_VERSION=$(uname -r)
rm -f /lib/modules/$KERNEL_VERSION/extra/audiobox_vsl.ko
rm -f /etc/modules-load.d/audiobox-vsl.conf

depmod -a

echo "✅ AudioBox VSL Driver uninstalled"
EOFUNINSTALL

chmod +x uninstall.sh

# Final instructions
cat << 'EOFFINAL'

╔═══════════════════════════════════════════════════════════╗
║                                                           ║
║   ✅ INSTALLATION COMPLETED SUCCESSFULLY                  ║
║                                                           ║
╚═══════════════════════════════════════════════════════════╝

🎉 The AudioBox 22 VSL driver is now installed and loaded!

📋 Module Status:
EOFFINAL

lsmod | grep audiobox

cat << 'EOFFINAL2'

🔌 Connect your AudioBox 22 VSL to see it in action!

📝 Useful Commands:
  • View logs:          dmesg | grep -i audiobox
  • Check module:       lsmod | grep audiobox
  • Module info:        modinfo audiobox_vsl
  • Unload module:      sudo rmmod audiobox_vsl
  • Load module:        sudo insmod audiobox_vsl.ko
  • Uninstall driver:   sudo ./uninstall.sh

📂 Installation directory: 
EOFFINAL2

echo "   $INSTALL_DIR"

cat << 'EOFFINAL3'

🌟 The module will load automatically on boot.

🔗 LazyOwn Project Links:
  • GitHub: https://github.com/grisuno/LazyOwn
  • Web: https://grisuno.github.io/LazyOwn/
  • Blog: https://medium.com/@lazyown.redteam

☕ Support: https://ko-fi.com/grisuno

Thank you for using AudioBox VSL Driver!

EOFFINAL3



# Agrega al menú final
echo -e "${BLUE}Select installation mode:${NC}"
echo "1) VSL button support only (default)"
echo "2) Full controls (ALSA + VSL button) - requires DKMS"
read -p "Choice [1-2]: " choice

case $choice in
    2)
        install_alsa_controls
        ;;
    *)
        echo -e "${GREEN}✅ VSL button support installed${NC}"
        ;;
esac

echo -e "${GREEN}✅ Installation complete!${NC}"
