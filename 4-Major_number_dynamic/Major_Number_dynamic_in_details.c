#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/cdev.h>


/* Meta information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abdallah Ahmed Mohammed ");
MODULE_DESCRIPTION("test parameters");


dev_t device_number=0;
struct cdev st_character_device;
struct class *device_class;
struct device *device_file;
static int Driver_Open (struct inode *device_file, struct file *instance)
{
    printk("%s device_file open was called \n",__FUNCTION__);
    return 0;
}
static int Driver_release (struct inode *device_file, struct file *instance)
{
    printk("%s device_file release was called \n",__FUNCTION__);
    return 0;
}
static ssize_t Driver_Read (struct file *instance, char __user * dummy1, size_t dummy2, loff_t *dummy3)
{
    printk("%s device_file read was called \n",__FUNCTION__);
    return 0;
}
static ssize_t Driver_Write (struct file *instance,const char __user * dummy1, size_t dummy2, loff_t *dummy3)
{

    printk("%s device_file write was called \n",__FUNCTION__);
    return 0;

}
const struct file_operations fops =
{
    .owner = THIS_MODULE,
    .open = Driver_Open,
    .release = Driver_release,
    .read = Driver_Read,
    .write = Driver_Write
};








static int __init Module_init(void)
{
    int retval;
    
    
    printk("hello Kernel this is the init module function \n");

    /**
 * alloc_chrdev_region() - register a range of char device numbers
 * @dev: output parameter for first assigned number
 * @baseminor: first of the requested range of minor numbers
 * @count: the number of minor numbers required
 * @name: the name of the associated device or driver
 *
 * Allocates a range of char device numbers.  The major number will be
 * chosen dynamically, and returned (along with the first minor number)
 * in @dev.  Returns zero or a negative error code.
 */
    // 1 - allocate the device number
    //int alloc_chrdev_region(dev_t *dev, unsigned baseminor, unsigned count,const char *name)
    retval = alloc_chrdev_region(&device_number,0,1,"test_device_name");
    if (retval==0 )
    {
        /*
        #define MINORBITS	20
        #define MINORMASK	((1U << MINORBITS) - 1)

        #define MAJOR(dev)	((unsigned int) ((dev) >> MINORBITS))
        #define MINOR(dev)	((unsigned int) ((dev) & MINORMASK))
        */
        printk("%s retval = %d , registered device major number = %d and minor number = %d \n",__FUNCTION__,retval,MAJOR(device_number),MINOR(device_number));
    }else
    {
        printk("cann't register device major number \n");
        return -1;
    }

    // 2 - define the device as character device

    /**
 * cdev_init() - initialize a cdev structure
 * @cdev: the structure to initialize
 * @fops: the file_operations for this device
 *
 * Initializes @cdev, remembering @fops, making it ready to add to the
 * system with cdev_add().
 */
    //void cdev_init(struct cdev *cdev, const struct file_operations *fops)
    cdev_init(&st_character_device,&fops);
    
/**
 * cdev_add() - add a char device to the system
 * @p: the cdev structure for the device
 * @dev: the first device number for which this device is responsible
 * @count: the number of consecutive minor numbers corresponding to this
 *         device
 *
 * cdev_add() adds the device represented by @p to the system, making it
 * live immediately.  A negative error code is returned on failure.
 */
    //int cdev_add(struct cdev *p, dev_t dev, unsigned count)
    retval = cdev_add(&st_character_device,device_number,1);
    if (retval == 0)
    {

    }else
    {
       printk("Registration of the devie failed \n");
       unregister_chrdev_region(device_number,1);
       return -1; 
    }


    // 3 - generate file (class , device)

    /**
 * class_create - create a struct class structure
 * @name: pointer to a string for the name of this class.
 *
 * This is used to create a struct class pointer that can then be used
 * in calls to device_create().
 *
 * Returns &struct class pointer on success, or ERR_PTR() on error.
 *
 * Note, the pointer created here is to be destroyed when finished by
 * making a call to class_destroy().
 */

    //struct class *class_create(const char *name)
    device_class = class_create(THIS_MODULE,"test_class");
    if(device_class == NULL)
    {
        
       printk("Creating device class failed\n");
       cdev_del(&st_character_device);
       unregister_chrdev_region(device_number,1);
        return -1;
    }

/**
 * device_create - creates a device and registers it with sysfs
 * @class: pointer to the struct class that this device should be registered to
 * @parent: pointer to the parent struct device of this new device, if any
 * @devt: the dev_t for the char device to be added
 * @drvdata: the data to be added to the device for callbacks
 * @fmt: string for the device's name
 *
 * This function can be used by char device classes.  A struct device
 * will be created in sysfs, registered to the specified class.
 *
 * A "dev" file will be created, showing the dev_t for the device, if
 * the dev_t is not 0,0.
 * If a pointer to a parent struct device is passed in, the newly created
 * struct device will be a child of that device in sysfs.
 * The pointer to the struct device will be returned from the call.
 * Any further sysfs files that might be required can be created using this
 * pointer.
 *
 * Returns &struct device pointer on success, or ERR_PTR() on error.
 */
    //struct device *device_create(const struct class *class, struct device *parent,dev_t devt, void *drvdata, const char *fmt, ...)

    device_file = device_create(device_class,NULL,device_number,NULL,"test_device_file");
    if(device_file == NULL)
    {
        printk("Creating device file failed\n");
        class_destroy(device_class);
        cdev_del(&st_character_device);
        unregister_chrdev_region(device_number,1);
        return -1;  
    }
   
    return 0;
}

static void __exit Module_module(void)
{
         /**
        * device_destroy - removes a device that was created with device_create()
        * @class: pointer to the struct class that this device was registered with
        * @devt: the dev_t of the device that was previously registered
         *
        * This call unregisters and cleans up a device that was created with a
        * call to device_create().
        */
        //void device_destroy(const struct class *class, dev_t devt)
        device_destroy(device_class,device_number);
        /**
        * class_destroy - destroys a struct class structure
        * @cls: pointer to the struct class that is to be destroyed
        *
        * Note, the pointer to be destroyed must have been created with a call
        * to class_create().
        */
        //void class_destroy(const struct class *cls)
        class_destroy(device_class);
        /**
        * cdev_del() - remove a cdev from the system
        * @p: the cdev structure to be removed
        *
        * cdev_del() removes @p from the system, possibly freeing the structure
        * itself.
        *
        * NOTE: This guarantees that cdev device will no longer be able to be
        *   opened, however any cdevs already open will remain and their fops will
        * still be callable even after cdev_del returns.
        */
        //void cdev_del(struct cdev *p)
        cdev_del(&st_character_device);
         /**
        * unregister_chrdev_region() - unregister a range of device numbers
        * @from: the first in the range of numbers to unregister
        * @count: the number of device numbers to unregister
        *
         * This function will unregister a range of @count device numbers,
        * starting with @from.  The caller should normally be the one who
        * allocated those numbers in the first place...
        */
        //void unregister_chrdev_region(dev_t from, unsigned count)
        unregister_chrdev_region(device_number,1);
        printk("Goodbye Kernel this is the exit module function \n");
}

module_init(Module_init);
module_exit(Module_module);









