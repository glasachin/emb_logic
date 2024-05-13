# Block Driver for latest kernel


`/proc/modules`

## 03: *blkdev_catalog
The catalog for listing the list of block devices for which the driver is being registered. It will be atleast `2` with `name, sector-size`

This `char *blkdev_catalog = "blkdev1, 1024; blkdev2, 2048";` is declared globally

`int len`: it will be the lenght of the catalog.

`char *catalog`: ref to individual device in catalog.

`len = strlen(blkdev_catalog);`: find out the length of the catalog

