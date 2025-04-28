# Week 2

## Linux Character Drivers

### Connecting to userspace

simple example

* `SCULL`: Simple character utility for loading localities
    * acts on memory as if it were a device
    * Not a `real` device driver

* `mknod [name] [type] [major] [minor]`
* `unregister_chrdev`


