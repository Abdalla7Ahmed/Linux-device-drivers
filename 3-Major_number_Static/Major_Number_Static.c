#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>


/* Meta information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abdallah Ahmed Mohammed ");
MODULE_DESCRIPTION("test parameters");


int number = 0;
int major_number = 0;

//int (*open) (struct inode *, struct file *);
static int Driver_Open (struct inode *device_file, struct file *instance)
{
    printk("%s device_file open was called \n",__FUNCTION__);
    return 0;
}



//int (*release) (struct inode *, struct file *);
static int Driver_release (struct inode *device_file, struct file *instance)
{
    printk("%s device_file release was called \n",__FUNCTION__);
    return 0;
}


const struct file_operations fops =
{
    .owner = THIS_MODULE,
    .open = Driver_Open,
    .release = Driver_release
};




module_param(number,int,0664);


static int __init Module_init(void)
{
    int retval;
    major_number = number;
    printk("hello Kernel this is the init module function \n");
    
    
    //static inline int register_chrdev(unsigned int major, const char *name, const struct file_operations *fops)
    retval = register_chrdev(major_number,"test_major",&fops);
  
    if (retval==0 )
    {
        printk("%s retval = %d , registered device major number = %d and minor number = %d \n",__FUNCTION__,retval,major_number,0);
    }else
    {
        printk("cann't register device major number \n");
        return -1;
    }
   
    return 0;
}

// to creat device file
// sudo mknod /dev/filename c majodr_number minor_number       c refered to the type of device (character , block , ... ) 
static void __exit Module_module(void)
{
    //static inline void unregister_chrdev(unsigned int major, const char *name)
    unregister_chrdev(major_number,"test_major");
    printk("Goodbye Kernel this is the exit module function \n");
}

module_init(Module_init);
module_exit(Module_module);









