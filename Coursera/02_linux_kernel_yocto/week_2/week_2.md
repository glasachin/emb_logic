# Week 2

## Linux Character Drivers

### Connecting to userspace

simple example

* `SCULL`: Simple character utility for loading localities
    * acts on memory as if it were a device
    * Not a `real` device driver

* `mknod [name] [type] [major] [minor]`
* `unregister_chrdev`

* `/proc/devices` : contains current list of allocated devices and associated driver

* `AWK`

### Device drivers File operations

* connect driver operations to device number
    * open, read, write etc
driver open from mknod node `/dev/yourdev`

```
struct file_operations xyz = 
{

}
```

* lot of definitions in book are out of date.
* read source code for update




