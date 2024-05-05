#include"headers.h"
#include"declaration.h"

void bdev_request(struct request_queue *queue)
{
    printk(KERN_INFO "Begin: %s\n", __func__);


    printk(KERN_INFO "End: %s\n", __func__);
}