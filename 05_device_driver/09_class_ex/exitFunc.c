#include"headers.h"
#include"declarations.h"
// #include"operations.h"
#include"defaults.h"
//Cleanup Function
static void __exit myDevExit(void)
{
    int i;
    printk(KERN_INFO "%s: Begin \n", __func__);

    for(i = 0; i < nod; i++)
    {
        dev->c_dev.dev = MKDEV(majorNo, i);
        cdev_del(&dev->c_dev);
    }
    // cdev_del(&dev->c_dev);
    kfree(dev);
    // unregister_chrdev(majorNo, "MyCharDriver");
    unregister_chrdev_region(devid, nod);
    printk(KERN_INFO "Bye for Now!!\n");
}

module_exit(myDevExit);