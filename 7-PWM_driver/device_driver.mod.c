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
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xbbf6b59a, "pwm_free" },
	{ 0xe85f8cb5, "device_destroy" },
	{ 0x6a2dd7c, "class_destroy" },
	{ 0xf7fb9e48, "cdev_del" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x741c01b8, "pwm_apply_state" },
	{ 0xa19b956, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x2505bf18, "kstrtol_from_user" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x32ab4392, "cdev_init" },
	{ 0x2dcc02c1, "cdev_add" },
	{ 0xeea3c1d8, "__class_create" },
	{ 0xaeb4f263, "device_create" },
	{ 0x5c959b41, "pwm_request" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x122c3a7e, "_printk" },
	{ 0x453e7dc, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B9B51B8E16D3538AC12C062");
