#include<headers.h>

static int __init myDevInit(void)
{
    printk(KERN_INFO "Hello Kernel!!");
    return 0;
}

module_init(myDevInit);
