#include"headers.h"

// Initialization function
static int __init myDevInit(void)
{
    printk(KERN_INFO "hello Kernel!!\n");
    return 0
}

module_init(myDevInit)