# File Operations
This is part of real driver to call the device for read and write operations. We have implemented the following:
1. Driver will create a device file (```/dev/``` location) automatically, which can be used to perform read and write operations.

2. Driver will implement the several basic file operations, just for beginning.

In Linux `struct inode` is used to define the file related operations. In kernel driver code `struct cdev` is useful for writing the code. `cdev` is one of the element of `inode`.

## Struct `cdev`
`cdev` structure is as follows:
```
struct cdev {
    struct kobeject kobj,
    struct module *owner,
    const struct file_operations *fops,
    struct list_head list,
    dev_t dev,
    unsigned int count

}
```

In this `cdev` structure we need to primarily filled the following:
1. `file_operations` ==> to specify the function responsible for file related operations
2. `owner` ==> most of the time it is `THIS_MODULE`

Allocation for `cdev` can be done during
1. `runtime` or 
2. our own

## Run-Time Allocation

```
struct cdev *my_cdev = cdev_alloc();
my_cdev->ops = &my_fops;
```

## our own allocation
for a device-specific structure

**Initialization**

```void cdev_int(struct cdev *cdev, struct file_operations *fops)```

**Add cdev structure**

```int cdev_add(struct cdev *dev, dev_t num, unsigned int count)```

*num* : first device number

*count* : number of device numbers that should be associated with the device 

It returns a negative number in case of any error.

**Remove Device**

```void cdev_del(struct cdev *dev);```

## File Operations
The `file_operations` structure creates the connection between device file and file related functins. It is defined in `<linus/fs.h`. Generally, this structure is called as `fops`. Each field in this structure is a function pointer to the implementing function. Complete structure very large, only a small snippet is given here.

```
struct file_operatins{
    struct module *owner;
    loff_t(*llseek)(struct file*, loff_t, int);
    ssize_t(*read)(struct file*, char __user*, size_t, loff_t*);
    ssize_t(*write)(struct file*, const char __user*, size_t, loff_t*);
    int(*open)(struct inode *, struct file*);
    ---------
}
```

### Owner
```struct module *owner``` is not an operation. Most of the time the value of this is `THIS_MODULE`

### read function
```ssize_t(*read)(struct file*, char __user*, size_t, loff_t*);```
This is the function pointer and the corresponding function should be defined.

### Open function

### write function

### release function

### Example

functions can be defined in separate file and their signature can be in separate file (as a normal modular programming). 

**file_operations structure**
```
static struct file_operations fops=
{
 .owner = THIS_MODULE,
 .read = readDevice,
 .write = writeDevice,
 .open = openDevice,
 .release = releaseDevice,
};
```
**open function**
```
static int openDevice(struct inode *inode, struct file *file)
{

    return 0;
}
```
**read function**
```
static ssize_t readDevice(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
    .....
    return 0;
}
```

**write function**
```
static ssize_t writeDevice(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
    .....
    return len;
}
```

**release function**
```
static int releaseDevice(struct inode *inode, struct file *file)
{
    .....
    return 0;
}
```