#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

ssize_t readDevice(struct file *filep, char __user *ubuff, size_t size, loff_t *loff)
{
    #ifdef DEBUG
    printk(KERN_INFO "Begin: %s\n", __func__);
    #endif
    
    #ifdef DEBUG
    printk(KERN_INFO "End: %s\n", __func__);
    #endif
    return 0;
}