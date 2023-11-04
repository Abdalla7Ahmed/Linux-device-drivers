#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
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

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x15b063c2, "gpio_to_desc" },
	{ 0xd615150e, "gpiod_get_raw_value" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa19b956, "__stack_chk_fail" },
	{ 0x4a5c4038, "gpiod_set_raw_value" },
	{ 0xfe990052, "gpio_free" },
	{ 0xe85f8cb5, "device_destroy" },
	{ 0x6a2dd7c, "class_destroy" },
	{ 0xf7fb9e48, "cdev_del" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x32ab4392, "cdev_init" },
	{ 0x2dcc02c1, "cdev_add" },
	{ 0xeea3c1d8, "__class_create" },
	{ 0xaeb4f263, "device_create" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xa6cb193e, "gpiod_direction_output_raw" },
	{ 0x3a0deed2, "gpiod_direction_input" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x122c3a7e, "_printk" },
	{ 0x453e7dc, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8A30D761E51EDA824AD6B10");
