#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

int openSerialDevice(struct inode *inode, struct file *filep)
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

    filep->private_data = ldev;
    if((filep->f_flags & O_ACCMODE) == O_WRONLY)
    {
        filep->f_pos = 0;
        printk(KERN_INFO "%s: Device opened for Writing\n", __func__);
    }
    else if((filep->f_flags & O_ACCMODE) == O_RDONLY)
    {
        printk(KERN_INFO "%s: Device opened for Reading\n", __func__);
    }
    //else if((filep->f_flags & O_ACCMODE) == O_APPEND)
      //  printk(KERN_INFO "%s: Device Opened for Appending\n", __func__);
    else
    {
        printk(KERN_INFO "%s: Invalid Device Open Mode \n", __func__);
        goto OUT;
    }
    
    #ifdef DEBUG
        printk(KERN_INFO "End: %s\n", __func__);
    #endif
    return 0;
    OUT:
    #ifdef DEBUG
        printk(KERN_ERR "%s: Error: End\n", __func__);
    #endif
    return -1;
}