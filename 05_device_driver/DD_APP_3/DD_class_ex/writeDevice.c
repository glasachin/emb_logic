#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

ssize_t writeDevice(struct file *filep, const char __user *ubuff, size_t size, loff_t *loff)
{
    Dev *ldev;
    size_t lsize;
    Item *itemPtr;
    int size_of_item, no_of_items;

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
        lsize = ldev->size_of_device;
    }

    size_of_item = ldev->no_of_reg * ldev->size_of_reg;
    no_of_items = lsize / size_of_item;

    if( lsize % size_of_item)
    {
        no_of_items++;
    }

    // allocate data for no-of-items (link list)
    for(i = 0; i < no_of_items; i++)
    {
        if(i == 0)
            itemPtr = ldev->itemPtr = (Item*)kmalloc(sizeof(Item), GFP_KERNEL);
        else
        {
            itemPtr->next = (Item*)kmalloc(sizeof(Item), GFP_KERNEL);
            itemPtr = itemPtr->next;
        }

        if(!itemPtr)
        {
            #ifdef DEBUG
                printk(KERN_ERR "%s: Error, kmalloc() failure\n", __func__);
            #endif
            goto OUT;
        }
        memset(itemPtr, '\0', sizeof(Item)); //for last item
    }

    itemPtr = ldev->first;
    itemPtr->data = (void**)kmalloc(sizeof(char*)*ldev->no_of_reg, GFP_KERNEL)
    if(!itemPtr->data)
    {
        #ifdef DEBUG
            printk(KERN_ERR "%s: Error, kmalloc() failure\n", __func__);
        #endif
        goto OUT;
    }
    memset(itemPtr->data,'\0', sizeof(char*)*ldev->no_of_reg);

    // number of quantums
    noq = lsize / ldev->size_of_reg;
    if(lsize % ldev->size_of_reg)
        noq++;
    


    RET:
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