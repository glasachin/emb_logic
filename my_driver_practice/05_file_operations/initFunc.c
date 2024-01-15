#include "headers.h"
#include "defaults.h"
#include "declarations.h"
#include "operations.h"

int nod = NOD;
dev_t devId = 0;

struct class *dev_class;

static int __init initFunc(void)
{
    int ret;
    printk(KERN_INFO "%s: Start\n", __func__);

    // allocate space for device ID
    ret = alloc_chrdev_region(&devId, 0, NOD, DEV_NAME);
    if (ret < 0)
    {
        return -1;
    }
    printk(KERN_INFO "%s: Major No.: %d, Minor No.: %d\n", __func__, MAJOR(devId), MINOR(devId));

    // Create device class
    dev_class = class_create(THIS_MODULE, "sachin_class");
    if (IS_ERR(dev_class))
    {
        pr_err("Cannot create the struct class for device \n");
        goto r_class;
    }

    // Create Device
    if(IS_ERR(device_create(dev_class, NULL, devId, NULL, "Sachin_device")))
    {
        pr_err("Cannot create the device\n");
        goto r_device;
    }

    printk(KERN_INFO "%s: End, Module Inserted Successfully...\n", __func__);
    return 0;

r_device:
    class_destroy(dev_class);
r_class:
    unregister_chrdev_region(devId, nod);
    return -1;
}

module_init(initFunc);