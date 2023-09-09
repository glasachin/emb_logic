#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

Item* creatScull(size_t lsize)
{
    Dev *ldev;
    //size_t lsize;
    Item *first, *itemPtr;
    int size_of_item, no_of_items, noq;

    #ifdef DEBUG
        printk(KERN_INFO "Begin: %s\n", __func__);
    #endif

        
    size_of_item = no_of_reg * size_of_reg;
    no_of_items = lsize / size_of_item;

    if( lsize % size_of_item)
    {
        no_of_items++;
    }

    // allocate data for no-of-items (link list)
    for(i = 0; i < no_of_items; i++)
    {
        if(i == 0)
            itemPtr = first = (Item*)kmalloc(sizeof(Item), GFP_KERNEL);
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

    itemPtr = first;

    for(i = 0; i < no_of_items; i++)
    {
        itemPtr->data = (void**)kmalloc(sizeof(char*)*no_of_reg, GFP_KERNEL)
        if(!itemPtr->data)
        {
            #ifdef DEBUG
                printk(KERN_ERR "%s: Error, kmalloc() failure\n", __func__);
            #endif
            goto OUT;
        }
        memset(itemPtr->data,'\0', sizeof(char*)*no_of_reg);
        itemPtr = itemPtr->next;
    }

    // number of quantums
    noq = lsize / size_of_reg;
    if(lsize % size_of_reg)
        noq++;

    itemPtr = first;
    
    for(l = i = 0; l < noq; l++)
    {
        itemPtr->data[i] = kmalloc(size_of_reg, GFP_KERNEL);
        if(!itemPtr->data[i])
        {
            #ifdef DEBUG
                printk(KERN_ERR "%s: Error, kmalloc() failure\n", __func__);
            #endif
            goto OUT;
        }
        if(i == no_of_reg -1)
        {
            itemPtr = itemPtr->next;
            i = 0;
        }
        else
            i++;
    }

    RET:
    #ifdef DEBUG
        printk(KERN_INFO "End: %s\n", __func__);
    #endif
    return first;

    OUT:
    #ifdef DEBUG
        printk(KERN_ERR "%s: Error: End \n", __func__);
    #endif

    return 0;
}