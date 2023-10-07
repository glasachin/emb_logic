#include"headers.h"
#include"defaults.h"
#include"declarations.h"

int trimDevice(Dev *fdev)
{
    int i;
    Item *last, *slast;
    #ifdef DEBUG
        printk(KERN_INFO "%s: Begin.\n", __func__);
    #endif

    if(!fdev->first)
    {
        printk(KERN_INFO "%s: Nothing ot Trim\n", __func__);
        goto RET;
    }

    while(fdev->first)
    {
        slast = last = fdev->first;
        while(last->next)
        {
            slast = last;
            last = last->next;
        }

        if(last->data)
        {
            for( i = 0; i < fdev->no_of_reg; i++)
            {
                if(last->data[i])
                {
                    kfree(last->data[i]);
                    last->data[i] = NULL;
                }
            }
            kfree(last->data);
            last->data = NULL;
        }
        kfree(last);
        if(fdev->first == last)
            fdev->first = NULL;
        slast->next = NULL;
    }


    RET:
    #ifdef DEBUG
        printk(KERN_INFO "%s: End.\n", __func__);
    #endif
    return 0;

    OUT:
    #ifdef DEBUG
        printk(KERN_ERR "%s: End.\n", __func__);
    #endif
    return -1;
}