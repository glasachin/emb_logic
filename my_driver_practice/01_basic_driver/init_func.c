#include"headers.h"
#include"declarations.h"

static int __init init_func(void)
{
    printk(KERN_INFO "%s: Started\n", __func__);


    printk(KERN_INFO "%s: End\n",__func__);
    return 0;
}

module_init(init_func);