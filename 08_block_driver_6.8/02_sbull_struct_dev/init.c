#include "headers.h"
#include "declaration.h"

int majorno, nsectors, hardsect_size;
struct blkdev *bdev;


static int __init initialization_func(void)
{
    int ret = 0;
    #ifdef DEBUG
    printk(KERN_INFO "Begin: %s\n", __func__);
    #endif

    majorno = MAJORNO;
    nsectors = NSECTORS;
    hardsect_size = HARDSECT_SIZE;

    majorno = register_blkdev(majorno, BDDNAME);
    if(majorno <= 0)
    {
        #ifdef DEBUG
        // printk(KERN_ERR "register_blkdev() failiure\n");
        pr_err("%s: Error: register_blkdev() failure.\n", __func__);
        return -EBUSY;
        #endif
        // goto OUT;
    }
    #ifdef DEBUG
    printk(KERN_INFO "Major No: %d\n", majorno);
    printk(KERN_INFO "END: %s\n", __func__);
    #endif

    bdev = kzalloc(sizeof(struct blkdev), GFP_KERNEL);
    if(!bdev)
    {
        ret = -ENOMEM;
        pr_err("Error: register_blkdev() failure.\n");
        // printk(KERN_ERR "kmalloc() failure\n");
        // unregister_blkdev(majorno, DEVNAME);
        goto OUT;
    }

    printk(KERN_INFO "%s: End.\n",__func__);
    // bdev->size = nsectors * hardsect_size;
    // bdev->data = vmalloc(bdev->size);
    // if(!bdev->data)
    // {
    //     printk(KERN_ERR "vmalloc() failure\n");
    //     kfree(bdev);
    //     unregister_blkdev(majorno, DEVNAME);
    //     goto OUT;
    // }

    return 0;

OUT:
    #ifdef DEBUG
        pr_err("Error: register_blkdev() failure.");
    #endif
    return ret;
}

module_init(initialization_func);