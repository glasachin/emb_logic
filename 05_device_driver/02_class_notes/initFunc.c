#include"headers.h"

// Initialization function
static int __init myDevInit(void)
{
    
    printk(KERN_INFO "hello Kernel!!\n");
    printk(KERN_INFO "%s: End\n", __func__);
    return 0;
}

module_init(myDevInit);