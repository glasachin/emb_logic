# SD CARD Prepration
This section provides the procedure to prepare the SD card for Raspberry Pi. For this we need to partition the RPi into two section

* `Boot`: This is minimum of 500MB and it contains the boot related files. This should be in `FAT32` format.
* `root`: This partition contains the `rootfs` or root file system and linux. This one can be in `ext4` format.

Create two partitions one `fat32 (boot)` and another `ext4 (root)`. Currently I used the ubuntu diskutility for doing the same but other commands can also be used (should be learned)

`fdisk` utility is best for this job.

## Identify the SD Card

* `lsblk` to see the attached disks
* SD card partition related device will be available in `/dev/...`


## Creating the boot partition

**Format the SD Card:**

Insert the SD card into your computer.
Find the device name of your SD card (e.g., /dev/sdX). Be careful to select the correct device to avoid data loss.
Unmount the SD card if it is automatically mounted:

`sudo umount /dev/sdX*`

Partition the SD card:

`sudo fdisk /dev/sdX`

* Type o to create a new DOS partition table.
* Type n, then p, then 1, then Enter twice to create a new primary partition using the default values.
* Type t, then c, to set the partition type to W95 FAT32 (LBA).
* Type w to write the changes and exit.

**Format the Boot Partition:**

Format the partition as FAT32:

`sudo mkfs.vfat /dev/sdX1`

**Mount the Boot Partition:**

Create a mount point:

`sudo mkdir /mnt/boot` : make folder at any location

Mount the partition:

`sudo mount /dev/sdX1 /mnt/boot` : mount the SD card at specific location

## Prepare root file system (rootfs)

again repeat the process to create another partition using `fdisk`. Make remaining storage into `root` partition. 

Once, it is done..

`sudo mkfs.ext4 -L root /dev/sda1`

**Mount the root partition**

again create a mount point for `root` partition and mount the partition as it is done for `boot` partition.


## Un-Mounting the device

`sudo umount <mount-point>`