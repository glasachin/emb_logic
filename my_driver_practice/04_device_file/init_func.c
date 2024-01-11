#include "headers.h"
#include "declarations.h"
#include "defaults.h"

int nod = NOD;
dev_t devId;

static int __init init_func(void)
{
    int ret;
    printk(KERN_INFO "%s: Start\n", __func__);

    ret = alloc_chrdev_region(&devId, MINORNUMBER, nod, DEVNAME);

        printk(KERN_INFO "%s: End\n", __func__);
    return 0;
}

module_init(init_func);