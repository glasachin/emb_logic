# Linux Boot Process
Based on Class
* Power on Self Test (POST)
* BIOS/UEFI
* Boot Loader (BL)
* Kernel Initialization
* Initramfs (Initial RAM File System)
* Init Process (SystemD)
* User Space
* Login Manager (Optional)
* User Login

## Linux Boot Process (Macroscopic)
During boot, it only enables 5 keys at start using `Basic IO` and `Basic Drivers` in bios. 
* basic minimul display
* 

power ON => POST => BIOS/UEFI => ROM1 (in processor chip Bootloader) => ROM2 (On motherboard) =>

## ARM Chip
The manufactures will hard code the `BL1` into the processor chip so that the boot location can be standarised.

### Boot Loader 1
Small piece of software (within the chip), `size(387B)`. It's task is to find, next stage of Boot Loader. It referes to other location which is residing on ROM (ROM2 on motherboard) where main boot loader (`BL1.5 or BL2`) will be residing.

## Boot Loaders

### BL1
on chip ROM (ROM1)
### BL1.5
on motherboard ROM (ROM2) (Optional)
### BL2
on motherboard ROM (ROM2) or initial sectors.

main task is to 
* find `secondary storage` and load minimalistic block driver. 
* find `OS` in some initial sectors of SSD (secondary storage)
    * sector 0: contents
    * sector 1: BL2
    * sector 2: Ref to BIOS
    * sector 3: Min block driver
    * sector 4: Min display driver
    * sector 5: Ref to OS, Loader

## Kernel Initialization    
Os loads into memory by loader (from sector 5) and starts kernel initialization. Kernel has 30 sub-systems, all starts one by one.

## initial RAM File System (Initramfs)
OS create bare minimum file system in RAM (`RAMDISK`)
**RAMDISK**

It is a software file system implemented in memory to launch RootFs in Secondary Storage

OS then creates the `Filesystem Table` inside the secondary storage.

Page tables (PT) also gets created inside the RAM. It depends upon the register (`PTBR` => contains starting address of the page table) of the processor.


## MBR
Master boot record `MBR`. It is located in the 1st sector of the `bootable` disk `/dev/hda` or `dev/sda`.

MBR is less than 512 bytes in size. It has three compenents.
1. primary boot locader info in 1st 446 bytes.
2. partition table info in next 64 bytes.
3. `mbr` validation check in last 2 bytes.

Note: It is not located inside any partition.

`MBR may or may not be there depending upon the hardware system. If there is no MBR and BL2 will be find at 0th location (sector 0) of the secondary disk. If MBR is there then `BL2` location information will be inside (at the end) of MBR.`

Now, MBR loads and executes the `GRUB` boot loader.

`Note: if there is BL1.5 then MBR will not be used. This will not be there in the system if additional EEPROM is not present`

So, the first 446 bytes of MBR containthe code that locates the partition to boot from.
The rest of booting process takes place from that partition.
This partition contains a software program for booting the system.

## Stage 2 Bootloader

* have enough space to do luxurious stuff
* provides configurability and management
* Loads the operating system
* passes arguments to the operating system
* jumps to start executing the operating system
* Desktops bootloaders
    * LILO, GRUB, SYSLINUX
* Embedded bootloaders
    * U-boot (standard), secondary bootloader (custom based on company).
    