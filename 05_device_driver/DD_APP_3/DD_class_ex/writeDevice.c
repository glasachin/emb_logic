#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

ssize_t writeDevice(struct file *filep, const char __user *ubuff, size_t size, loff_t *loff)
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


    #ifdef DEBUG
        printk(KERN_INFO "End: %s\n", __func__);
    #endif
    return 0;

    OUT:
    #ifdef DEBUG
        printk(KERN_ERR "%s: Error: End \n", __func__);
    #endif

    return -1;
}