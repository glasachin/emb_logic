# Embedded Linux
* Linux is just a Kernel.
* `Embedded Linux systems` are the devices that use the
    * linux kernel
    * a variety of other software
* an `embedded linux distribution`
    * a prepackaged set of applications tailored for embedded linux systems.
    * Delvelopment tools
        * To build a complete system
* `Embedded Linux Vendor` 
    * They provide development tools
        * Cross Compilers, debuggers, project manage software, boot image builders etc.

## Namenclature

1. Host System
    * e.g. Computer

    Development tools are used here.
2. Target System

3. 

## Embedded Linux Classification
* These classification are based on
    * Size 

## Design/Implementation Methodology
* Determine system components
    * make a list of what is needed
    * Determine the hardware components that can be found as part of an embedded linux system.
    * Determining system requirements and LInux's compliance to these requirements has to be completed.
* Configure and build the kernel
* Build the root filesystem
    * The root file-system of an embedded linux system contains: 
        * the minimal set of applications, libraries and related files needed to run the system.
* Set-up boot s/w & configure
    * The methodology to package and boot a system is fairly similar among different architectures.
    * but varies according to the permanent storage device from

### Setting up and Using Development Tools
* The target environment is dissibmilar to the host on which the development is conducted.
* There is a need for host/target setup
    * the developer develops the software on the host
    * Downloads it onto the target for testing
    * There are two aspects to this setup.
        * Development
        * Debugging
* As the application cannot run on the bare hardware
    * There has to be a functional embedded linux system on the target hardware.
* The 

## 

### Host

* Several different types of Hosts
    * variant of Linux
        * linaro
        * debian GNU/LINUX
        * Fedora
*

### Development Setups
* There are 3 types of Host Target Development Setups
    * `Linked Setup`: Host and target are connected directly either serial or ethernet (Physical cable). No physical hardware storage device is transferred between the target and the host. All transfer occur via the link. 
        * Host
            * cross platform
            * development
        * Target
            * Bootloader
            * Kernel
            * Root Filesystem
    * `Removable Storage Setup`: very cost effective
        * Host --> same as linked
        * Target --> Bootloader 2
        * Secondary storage
            * can have secondary boot loader (1 and 1.5)
            * kernel
            * Root File System

    * `Standalone Setup`: No host, directly on the target board. Contains whatever is required.
        * boot loader
        * Kernel
        * full root
        * filesystem
        * Native Development environment

## Host-Target Debug Setups
There are basically three types of debug interfaces:

* A serial line
* A networking interface
* Special debugging hardware
