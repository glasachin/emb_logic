#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

ssize_t readDevice(struct file *filep, char __user *ubuff, size_t size, loff_t *loff)
{
    Dev *ldev;
    size_t noctr, nocsr, lsize;
    Item *curr;
    unsigned int noq, i, l, not;

    #ifdef DEBUG
    printk(KERN_INFO "Begin: %s\n", __func__);
    printk(KERN_INFO "%s: size:%ld \n", __func__, (long)size);
    #endif
    
    if(size == 0)
    {
        printk(KERN_INFO "%s: Nothing to Write\n", __func__);
        goto RET;
    }

    ldev = (Dev*)filep->private_data;
    if(!ldev)
    {
        printk(KERN_ERR "%s: Error Device not found\n", __func__);
        goto OUT;
    }
    // if not in readmode then go out
    if(size > size_of_device)
    {
        noctr = lsize = size_of_device;
    }
    else    
        noctr = lsize = size;

    nocsr = 0;
    
    if(ldev->first)
    {
        curr = ldev->first;
    }
    else
    {
        printk(KERN_INFO "%s: Nothing to Read\n", __func__);
        goto RET;
    }

    noq = lsize / ldev->size_of_reg;
    if(lsize % ldev->size_of_reg)
        noq++;

    for( i = l = 0; l < noq; l++)
    {
        if(noctr > ldev->size_of_reg)
            noctr = ldev->size_of_reg;
        not = copy_to_user(ubuff+nocsr, curr->data[i], noctr);
        if(not == -1)
        {
            printk(KERN_ERR "%s: Error: copy_to_user() failure\n", __func__);
            goto OUT;
        }
        nocsr = nocsr + size_of_reg - not;
        noctr = lsize - nocsr;
        if( i == ldev->no_of_reg - 1)
        {
            curr = curr->next;
            i = 0;
        }
        else 
            i++;
    }

    printk(KERN_INFO "%s: Read data: %s\n", __func__, ubuff);
    
    RET:
    #ifdef DEBUG
        printk(KERN_INFO "End: %s\n", __func__);
    #endif
    return nocsr;

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