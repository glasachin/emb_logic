#include "headers.h"
#include "declarations.h"
#include "defaults.h"
#include "operations.h"

int value;
char *name;
int varArray[NOE];
int cb_value;

module_param(value, int, S_IRUSR | S_IWUSR);
module_param(name, charp, S_IRUSR | S_IWUSR);               // to get string pointer
module_param_array(varArray, int, NULL, S_IRUSR | S_IWUSR); // to get parameters in an array
module_param_cb(cb_value, &my_param_ops, &cb_value, S_IRUSR | S_IWUSR);

#ifdef STATIC_DEV_ID
dev_t devId = MKDEV(236, 0); // Static Major and Minor Number allocation
#else
dev_t devId = 0;
#endif

int nod = NOD;

static int __init init_func(void)
{
    int i, ret;
    printk(KERN_INFO "%s: Started\n", __func__);

// register device
#ifdef STATIC_DEV_ID
    ret = register_chrdev_region(devId, nod, DEVNAME);
#else
    ret = alloc_chrdev_region(&devId, MINORNO, nod, DEVNAME);
#endif

    if(ret < 0)
    {
        printk(KERN_INFO "Cannot allocate major number for device\n");
        return -1;
    }

    printk(KERN_INFO "%s: Major = %d, Minor = %d\n", __func__, MAJOR(devId), MINOR(devId));

    printk(KERN_INFO "%s: value: %d\n", __func__, value);
    printk(KERN_INFO "%s: cb_value: %d\n", __func__, cb_value);
    printk(KERN_INFO "%s: name: %s\n", __func__, name);

    for (i = 0; i < NOE; i++)
    {
        printk(KERN_INFO "%s: arr_value[%d] = %d\n", __func__, i, varArray[i]);
    }

    printk(KERN_INFO "%s: End\n", __func__);
    return 0;
}

module_init(init_func);