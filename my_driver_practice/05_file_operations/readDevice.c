#include "headers.h"
#include "defaults.h"
#include "declarations.h"
// #include "operations.h"

ssize_t readDevice(struct file *file, char __user *buf, size_t len, loff_t *off)
{
    printk(KERN_INFO "%s: Start\n", __func__);

    printk(KERN_INFO "%s: End\n", __func__);
    return 0;
}