#include"headers.h"
// #include"operations.h"
#include"defaults.h"
#include"declarations.h"

dev_t devid;
int majorNo, minorNo, nod;

// Initialization function
static int __init myDevInit(void)
{
    int ret;
    printk(KERN_INFO "%s: Begin \n", __func__);

    majorNo = MAJORNO;
    minorNo = MINORNO;
    nod = NOD;

    // register device driver into the kernel's device table
    ret = alloc_chrdev_region(&devid, minorNo, nod, CDDNAME);
    if(ret == -1)
    {
        printk(KERN_ERR "%s: Error: Device Registration Failed\n", __func__);
    }
    // majorNo = register_chrdev(0, "MyCharDriver", &fops);
    // if(majorNo == -1)
    // {
    //     printk(KERN_ERR "%s: Error: device registration failed\n",__func__);
    //     return -1;
    // }
    // printk(KERN_INFO "%s: Device Registration Success ful Major numbr %d\n", __func__, majorNo);

    // printk(KERN_INFO "hello Kernel!!\n");
    printk(KERN_INFO "%s: End\n", __func__);
    return 0;
}

module_init(myDevInit);