# SPDX-License-Identifier: GPL-2.0-or-later
# Single source of truth for all build, test, install, and clean
# commands. install.sh and configure delegate here and add no logic
# of their own; any build flag, path, or tool invocation belongs in
# this file.
#
# The kernel module is built by delegating to the in-tree kbuild
# system. Targets for the userspace CMocka test suite are defined
# alongside and do not interfere with the kernel build.
#
# Note: .DEFAULT_GOAL is intentionally omitted. Setting it triggers
# a kbuild sub-make recursion bug in 6.x kernels that requires
# write access to the kernel source directory. Leaving the default
# goal implicit (first target wins) keeps the build portable.
#
VERSION ?= 1.0
MAINTAINER ?= Unknown
DEB_ARCH ?= $(shell dpkg --print-architecture)
DEB_NAME ?= audiobox-vsl-dkms
DEB_VERSION ?= $(VERSION)
DEB_DESCRIPTION ?= Open source Linux kernel module for the PreSonus AudioBox VSL family
DEB_SECTION ?= kernel
DEB_PRIORITY ?= optional
DEB_MAINTAINER ?= $(MAINTAINER)
DEB_HOMEPAGE ?= https://github.com/grisuno/VSL-DSP

obj-m += audiobox_vsl.o

KDIR     ?= /lib/modules/$(shell uname -r)/build
PWD      := $(shell pwd)
KVER     := $(shell uname -r)
DEPMOD   ?= depmod
MODPROBE ?= modprobe
RMMOD    ?= rmmod
INSTALL  ?= /lib/modules/$(KVER)/extra

CC       ?= gcc
CSTD     ?= -std=c11
CFLAGS_T ?= $(CSTD) -O2 -g -Wall -Wextra -Werror -Wshadow -Wpedantic \
            -Wstrict-prototypes -Wmissing-prototypes -Wconversion \
            -Wsign-conversion -Wold-style-definition \
            -fstack-protector-strong -D_FORTIFY_SOURCE=2
CFLAGS_A ?= $(CFLAGS_T) -fsanitize=address,undefined -fno-omit-frame-pointer -O1
LDLIBS_T ?= -lcmocka
LDLIBS_A ?= -lcmocka -lasan -lubsan

# Userspace DSP library and CLI flags
CFLAGS_H ?= $(CSTD) -O2 -g -Wall -Wextra -Werror -Wshadow -Wpedantic \
            -Wstrict-prototypes -Wmissing-prototypes -Wconversion \
            -Wsign-conversion -Wold-style-definition \
            -fstack-protector-strong -D_FORTIFY_SOURCE=2 \
            -Isrc
LDLIBS_H ?= -lusb-1.0 -lm

TEST_BIN := tests/audiobox_vsl_test
TEST_DSP_BIN := tests/test_vsl_dsp_logic
VSL_CLI_BIN := src/vsl_cli

.PHONY: all test asan clean install uninstall modprobe rmmod info help deb \
        vsl-cli test-dsp

all: modules test vsl-cli test-dsp

modules:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

$(TEST_BIN): tests/test_audiobox_vsl.c audiobox_vsl.h | tests
	$(CC) $(CFLAGS_T) -I. $< -o $@ $(LDLIBS_T)

tests:
	@mkdir -p tests

test: $(TEST_BIN)
	$(TEST_BIN)

asan: tests/test_audiobox_vsl.c audiobox_vsl.h | tests
	$(CC) $(CFLAGS_A) -I. $< -o $(TEST_BIN) $(LDLIBS_A)
	$(TEST_BIN)

$(TEST_DSP_BIN): tests/test_vsl_dsp_logic.c src/vsl_dsp_logic.c src/vsl_dsp_logic.h
	$(CC) $(CFLAGS_T) -Isrc tests/test_vsl_dsp_logic.c src/vsl_dsp_logic.c -o $@ $(LDLIBS_T) -lm

test-dsp: $(TEST_DSP_BIN)
	$(TEST_DSP_BIN)

$(VSL_CLI_BIN): src/vsl_cli.c src/vsl_dsp_logic.c src/vsl_dsp_logic.h \
                src/vsl_dsp_transport.c src/vsl_dsp_transport.h
	$(CC) $(CFLAGS_H) src/vsl_cli.c src/vsl_dsp_logic.c src/vsl_dsp_transport.c \
	-o $(VSL_CLI_BIN) $(LDLIBS_H)

vsl-cli: $(VSL_CLI_BIN)

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -f $(TEST_BIN) $(TEST_DSP_BIN) $(VSL_CLI_BIN)

install: modules
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install
	$(DEPMOD) -a $(KVER) || true

uninstall:
	rm -f $(INSTALL)/audiobox_vsl.ko
	$(DEPMOD) -a $(KVER) || true

modprobe:
	$(MODPROBE) audiobox_vsl

rmmod:
	$(RMMOD) audiobox_vsl || true

info:
	@echo "kernel  : $(KVER)"
	@echo "kdir    : $(KDIR)"
	@echo "cc      : $(CC)"
	@echo "install : $(INSTALL)"

deb: modules
	@mkdir -p debian/lib/modules/$(KVER)/extra
	@mkdir -p debian/DEBIAN
	@cp audiobox_vsl.ko debian/lib/modules/$(KVER)/extra/
	@echo "Package: $(DEB_NAME)" > debian/DEBIAN/control
	@echo "Version: $(DEB_VERSION)" >> debian/DEBIAN/control
	@echo "Section: $(DEB_SECTION)" >> debian/DEBIAN/control
	@echo "Priority: $(DEB_PRIORITY)" >> debian/DEBIAN/control
	@echo "Architecture: $(DEB_ARCH)" >> debian/DEBIAN/control
	@echo "Maintainer: $(DEB_MAINTAINER)" >> debian/DEBIAN/control
	@echo "Homepage: $(DEB_HOMEPAGE)" >> debian/DEBIAN/control
	@echo "Description: $(DEB_DESCRIPTION)" >> debian/DEBIAN/control
	@fakeroot dpkg-deb --build debian $(DEB_NAME)_$(DEB_VERSION)_$(DEB_ARCH).deb
	@rm -rf debian

help:
	@echo "Targets:"
	@echo "  all         build kernel module, run tests, build vsl-cli (default)"
	@echo "  modules     build the kernel module only"
	@echo "  test        build and run the CMocka test suite (detector)"
	@echo "  test-dsp    build and run the DSP logic unit tests"
	@echo "  vsl-cli     build the VSL DSP control CLI tool"
	@echo "  asan        build and run the test suite under ASan+UBSan"
	@echo "  clean       remove build artefacts"
	@echo "  install     copy the kernel module to $(INSTALL) and run depmod"
	@echo "  uninstall   remove the kernel module from $(INSTALL)"
	@echo "  modprobe    load the kernel module"
	@echo "  rmmod       unload the kernel module"
	@echo "  info        print resolved build variables"
	@echo "  deb         build Debian package (.deb) for the kernel module"
	@echo "  help        list every available target"