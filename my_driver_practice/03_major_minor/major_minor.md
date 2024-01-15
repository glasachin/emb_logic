# Manor Number and Minor Number
This driver code give example for allocating driver's major number and minor number via dyanmic or static allocation.

The device name with allocated MAJOR Number appears in ```/proc/devices``` file. Its content can be seen using **cat** command.

## dev_t
```dev_t``` is used to hold device numbers (Major and Minor). It is a 32-bit number with 12-bits for **Major Number** and 20-bits for **Minor Number** 

## Static Allocation

1. For static allocation, first we need to assign the Major and Minor number to our device. This is done using ```MKDEV(int major, int minor)```. 

2. Once major and minor numbers are obtained then we need to assign the same to our device.
```int register_chrdev_region(dev_t first, unsigned int count, char *name)``` 

    - it returns 0 for success and returns negative value in case of error.
    - ```count``` is the total number of required contiguous deve numbers.

3. If we want to read back the assigned major and minor numbers then that can be done using ```MAJOR(dev_t dev) and MINOR(dev_t dev);``` functions
### example
```
dev_t dev = MKDEV(236, 0);
register_chrdev_region(dev, 1, "Sachin_device");
```

## Dynamic Allocation
It will automatically allocate the major number and minor number based on its availability.

```int alloc_chrdev_region(dev_t *dev, unsigned int firstminor, unsigned int count, char *name)```

It return 0 in case of success and negative number in case of any error.

### Example
```
dev_t dev;
alloc_chrdev_region(&dev, 0, 1, "Sachin_device");
printk(KERN_INFO "MINOR: %d, MAJOR: %d\n", MINOR(dev), MAJOR(dev));
```

## Unregister device by freeing up the space
It is necessary to unregister the device once driver is unloaded from kernel. It can be done by the following command:

`void unregister_chrdev_region(dev_t first, unsigned int count)`