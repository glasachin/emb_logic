#include"headers.h"
#include"declarations.h"
#include"operations.h"
//Cleanup Function
static void __exit myDevExit(void)
{
    printk(KERN_INFO "%s: Begin \n", __func__);
    unregister_chrdev(majorNo, "MyCharDriver");
    printk(KERN_INFO "Bye for Now!!\n");
}

module_exit(myDevExit);