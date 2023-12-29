#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

ssize_t writeSerialDevice(struct file *filep, const char __user *ubuff, size_t size, loff_t *loff)
{
    int not, noq, l, i;
    int noctw, nocsw; // noctw: no. of character to write, nocsw: no. of character successfully written
    Dev *ldev;
    size_t lsize;
    Item *curr;
    char ch;
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

    
    copy_from_user(&ch, ubuff, 1);
    printk(KERN_INFO "received data: %c\n", ch);
    outb(ch, THR); // demo send one data only

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