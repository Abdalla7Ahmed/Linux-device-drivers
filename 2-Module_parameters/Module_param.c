#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

/* Meta information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abdallah Ahmed Mohammed ");
MODULE_DESCRIPTION("test parameters");


// lsmod   --> list the all modules 
// insmod , modprobe  --> insert module
// rmmod   --> delete module
// modinfo <moduel>    --> information about specific module

//#include <linux/stat.h>
// user     + group     + other 
// rwx      + rwx       + rwx 
// 111(7)   + 111(7)    + 111(7)    --> 777
// rw-      + rw-       + r--     
// 110(6)   + 110(6)    + 100(4)    --> 664



/**
 * module_param - typesafe helper for a module/cmdline parameter
 * @name: the variable to alter, and exposed parameter name.
 * @type: the type of the parameter
 * @perm: visibility in sysfs.
 *
 * @name becomes the module parameter, or (prefixed by KBUILD_MODNAME and a
 * ".") the kernel commandline parameter.  Note that - is changed to _, so
 * the user can use "foo-bar=1" even for variable "foo_bar".
 *
 * @perm is 0 if the variable is not to appear in sysfs, or 0444
 * for world-readable, 0644 for root-writable, etc.  Note that if it
 * is writable, you may need to use kernel_param_lock() around
 * accesses (esp. charp, which can be kfreed when it changes).
 *
 * The @type is simply pasted to refer to a param_ops_##type and a
 * param_check_##type: for convenience many standard types are provided but
 * you can create your own by defining those variables.
 *
 * Standard types are:
 *	byte, hexint, short, ushort, int, uint, long, ulong
 *	charp: a character pointer
 *	bool: a bool, values 0/1, y/n, Y/N.
 *	invbool: the above, only sense-reversed (N = true).
 */


char *name=NULL;
module_param(name,charp,0664);


static int __init Module_init(void)
{
    printk("hello , %s \n",name);
    return 0;
}

static void __exit Module_module(void)
{
    printk("Goodbye , %s \n",name);
}

module_init(Module_init);
module_exit(Module_module);










