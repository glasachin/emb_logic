#include"headers.h"
#include"declarations.h"
#include"defaults.h"

long ioctl_dev(struct file *filep, unsigned int command, unsigned long arg)
{
    int ret;
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
        case GETREGSIZE:
            #ifdef DEBUG
                printk(KERN_INFO "Command: GETREGSIZE\n");
                printk(KERN_INFO "Register Size: %d\n", ldev->size_of_reg);
            #endif
            ret = put_user(ldev->size_of_reg, (int __user*)arg);
            if(ret < 0)
            {
                #ifdef DEBUG
                    printk(KERN_ERR "Error: put_user() failure.\n");
                #endif
                goto OUT;
            }
            break;
        case GETNOOFREG:
            #ifdef DEBUG
                printk(KERN_INFO "Command: GETNOOFREG\n");
                printk(KERN_INFO "Number of Registers are: %d\n", ldev->no_of_reg);
            #endif
            ret = put_user(ldev->no_of_reg, (int __user*)arg);
            if(ret < 0)
            {
                #ifdef DEBUG
                    printk(KERN_ERR "Error: put_user() failure.\n");
                #endif
                goto OUT;
            }
            break;
        case GETDEVICESIZE:
            #ifdef DEBUG
                printk(KERN_INFO "Command: GETNOOFREG\n");
                printk(KERN_INFO "Number of Registers are: %d\n", ldev->size_of_device);
            #endif
            ret = put_user(ldev->size_of_device, (int __user*)arg);
            if(ret < 0)
            {
                #ifdef DEBUG
                    printk(KERN_ERR "Error: put_user() failure.\n");
                #endif
                goto OUT;
            }
            break;
        case GETDATASIZE:
            #ifdef DEBUG
                printk(KERN_INFO "Command: GETNOOFREG\n");
                printk(KERN_INFO "Number of Registers are: %d\n", ldev->size_of_data);
            #endif
            ret = put_user(ldev->size_of_data, (int __user*)arg);
            if(ret < 0)
            {
                #ifdef DEBUG
                    printk(KERN_ERR "Error: put_user() failure.\n");
                #endif
                goto OUT;
            }
            break;
        case SETREGSIZE:
            #ifdef DEBUG
                printk(KERN_INFO "Command: SETREGSIZE\n");
                // printk(KERN_INFO "Register Size: %d\n", ldev->size_of_reg);
            #endif
            ret = get_user(size_of_reg, (int __user*)arg);
            if(ret < 0)
            {
                #ifdef DEBUG
                    printk(KERN_ERR "Error: put_user() failure.\n");
                #endif
                goto OUT;
            }
            ldev->size_of_reg = size_of_reg;
            break;
        case SETNOOFREG:
            #ifdef DEBUG
                printk(KERN_INFO "Command: SETNOOFREG\n");
                // printk(KERN_INFO "Number of Registers are: %d\n", ldev->no_of_reg);
            #endif
            ret = get_user(no_of_reg, (int __user*)arg);
            if(ret < 0)
            {
                #ifdef DEBUG
                    printk(KERN_ERR "Error: put_user() failure.\n");
                #endif
                goto OUT;
            }
            ldev->no_of_reg = no_of_reg;
            break;
        case SETDEVICESIZE:
            #ifdef DEBUG
                printk(KERN_INFO "Command: SETNOOFREG\n");
                // printk(KERN_INFO "Number of Registers are: %d\n", ldev->size_of_device);
            #endif
            ret = get_user(size_of_device, (int __user*)arg);
            if(ret < 0)
            {
                #ifdef DEBUG
                    printk(KERN_ERR "Error: put_user() failure.\n");
                #endif
                goto OUT;
            }
            ldev->size_of_device = size_of_device;
            break;
        // case SETDATASIZE: // no SETDATASIZE
        //     #ifdef DEBUG
        //         printk(KERN_INFO "Command: SETDATASIZE\n");
        //         // printk(KERN_INFO "Number of Registers are: %d\n", ldev->size_of_data);
        //     #endif
        //     ret = get_user(size_of_data, (int __user*)arg);
        //     if(ret < 0)
        //     {
        //         #ifdef DEBUG
        //             printk(KERN_ERR "Error: put_user() failure.\n");
        //         #endif
        //         goto OUT;
        //     }
        //     ldev->size_of_data = size_of_data;
        //     break;
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
            ret = trimDevice(ldev);
            if(ret == -1)
            {
                #ifndef DEBUG
                    printk(KERN_ERR "Error: trim_dev() failure\n");
                #endif
            }
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