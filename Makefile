# SPDX-License-Identifier: GPL-2.0-or-later
# Makefile for AudioBox 22 VSL driver
obj-m += audiobox_vsl.o

# Kernel build directory - can be overridden via environment or command line
KDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

# Install the module to the standard location and update module dependencies
install:
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install
	@echo "Updating module dependencies..."
	/sbin/depmod -a $(shell uname -r) || true
	@echo "Module installed successfully."

# Remove the installed module
uninstall:
	rm -f /lib/modules/$(shell uname -r)/extra/audiobox_vsl.ko
	rm -f /lib/modules/$(shell uname -r)/kernel/extra/audiobox_vsl.ko
	/sbin/depmod -a $(shell uname -r) || true
	@echo "Module uninstalled."

.PHONY: all clean install uninstall