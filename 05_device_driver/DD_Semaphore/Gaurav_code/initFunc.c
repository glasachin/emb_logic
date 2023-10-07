#include"headers.h"
#include"defaults.h"
#include"declarations.h"
#include"operations.h"

dev_t devid,devno;
int majorNo, minorNo, nod;
Dev *dev;
int size_of_device, no_of_reg, size_of_reg,size_of_data;

module_param(size_of_device, int, S_IRUGO);
module_param(no_of_reg, int, S_IRUGO);
module_param(size_of_reg , int, S_IRUGO);
module_param(nod, int, S_IRUGO);

static int __init myDevInit(void)
{
    int ret;  
    int i;
    printk(KERN_INFO "%s:Begin.\n", __func__);
//register device driver
    majorNo = MAJORNO;
    minorNo = MINORNO;
    size_of_data = DATASIZE;
    size_of_device = DEVSIZE;
    no_of_reg = NOOFREG;
    size_of_reg = REGSIZE;
   // size_of_data = DATASIZE;
    // nod = NOD;
    
    ret = alloc_chrdev_region(&devid, minorNo ,nod, CDDNAME);
    if(ret == -1)
    {
    printk(KERN_ERR "%s:ERROR: Device Registration failed.\n", __func__);
    goto OUT; //return -1; //goto OUT can be used here also
    }
    majorNo = MAJOR(devid);
 // minorNo = MINOR(devid); // if code doesn't work uncomment this line
    printk(KERN_INFO "%s: Device Registration successful. MAjor No:%d\n ", __func__,majorNo);
    dev = (Dev*)kmalloc(sizeof(Dev)*nod, GFP_KERNEL);
    if(!dev)
    {
    printk(KERN_ERR "%s:ERROR: Device memory allocation failed.\n",__func__);
    goto OUT;//return -1; //goto OUT can also be used here
    }
    memset(dev,'\0',sizeof(Dev)*nod);
   
    //device initialisation
    for(i=0;i<nod;i++)
    {
    cdev_init(&dev[i].c_dev, &fops);
    dev[i].c_dev.owner = THIS_MODULE;
    dev[i].size_of_device = size_of_device;
    dev[i].no_of_reg = no_of_reg;
    dev[i].size_of_reg = size_of_reg;
    dev[i].size_of_data = size_of_data;
    dev[i].c_dev.ops = &fops;
    devno = MKDEV(majorNo, i);
    sema_init(&dev[i].sem,1);
    ret = cdev_add(&dev[i].c_dev, devno , 1);
    if(ret == -1)
    {
    printk(KERN_ERR "%s:ERROR: cdev_add() failed.\n",__func__);
    goto OUT;//return -1;
    }
   // minorNo = MINOR(devno);
    printk(KERN_INFO "%s: Device Registration successful. Minor No: %d\n", __func__,MINOR(dev[i].c_dev.dev));
    }

    printk(KERN_INFO "%s:End.\n", __func__);
    return 0;
OUT:
    printk(KERN_ERR "%s: ERROR: End.\n",__func__);
    return -1;
    }
    module_init(myDevInit);
