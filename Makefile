obj-m += audiobox_vsl_standalone.o
audiobox_vsl_standalone-objs := audiobox_vsl.o

KDIR := /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
