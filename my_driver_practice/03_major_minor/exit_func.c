#include"headers.h"
#include"declarations.h"

static void __exit exit_func(void)
{
    printk(KERN_INFO "%s: Started\n", __func__);

    unregister_chrdev_region(devId, nod);

    printk(KERN_INFO "%s: End\n",__func__);
}

module_exit(exit_func);