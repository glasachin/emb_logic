#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

ssize_t readDevice(struct file *filep, char __user *ubuff, size_t size, loff_t *loff)
{
    Dev *ldev;
    #ifdef DEBUG
    printk(KERN_INFO "Begin: %s\n", __func__);
    #endif
    
    ldev = (Dev*)filep->private_data;
    if(!ldev)
    {
        printk(KERN_ERR "%s: Error Device not found\n", __func__);
        goto OUT;
    }
    // if not in readmode then go out
    if((filep->f_flags & O_ACCMODE) != O_RDONLY)
    {
        printk(KERN_INFO "%s: Device is not opened for Reading\n", __func__);
        goto OUT;
    }

    

    OUT:
    #ifdef DEBUG
        printk(KERN_ERR "%s: Error: End \n", __func__);
    #endif
    return -1;

    // #ifdef DEBUG
    // printk(KERN_INFO "End: %s\n", __func__);
    // #endif
    // return 0;
}