#include"headers.h"
#include"operations.h"
#include"defaults.h"
#include"declarations.h"

dev_t devid;
int majorNo, minorNo, nod;
Dev *dev;
// Initialization function. Here we have nod = 20, i.e. 20 devices
// and then assign memory for them using kmalloc
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
    
    majorNo = MAJOR(devid);
    minorNo = MINOR(devid);

    printk(KERN_INFO "%s: Device Registration Successful. Major No: %d; Minor No: %d\n", __func__, majorNo, minorNo);

    dev = (Dev*)kmalloc(sizeof(Dev)*nod, GFP_KERNEL);
    if(!dev)
    {
        printk(KERN_ERR "%s: Error Device memory allocation failed \n", __func__);
        return -1;
    }

    memset(dev, '\0', sizeof(Dev));
    // device initialization
    // cdev_init();
    cdev_init(&dev->c_dev, &fops);
    ret = cdev_add(&dev->c_dev, devid, 1);
    if(ret == -1)
    {
        printk(KERN_ERR "%s: Error cdev_add() Failed.\n", __func__);
        return -1;
    }
    // printk(KERN_INFO "hello Kernel!!\n");
    printk(KERN_INFO "%s: End\n", __func__);
    return 0;
}

module_init(myDevInit);