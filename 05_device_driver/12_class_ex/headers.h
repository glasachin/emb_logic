#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/slab.h> // to include kmalloc()
#include<linux/cdev.h>
#include<linux/moduleparam.h>

MODULE_LICENSE("GNU/GPL");
MODULE_AUTHOR("sachin");
MODULE_DESCRIPTION("Implemnting Open operation");