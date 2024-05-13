#include<linux/init.h>
#include<linux/module.h>
#include<linux/blkdev.h>
#include<linux/types.h>
#include<linux/slab.h> // to include kmalloc()
#include<linux/vmalloc.h>
// #include<linux/cdev.h>

MODULE_LICENSE("GNU/GPL");
MODULE_AUTHOR("Sachin");
MODULE_DESCRIPTION("Block driver registration and memory allocation");