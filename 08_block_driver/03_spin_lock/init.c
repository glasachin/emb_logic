#include "headers.h"
#include "declaration.h"

int majorno, nsectors, hardsect_size;
struct Dev *bdev;


static int __init initialization_func(void)
{
    #ifdef DEBUG
    printk(KERN_INFO "Begin: %s\n", __func__);
    #endif

    majorno = MAJORNO;
    nsectors = NSECTORS;
    hardsect_size = HARDSECT_SIZE;

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

    bdev = kmalloc(sizeof(struct Dev), GFP_KERNEL);
    if(!bdev)
    {
        printk(KERN_ERR "kmalloc() failure\n");
        unregister_blkdev(majorno, DEVNAME);
        goto OUT;
    }

    bdev->size = nsectors * hardsect_size;
    bdev->data = vmalloc(bdev->size);
    if(!bdev->data)
    {
        printk(KERN_ERR "vmalloc() failure\n");
        kfree(bdev);
        unregister_blkdev(majorno, DEVNAME);
        goto OUT;
    }

    spin_lock_init(&bdev->lock);
    // blk_init_queue(bdev_request, &bdev->lock);
    blk_put_queue(bdev->queue);

    return 0;

OUT:
    #ifdef DEBUG
        printk(KERN_ERR "End(error): %s\n", __func__);
    #endif
    return -1;
}

module_init(initialization_func);