#include"headers.h"
#include"declarations.h"
#include"defaults.h"

long ioctl_dev(struct file *filep, unsigned int command, unsigned long arg)
{
    Dev *ldev;

    #ifdef DEBUG
    printk(KERN_INFO "Begin: %s\n", __func__);
    #endif

    ldev = (Dev*)filep->private_data;
    if(!ldev)
    {
        #ifdef DEBUG
            printk(KERN_INFO "Error: Device not found\n");
        #endif
        goto OUT;
    }

    switch(command)
    {
        case DEVRESET:
            #ifdef DEBUG
                printk(KERN_INFO "Command: DEVRESET\n");
            #endif
            // It will reset the following values to default vaues and passed value from driver load 
            // times will be reset
            size_of_reg = ldev->size_of_reg = REGSIZE;
            no_of_reg = ldev->no_of_reg = NOOFREG;
            size_of_data = ldev->size_of_data = DATASIZE;
            size_of_device = ldev->size_of_device = DEVSIZE;
            break;
        default:
            #ifdef DEBUG
                printk(KERN_INFO "Command not Recognized\n");
            #endif
    }

OUT:
    #ifdef DEBUG
        printk(KERN_INFO "End: %s\n", __func__);
    #endif
    return 0;
}