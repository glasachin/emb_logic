#include "headers.h"
#include "declaration.h"

int init_tag_set(struct blk_mq_tag_set *set, void *data)
{
    printk(KERN_INFO "%s: Start: \n", __func__);

    set->ops = &mq_ops;

    printk(KERN_INFO "%s: End: \n", __func__);
    return 0;
}