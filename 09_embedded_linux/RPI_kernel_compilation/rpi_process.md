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

