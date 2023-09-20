#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

ssize_t writeDevice(struct file *filep, const char __user *ubuff, size_t size, loff_t *loff)
{
    int not, noq, l, i;
    int noctw, nocsw; // noctw: no. of character to write, nocsw: no. of character successfully written
    Dev *ldev;
    size_t lsize;
    Item *curr;
    // int size_of_item, no_of_items;

    #ifdef DEBUG
    printk(KERN_INFO "Begin: %s\n", __func__);
    #endif

    if(size == 0)
    {
        printk(KERN_INFO "%s: Nothing to write\n", __func__);
        goto RET;
    }
    
    ldev = (Dev*)filep->private_data;
    if(!ldev)
    {
        printk(KERN_ERR "%s: Error Device not found\n", __func__);
        goto OUT;
    }

    if(size > ldev->size_of_device)
    {
        noctw = lsize = ldev->size_of_device;
    }
    else    
        noctw = lsize = size;
    
    curr = ldev->first = creatScull(lsize); // It creates the structure and returns the address of first element

    // number of quantums
    noq = lsize / ldev->size_of_reg;
    if(lsize % ldev->size_of_reg)
        noq++;

    for(nocsw = i = l = 0; l < noq; l++)
    {
        if(noctw > ldev->size_of_reg)
            noctw = ldev->size_of_reg;
        not = copy_from_user(curr->data[i], ubuff + nocsw, noctw);
        printk(KERN_ERR "%s: copy_from_user() output: %d\n", __func__, not);
        if(not == -1)
        {
            printk(KERN_ERR "%s: copy_from_user() failure\n", __func__);
            goto OUT;
        }
        nocsw = nocsw + size_of_reg - not;
        noctw = lsize - nocsw;
        if(i == ldev->no_of_reg-1)
        {
            curr = curr->next;
            i = 0;
        }
        else
            i++;
    }

    ldev->size_of_data = nocsw;

    RET:
    #ifdef DEBUG
        printk(KERN_INFO "End: %s\n", __func__);
    #endif
    return nocsw;

    OUT:
    #ifdef DEBUG
        printk(KERN_ERR "%s: Error: End \n", __func__);
    #endif

    return -1;
}