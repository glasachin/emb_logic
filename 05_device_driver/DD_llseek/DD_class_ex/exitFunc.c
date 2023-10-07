#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

//Cleanup Function
static void __exit myDevExit(void)
{
    int i;
    printk(KERN_INFO "%s: Begin \n", __func__);

    for(i = 0; i < nod; i++)
    {
        dev[i].c_dev.dev = MKDEV(majorNo, i);
        cdev_del(&dev[i].c_dev);
    }
    // cdev_del(&dev->c_dev);
    kfree(dev);
    // unregister_chrdev(majorNo, "MyCharDriver");
    unregister_chrdev_region(devid, nod);
    printk(KERN_INFO "Bye for Now!!\n");
    return ;
}

module_exit(myDevExit);