#include"headers.h"
#include"defaults.h"
#include"declarations.h"
#include"operations.h"

dev_t devid, devno;
int majorNo, minorNo, nod;
Dev *dev;
//struct file_operations fops;
// Initialization function. Here we have nod = 20, i.e. 20 devices
// and then assign memory for them using kmalloc

module_param(nod, int, S_IRUGO);

static int __init myDevInit(void)
{
    int ret, i;
    printk(KERN_INFO "%s: Begin \n", __func__);

    majorNo = MAJORNO;
    minorNo = MINORNO;
    // nod = NOD;

    // register device driver into the kernel's device table
    ret = alloc_chrdev_region(&devid, minorNo, nod, CDDNAME);
    if(ret == -1)
    {
        printk(KERN_ERR "%s: Error: Device Registration Failed\n", __func__);
        goto OUT;
    }
    
    majorNo = MAJOR(devid);
    // minorNo = MINOR(devid);

    printk(KERN_INFO "%s: Device Registration Successful. Major No: %d; \n", __func__, majorNo);

    dev = (Dev*)kmalloc(sizeof(Dev)*nod, GFP_KERNEL);
    if(!dev)
    {
        printk(KERN_ERR "%s: Error Device memory allocation failed \n", __func__);
        // return -1;
        goto OUT;
    }

    memset(dev, '\0', sizeof(Dev));
    
    // device initialization
    for(i = 0; i < nod; i++)
    {
        cdev_init(&dev[i].c_dev, &fops);
        //dev[i].owner = THIS_MODULE;
        //dev[i].ops = &fops;
        devno = MKDEV(majorNo, i);
        ret = cdev_add(&dev[i].c_dev, devno, 1);
        if(ret == -1)
        {
            printk(KERN_ERR "%s: Error cdev_add() Failed.\n", __func__);
            // return -1;
            goto OUT;
        }
        // minorNo = MINOR(devno);
        // printk(KERN_INFO "%s: Device Registration successful. Minor No: %d\n", __func__, minorNo);
        printk(KERN_INFO "%s: Device Registration successful. Minor No: %d\n", __func__, MINOR(dev[i].c_dev.dev));
    }
    
    // printk(KERN_INFO "hello Kernel!!\n");
    printk(KERN_INFO "%s: End\n", __func__);
    return 0;

    OUT:
        printk(KERN_ERR "%s: Error \n", __func__);
        return -1;
}

module_init(myDevInit);