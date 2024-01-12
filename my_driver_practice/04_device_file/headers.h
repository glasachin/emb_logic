#ifndef __HEADERS_H__
#define __HEADERS_H__

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/err.h>
#include <linux/device.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sachin");
MODULE_DESCRIPTION("This is the driver for creating and testing Device Files.");
MODULE_VERSION("0.0.4"); // similar to the file number

#endif