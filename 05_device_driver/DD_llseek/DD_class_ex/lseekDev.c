#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

loff_t lseek_dev(struct file *filep, loff_t offset, int origin)
{
    
    #ifdef DEBUG
    printk(KERN_INFO "Begin: %s\n", __func__);
    printk(KERN_INFO "%s: f_pos: %d\n", __func__, (int)filep->f_pos);
    printk(KERN_INFO "%s: offset: %d\n", __func__, (int)offset);
    
    #endif

    switch(origin)
    {
        case SEEK_SET:
            #ifdef DEBUG
                printk(KERN_INFO "SEEK_SET\n");
            #endif
            // check offset limit
            if((filep->f_pos + offset) > size_of_device)
            {
                #ifdef DEBUG
                printk(KERN_INFO "offset too big\n");
                #endif
                goto OUT;
            }
            filep->f_pos = offset;
            break;
        case SEEK_CUR:
            #ifdef DEBUG
                printk(KERN_INFO "SEEK_CUR\n");
            #endif
            break;
        case SEEK_END:
            #ifdef DEBUG
                printk(KERN_INFO "SEEK_END\n");
            #endif
            break;
    }


    #ifdef DEBUG
        printk(KERN_INFO "End: %s\n", __func__);
        printk(KERN_INFO "%s: f_pos: %d\n", __func__, (int)filep->f_pos);
        printk(KERN_INFO "%s: offset: %d\n", __func__, (int)offset);
        
    #endif
    
    return filep->f_pos;

OUT:
    #ifdef DEBUG
        printk(KERN_INFO "End: %s\n", __func__);
        printk(KERN_INFO "%s: f_pos: %d\n", __func__, (int)filep->f_pos);
        printk(KERN_INFO "%s: Error: offset: %d too large\n", __func__, (int)offset);
    #endif
    
    return filep->f_pos;

}