#ifndef __HEADERS_H__
#define __HEADERS_H__

#include <linux/kernel.h>
#include <linux/kmalloc.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/err.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sachin Sharma");
MODULE_DESCRIPTION("This is simple ioct enabled character driver");
MODULE_VERSION("0.0.7");

#endif