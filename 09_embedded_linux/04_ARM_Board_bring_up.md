# ARM Based Board Bringup

1. Obtain the necessary Components
    * Obtain Kernel Image
    * Setup Cross Compiler: `arm-none-eabi-gcc`
    * Boot Loader, u-boot, busybox
    * Root File system
2. Set up the Cross-Cpmpiler
    * Choose the cross-compiler
    * Install the cross-compiler on a debian-based system
    * Verify the installation
3. Buid the `U-Boot` loader
4. 



`set`: gives the environment variables

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

Use

* Minimalist shell environment
* system initialization
* diagnostics anddebugging
* embedded system maintenance
* script execution

Kye Features of Busy Box

* Single Binary: all commands are compiled into a single binary file.
* Configurable: It is highly configurable
* small footprint: Busy box is designed to have a small memory storage
* Compatibility: 

Busy box is often included in the initial filesystem to provide a basic working environment.

`How is busybox used during ARM Board Bringup?`
1. Building busybox
    * Download `wget https://busybox.net/downloads/busybox
    * Configure BusyBox
        * make defconfig
        * make menuconfig
        * make CROSS_COMPILE=arm-none-eabi- install
2. setting up the root filesystem
    
3. booting with busybox

```buildroot```



# 2. Setup the Compiler

* `gcc-arm-none-eabi`: gcc -> compiler, arm -> for ARM architecture, `none` -> no os on host machine at which compiler wll work
* `gcc-arm-linux-gnueabi`: `linux` -> host machine has linux


Once the cross-compiler is used then use the same to compile some test file (hello.c).

For more complex projects, we may need to configure additional settings in our build environment. IT can include makefiles etc.

* Environment Variables
* Makefiles

1. `Environment Variables Setup`

```export CROSS_COMPILE=arm-none-eabi
export PATH=$