#include "headers.h"
#include "declarations.h"
#include "defaults.h"
#include "operations.h"

int nod = NOD;
dev_t devId; // it contains the Major and Minor Number of driver
struct class devClass;
struct cdev *dev;

uint8_t *kbuff;

static int __init initFunc(void)
{
    int ret;
    printk(KERN_INFO "%s: Start\n", __func__);

    /*1. Get Major and Minor Number by allocating the region*/
    ret = allock_chrdev_region(&devId, START_MINOR_NO, nod, DEV_NAME);
    if(ret < 0)
    {
        return -1;
    }

    printk(KERN_INFO "Major: %d, Minor: %d\n", MAJOR(devId), MINOR(devId));
    
    /*2. Create Device File*/
    /*a. create device class*/
    
    /*b. add device file*/

    printk(KERN_INFO "%s: End\n", __func__);
    return 0;
} 
module_init(initFunc);