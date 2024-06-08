# ARM Based Board Bringup

1. Obtain the necessary Components
    * Obtain Kernel Image
    * Setup Cross Compiler: `arm-none-eabi-gcc`


## 1.

### 1b. arm-none-eabi-gcc

`arm`: processor
`none`: this indicates target doesn't have any os and only have baremetal code
`eabi`: Embedded Application Binary Interface, which is standardized set of conventions for binary interfacing in embedded systems. It defines how functions and data re represented at the binary level to ensure compatibility and efficiency. 
`gcc`: It stands for GNU Compiler Collection, which is a set of compilers produced by the GNU projects.

### 1c. Boot Loader
It is a small program that is executed when a computer or embedded system is powered on or reset.

* Initialization
    * Setting up the system hardware and preparing it to run software. 
    * It includes
        * initializing memory
        * setting up CPU registers
        * configuring peripherals
* Loading the Operating systems
    * locating the OS kernel and loading int into memory.
    * it involves reading the kernel from a storage device like a hdd, ssd or flash memory.
    * transferring it to RAM
* transferring control
    * passing control to the Operating system which then continues the boot process and eventually starts running user applications.

U-Boot is widely used bootloader for ARM boards.
1. Cross-platform Support
    * U-Boot can run on wide range of hardwaes
2. Network Booting
    * U-Boot supports booting over the network using protocols like TFTP
3. File System Support
    * It can read various file systems including FAT etc.
4. Scripting and Commands
    * 
5. Customizability
    * It can be customized  easily to meet the requirements

### 1d. Root Filesystem, Busybox
* It is a software utility that combines many common Unix/Linux command-line tools into a single executable file.
* It is designed to be lightweight and efficient, making it ideal for use in embedded systems.

