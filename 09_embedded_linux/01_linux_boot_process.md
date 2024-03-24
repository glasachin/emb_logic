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
    


## BIOS (another theory class from EMBLOGIC)
There is no bios from 2020 onwards, all works on `UEFI`
* when we power on our computer
    * the BIOS or UEFI Firmware is the first software that runs.
* It performs  self test.

### BIOS/UEFI
`basic ip/op system / Unified extensible firmware interface`

`bios` -> BL1 -> BL1.5 -> Hard-drive

`UEFI` -> direct `Hard Drive`

### Bootloader
* once the boot device is identified
    * THe bios/uefi locads the bootloader into tmemmory from
        * the MBR (master boot record)
        * the GUID partition table (GPT) of the boot device
* Common linux bootloaders include
    * GRUB (Grand Unified Bootloader)
    * LILO

### Kenel Initialization
* it initializes the necessary resources.
* It is loaded into memoryb by the bootloader.
* It idenentifies and mounts the root filesystem which contains the core of operating systems

### InitRAMFs
* In some cases
    * an initramfs is used to provide
        * additional driver
        * modules needed to mount the root filesystem
* it is a temporatry root filesystem loaded into memory
* it allows ther kernel to locad necessary modules.

### Init Process SystemD
* The init processis the first user-space process nad has PID 1.
* In modern Linux, init has been replaced by `systemd` or other init systems
* systemd is widely used and manages the initialization and management of system services and processes.

### User Space
`PTBR` -> Page table base register
* Once init or systemd process is stared, 
    * it initializes the user space components.

### Login Manager
* If the system is configured witha a graphical user Interface (GUI)
    * a login manager such as
        * GDM: Genome display manager
        * KDM: KDE display manager may start
            * presenting a graphical login screen

### User Login
* after successfull login authentication
    * ther user shell is started 
    THe user is presented with a command line interface

### Linux is UP
* This completes the Linux boot process


## BIOS
* firmware
* initiates hardware during the booting process
* provides runtimver services for operating system
* a bridge beween Operating system and hardware

### A Firmware
* Acting as a piece of firmware embedded on a small memory chip on the computer's motherboard
* There is chip (bios chip) on mother board. It initialize and test.

### core functions  of BIOS
**POST (Power on self-test)**

1. upon powering on the computer it performs POST.

**Initialization**

`(BRT) bit recognition time` cannot be constant. It is set each time when computer boots up.

goto `/dev/` there is device `nvrm (non-volatile RAM)`. Initial BRT is set based on this.

The BIOS stores device configurations and system settings in a non-volatile memory (nvram)
* e.g. CMOS battery-backed RAM.
* allowing the system to remember its state acroos reboots.

**bootstrapping**


**BIOS interfaces and Settings**


**Modern Evolution: UEFI**

* The `Unified extensible firmware interface (UEFI)` is a modern replacement for traditional BIOS firmware interfaces.
    * offering more advanced freatures,
    * better boot
