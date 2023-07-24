#include"headers.h"
#include"declarations.h"
// #include"operations.h"
#include"defaults.h"
//Cleanup Function
static void __exit myDevExit(void)
{
    printk(KERN_INFO "%s: Begin \n", __func__);
    // unregister_chrdev(majorNo, "MyCharDriver");
    unregister_chrdev_region(devid, NOD);
    printk(KERN_INFO "Bye for Now!!\n");
}

module_exit(myDevExit);