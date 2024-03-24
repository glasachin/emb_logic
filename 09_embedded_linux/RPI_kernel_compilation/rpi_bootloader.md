# Bootloader
First of all we need to create the bootloader for raspberry pi. Bootloader creates the necessary *.dtb and other files. 

Furthermore, RPi also needs some `start.elf` files as well which are not provided by the some bootloaders, so we can copy the official bootloader files from `github` and then compile ours.

## Add Files to the Boot Partition:
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

## Create Bootloader using U-Boot

`u-boot` is a second stage bootloader. Raspberry Pi, by default, has 2 bootloaders; bootcode.bin and start.elf, and we need both before booting u-boot (Because Raspberry pi is using very odd SoC, which has GPU in it. Those bootloaders take care of GPU initialization.).

**Get U-Boot**

Download the source code using git.

`git clone git://git.denx.de/u-boot.git`

**Configuring according to RPi**

Before building, this has to be configured for the specific target hardware. You can find the default config for Raspberry pis by doing this;

`ls configs | grep rpi`

Then, you’ll get output like below;

```
rpi_0_w_defconfig
rpi_2_defconfig
rpi_3_32b_defconfig
rpi_3_b_plus_defconfig
rpi_3_defconfig
rpi_4_32b_defconfig
rpi_4_defconfig
rpi_arm64_defconfig
rpi_defconfig
```

To apply this config, use make command like below (You can export ARCH and CROSS_COMPILE variables).

`make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- rpi_3_defconfig` ==> this is for RPi3

Also, we can customize “default boot command”, “timeout” and so on, by using interactive “menuconfig”, but it’s not mandatory.

`make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- menuconfig`

**Building Bootloader**

Then build it. You can specify number of parallel jobs by specifying `-j` option.

`make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- -j 4`

**Moving to Boot Partition of SD Card**

After building, copy `u-boot` to `boot` partition on SD card, renaming it to `kernel8.img`. The number could be anything higher than “7”, because higher number will be chosen by previous stage bootloader (by default, there are “kernel.img” and “kernel7.img” for compatibility). Since we will be using “u-boot” after default bootloader, we don’t need “config.txt” in boot partition. Rename it to “config.txt.orig” or something to eliminate this from boot process.

**Create Boot Script**

```Note: Role of this section is not completely known```

Then, you have to prepare “boot script” for u-boot. Here’s an example (rpi_bootscript.txt).

```
mmc dev 0                                                                   
fatload mmc 0:1 ${kernel_addr_r} Image                                      
fatload mmc 0:1 ${fdt_addr_r} bcm2710-rpi-3-b.dtb                           
setenv bootargs "console=serial0,115200 console=tty1 root=/dev/sda1 rw rootfs type=ext4 rootwait devtmpfs.mount=0"                                       
booti ${kernel_addr_r} - ${fdt_addr_r}
```

Basically, what it does is, reading “kernel image”, “device tree blob” and (if needed) “initrd” from SD card, and put it into DRAM. Also, the important thing is “kernel bootarg”. It is important to customize this since we are mounting root filesystem from external storage (root=/dev/sda1).

Create image for boot script. “mkimage” is in <u-boot>/tools. Add the path before making boot script.

```
export PATH=${PATH}:tools # Note, "tools" is in u-boot directory
mkimage -A arm -O linux -T script -a 0 -e 0 -C none -d rpi_bootscript.txt boot.scr
```

