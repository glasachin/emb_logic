#ifndef __HEADERS_H__
#define __HEADERS_H__
    #include<linux/init.h>
    #include<linux/module.h>
    #include<linux/fs.h>
    #include<linux/slab.h> // to include kmalloc()
    #include<linux/cdev.h>
    #include<linux/moduleparam.h>
    #include<linux/kernel.h>
    #include<linux/uaccess.h>
    // #include<linux/semaphore.h>
    #include<linux/completion.h>

    MODULE_LICENSE("GNU/GPL");
    MODULE_AUTHOR("sachin");
    MODULE_DESCRIPTION("Implemnting Open operation");

#endif