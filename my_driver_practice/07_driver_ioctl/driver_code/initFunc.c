#include "headers.h"
#include "declarations.h"
#include "defaults.h"
#include "operations.h"

static int __init initFunc(void)
{
    printk(KERN_INFO "%s: Start\n", __func__);

    
    printk(KERN_INFO "%s: End\n", __func__);
    return 0;
} 
module_init(initFunc);