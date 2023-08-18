#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

int openDevice(struct inode *inode, struct file *file)
{
    Dev *ldev;

    #ifdef DEBUG
    printk(KERN_INFO "Begin: %s\n", __func__);
    #endif
    
    
    ldev = container_of(inode->i_cdev, Dev, c_dev);
    if(!ldev)
    {
        printk(KERN_ERR "%s: Error container_of() failure.\n", __func__);
        goto OUT;
    }

    #ifdef DEBUG
        printk(KERN_INFO "End: %s\n", __func__);
    #endif
    return 0;
    OUT:
    #ifdef DEBUB
        printk(KERN_ERR "%s: Error: End\n", __func__);
    #endif
    return -1;
}