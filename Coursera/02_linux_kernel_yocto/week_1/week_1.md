# week 1

## Introduction to device drivers

* make hardware to respond to well defined abstraction interface
    * read(), write(), ioctl()
* 


### Device Driver Overview

* character device class => accessed as a stream of bytes
* block device class => for disk devices which can host a filesystem.
    * transfers data in blocks.
* network device class

* Kernel Filesystems
    * maps low level blocks on disk to directories and files.

* Buffer overrun => need to be careful for potential security lapse


## Introduction to Kernel Modules

### Kernel Modules


* `/var/log/syslog` ==> module message logs

* `module_init(funcname)` ==> identifies a function called when the module starts (from `insmod`)
* `module_exit(funcname)` ==> when module is unloaded (from `rmmod`)
* `printk`
* `MODULE_LICENSE`
* `Kernel stack` is small compared to applications
    * application default stack size is ~2MB i.e. huge variables in your local variables for your function
    * Kernel stack may be 4K in size
        * i.e. small space, done declare large automatic stack allocated variables
        * allocate memory dynamically
* reentrancy in kernel modules

### Building and Loading Kernel Modules

* write a `Makefile` block for module
    * `obj-m := hello.o`

* Invoke with
    * `make -C /path/to/kernel/source`
        M = `pwd`   ( gets the path of your module makefile)

* `ls -la /lib/modules` 
* `/usr/src` contains our kernel header source
* `Makefile` exists in the kernel source directory

* `insmod` : loads `.ko` file into the kernel after linking to kernel symbol table
* `rmmod`
    
* `/sys` and `/proc`


### Kernel Module Design Basics

* Version dependency
    * `vermagic`
    * rebuild module with appropriate kernel source.
    * macro can be used by yourself to make backward compatibility



