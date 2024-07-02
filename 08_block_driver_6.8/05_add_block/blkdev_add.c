#include "headers.h"
#include "declaration.h"

struct blkdev *blkdev_add(int major, int minor, char *name, sector_t capacity)
{
    int ret;
    struct blkdev *ldev;
    printk(KERN_INFO "%s: Init: %s, capacity: %ld\n", __func__, name, (long int)capacity);

    ldev = kzalloc(sizeof(struct blkdev), GFP_KERNEL);
    if (!ldev)
    {
        pr_err("%s: %d: ERROR: kzalloc() Failure, \n", __func__, __LINE__);
        ret = -ENOMEM;
        goto FAIL;
    }

    INIT_LIST_HEAD(&ldev->link);
    ldev->capacity = capacity;
    ldev->data = __vmalloc(capacity << SECTOR_SHIFT, GFP_NOIO | __GFP_ZERO);
    if(!ldev->data)
    {
        ret = -ENOMEM;
        kfree(ldev);
        goto FAIL;
    }

    printk(KERN_INFO "%s: End: \n", __func__);
    return 0;

FAIL:

    pr_err("Error: register_blkdev() failure.");

    return 0;
}