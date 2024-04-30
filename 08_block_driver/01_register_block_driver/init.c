#include "headers.h"
#include "declaration.h"

int majorno;

static int __init initialization_func(void)
{
    #ifdef DEBUG
    printk(KERN_INFO "Begin: %s\n", __func__);
    #endif

    majorno = MAJORNO;

    majorno = register_blkdev(majorno, DEVNAME);
    if(majorno < 0)
    {
        #ifdef DEBUG
        printk(KERN_ERR "register_blkdev() failiure\n");
        #endif
        goto OUT;
    }
    #ifdef DEBUG
    printk(KERN_INFO "Major No: %d\n", majorno);
    printk(KERN_INFO "END: %s\n", __func__);
    #endif
    return 0;

OUT:
    #ifdef DEBUG
        printk(KERN_ERR "End(error): %s\n", __func__);
    #endif
    return -1;
}

module_init(initialization_func);