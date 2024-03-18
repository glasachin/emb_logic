# Custom Linux Kernel on Raspberry Pi

This process is for linux kernel provided by RPi for raspberry pi only.

https://www.raspberrypi.com/documentation/computers/linux_kernel.html

https://techexplorations.com/raspberry-pi/how-to-compile-a-custom-raspberry-pi-os-kernel/

https://yuhei1-horibe.medium.com/building-and-booting-fully-customized-os-on-raspberry-pi-f743899c79d

1. Setup SD card
    * fat32 partition (minimum 32MB)
    * ext4 partition (whatever space)
2. Create Bootloader
    * can be created using `u-boot` (same is used for several other boards)
    * create `bootscript`
3. Compile the required `kernel`

4. Create root file syste `rootfs` and install compiled kernel in `rootfs`. (instructions are given)


## Create the partitions on SD card
Create two partitions one `fat32 (boot)` and another `ext4 (root)`. Currently I used the ubuntu diskutility for doing the same but other commands can also be used (should be learned)

`fdisk` utility is best for this job.

## Process for RPi Linux

We need to create `bootloader` and `Linux Kernel` both. we need toolchain to generate AARCH64 binary. Toolchain is set of compilers and other tools like linker.

NOTE: SD card should be mounted inside the Linux folder.

### Building Custom Bootloader
`u-boot` is a second stage bootloader. Raspberry Pi, by default, has 2 bootloaders; bootcode.bin and start.elf, and we need both before booting u-boot (Because Raspberry pi is using very odd SoC, which has GPU in it. Those bootloaders take care of GPU initialization.).

## boot section or partition for RPI

### Preparing the Boot Partition

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

`sudo mkdir /mnt/boot`

Mount the partition:

`sudo mount /dev/sdX1 /mnt/boot`

### Adding Files to the Boot Partition:
Download Raspberry Pi Boot Files:

Download the Raspberry Pi boot files from the Raspberry Pi GitHub repository:
bash

`git clone https://github.com/raspberrypi/firmware.git`

Copy Boot Files to the SD Card:

Copy the boot files to the boot partition of the SD card:
bash
Copy code

`sudo cp -r firmware/boot/* /mnt/boot/`

Configure the Boot Partition (Optional):

If you need to configure the config.txt file or any other configuration file, you can do so now:
bash
Copy code

`sudo nano /mnt/boot/config.txt`

Unmount the Boot Partition:

Safely unmount the boot partition:
bash

`sudo umount /mnt/boot`