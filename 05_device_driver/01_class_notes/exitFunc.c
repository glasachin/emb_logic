#include"headers.h"
//Cleanup Function
static void __exit myDevExit(void)
{
    printk(KERN_INFO "Bye for Now!!\n");
}

module_exit(myDevExit)