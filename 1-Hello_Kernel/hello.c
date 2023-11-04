#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

/* Meta information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abdallah Ahmed Mohammed ");
MODULE_DESCRIPTION("simple hello world ");

/**
=============== module_init(): ============= 
The module_init() function is used to specify the entry point or initialization 
function for a kernel module. When a kernel module is loaded, 
the kernel calls the function specified by module_init() to initialize the module. 
This function is typically defined in the module's source code and serves as the starting point for the module's execution.
*/


/*
module_exit():
The module_exit() function is used to specify the exit or cleanup function 
for a kernel module. When a kernel module is unloaded,
either manually or during system shutdown, the kernel calls the function 
specified by module_exit() to perform any necessary cleanup tasks.
*/



// lsmod   --> list the all modules 
// insmod , modprobe  --> insert module
// rmmod   --> delete module
// modinfo <moduel>    --> information about specific module


static int __init Module_init(void)
{
    printk("hello , Kernel\n");
    return 0;
}

static void __exit Module_module(void)
{
    printk("Goodbye , Kernel\n");
}
module_init(Module_init);

module_exit(Module_module);










