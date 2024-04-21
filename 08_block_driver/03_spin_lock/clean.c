#include "headers.h"
#include "declaration.h"

static void __exit cleanup_func(void)
{
    #ifdef DEBUG
        printk(KERN_INFO "Begin: %s", __func__);
    #endif
    
    vfree(bdev->data);
    kfree(bdev);
    unregister_blkdev(majorno, DEVNAME);


    #ifdef DEBUG
        printk(KERN_INFO "End: %s", __func__);
    #endif
}

module_exit(cleanup_func);