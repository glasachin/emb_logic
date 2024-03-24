# Custom Linux Kernel on Raspberry Pi

This explains the process for booting RPi hardware using customized or compiled Linux kernel. There are several ways of doing the same and we have tried to explain the procedure here.

Here we will be using some other computer to compile the Linux and hence this entire process will be known as `cross compilation`.

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


## Process for RPi Linux

We need to create `bootloader` and `Linux Kernel` both. we need toolchain to generate AARCH64 binary. Toolchain is set of compilers and other tools like linker.

`prepare sd card` related documents for RPI [here](./sd_card_prepration.md)

`bootloader` related documents for RPi can be found [here](./rpi_bootloader.md).

`rootfs` related documents for RPi can be found [here](./rpi_rootfs.md)

`copy on SD card` related documents for RPi [here](./rpi_copy_sd_card.md)

## Some other important or useful links

**Cross Compilers**

`https://github.com/abhiTronix/raspberry-pi-cross-compilers`


