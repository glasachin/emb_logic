#include"headers.h"
#include"operations.h"
#include"declarations.h"

int majorNo;

// Initialization function
static int __init myDevInit(void)
{
    printk(KERN_INFO "%s: Begin \n", __func__);
    // register device driver into the kernel's device table
    majorNo = register_chrdev(0, "MyCharDriver", &fops);
    if(majorNo == -1)
    {
        printk(KERN_ERR "%s: Error: device registration failed\n",__func__);
        return -1;
    }
    printk(KERN_INFO "%s: Device Registration Success ful Major numbr %d\n", __func__, majorNo);

    // printk(KERN_INFO "hello Kernel!!\n");
    printk(KERN_INFO "%s: End\n", __func__);
    return 0;
}

module_init(myDevInit);