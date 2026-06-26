#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};


MODULE_INFO(depends, "usbcore");

MODULE_ALIAS("usb:v194Fp0101d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "5C6D6F396B17212EA8CFB73");
