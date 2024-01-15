# Creation of Device File
Once driver of a device is loaded into the kernel, Its device file need to be created or should be available so that application can access the device (as all devices are file in Linux). With the help of this device file we can do any system call e.g. open, read, write etc on device.

device files are available in the `/dev/` directory. Here */dev/null* is also a device which is generally used as a byte sink.


## Manual Creation
Device file can be created manually using ```mknod``` command. We insert the driver normally and then create a device file with the following command:

`$mknod -m <permission> <name> <device_type> <major_number> <minor_number>`

1. `device_type`: c --> character device, b--> block device


## Automatic creation of device file
The automatic creation of device files is handeled by *udev* which is a kernel device manager and creates/removes device nodes. This code create device file automatically. The created file will be available in the `/dev/` directory. The steps for creating device file automatically is as follows:

1. Create the struct class
2. Create device with the class created in step 1.


### Create the Struct Class
Once class is created then it will be visible in `/sys/class/` folder.

```struct class *class_create(struct module *owner, const char *name)```

Once class is creted then it needs to be destroyed as well upon unloading of the driver.

`void class_destroy (struct class *cls)`

*Example:*

```
static struct class *dev_class;
dev_class = class_create(THIS_MODULE, "sachin_device_class");
if(IS_ERR(dev_class))
{
    pr_err("cannot create the struct class");
    unregister_chrdev_region(dev, nod); // remove chrdev_region, nod: number of devices
    return -1;
}
```

### Create Device
The device class is used to create the device. The following function is used to do the same:

`struct device *device_create(struct *class, struct device *parent, dev_t dev, void *drvdata, const char *fmt,....)`

`... : means variable argument`

Once device is created then it needs to be destroyed from cleanup function or earlier
`void device_destroy (struct class * class, dev_t dev)`

*Example*
```
if(IS_ERR(device_create(dev_class, NULL, dev, NULL, "sachin_device")))
{
    pr_err("cannot create device\n");
    goto r_device;
}

r_device:
    class_destroy(dev_class);
    unregister_chrdev_region(dev, nod);
    return -1;
```

## Cleanup function
In cleanup function we should remove everything one by one in the following order:
1. destroy device
2. destroy class
3. Clear allocated chrdev region