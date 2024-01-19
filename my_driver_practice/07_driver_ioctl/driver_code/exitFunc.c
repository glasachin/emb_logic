#include "headers.h"
#include "declarations.h"
#include "defaults.h"

static void __exit exitFunc(void)
{
    printk(KERN_INFO "%s: Start\n", __func__);


    printk(KERN_INFO "%s: End\n", __func__);
}
module_exit(exitFunc);