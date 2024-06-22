# Block Driver for latest kernel


`cat /proc/modules`

`cat /proc/devices`

`lsmod`

## 03: *blkdev_catalog
The catalog for listing the list of block devices for which the driver is being registered. It will be atleast `2` with `name, sector-size`

This `char *blkdev_catalog = "blkdev1, 1024; blkdev2, 2048";` is declared globally

`int len`: it will be the lenght of the catalog.

`char *catalog`: ref to individual device in catalog.

`len = strlen(blkdev_catalog);`: find out the length of the catalog

# 04

All block devices will be as a list of devices. so we will use a "catalog" of devices.

**Example**

`char *blkdev_catalog = "blkdev1, 1024; blkdev2, 2048";`

There are two devices in above definition separated by `;`

We have to keep the copy of the original catalogue

`IMP:` kstrtoull may not work on some machines


* Block device works on either of the two ways: `request based` or `block IO mode (bio) `