#include "headers.h"
#include "declarations.h"
#include "defaults.h"

int nod = NOD;
dev_t devId;
struct class *dev_class;

static int __init init_func(void)
{
    int ret;
    printk(KERN_INFO "%s: Start\n", __func__);

    ret = alloc_chrdev_region(&devId, MINORNUMBER, nod, DEVNAME);
    if(ret < 0)
    {
        pr_err("Can not allocate major number\n");
        return -1;
    }

    pr_info("Major: %d, Minnor: %d\n", MAJOR(devId), MINOR(devId));

    // creating struct class
    dev_class = class_create(THIS_MODULE, "SachinClass");

    // create device
    device_create(dev_class, NULL, devId, NULL, "Sachin_Device1");

    printk(KERN_INFO "%s: End\n", __func__);
    return 0;
}

module_init(init_func);