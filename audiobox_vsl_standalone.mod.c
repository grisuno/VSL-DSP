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



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x3a4c8fde, "_dev_info" },
	{ 0x20977b5c, "usb_deregister" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x3b83a326, "usb_register_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa1a94982, "module_layout" },
};

MODULE_INFO(depends, "usbcore");

MODULE_ALIAS("usb:v194Fp0101d*dc*dsc*dp*ic*isc*ip*in*");
