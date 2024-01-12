#include "headers.h"
#include "declarations.h"

static void __exit exit_func(void)
{
    printk(KERN_INFO "%s: Start\n", __func__);

    device_destroy(dev_class, devId);
    class_destroy(dev_class);
    unregister_chrdev_region(devId, nod);

    printk(KERN_INFO "%s: End\n", __func__);

}

module_exit(exit_func);