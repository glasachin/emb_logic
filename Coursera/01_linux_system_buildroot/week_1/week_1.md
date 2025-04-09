# Week 1

**book**

1. Mastering Embedded Linux Programming
2. Linux System Programming 2nd edition (one pdf is in documents)
3. Linux Device Drivers 3rd edition (LDD)


## Linux Overview

* can run or a 32-bit processor with 16+MB of RAM and 8MB of flash. Needs Memory management unit for all practical purpose.
* May not be appropriate for some real time systems.

### Linux Command
basics

### Advanced Linux Command Line

* editing
* shell
* searching --> 
    * `find`
    * `grep`
* wildcards, pipes and redirections
    * `*`
    * `|`
    * `>`, `>>`
* permissions,
    * `chmod`
* Remote access to command line
    * `ssh`

### Scripts


## Introduction to System Programming


### System Programming

corenerstones 

1. system calls --> around 300
2. C library --> glibc,
3. C compiler/linker (toolchain) --> gcc

**ABI**

* Application binary interface
* Byte code specific hardware types,software/compiler. Requires match:
    * hardware
    * software libraries (glibc and version)
    * compiler

**POSIX**

* `portable operating system interface`


### Linux File System

* `linux inode (Index Node)`
    * Metadata used to track files on disk.
* two type of links
    * Hard and symbolic (symlinks)
* Linux special files
    * `Kernel objects represented as files`
        * Character Device: linear queue of bytes
        * Block Device: Array of bytes, addressable in a sector
        * Named Pipes/Sockets: Interprocess Communication

* specific types
    * NFS
    * ext4
    * fat

`good example for blocks while addressing`

### Processes and Threads

* `Linux Processes`: executable object code, running on hardware.
    * `elf`: executable and linkable format
* `Linux Threads`:
    * unit of activity within a process
    * Each thread has:
        * Stack - stores local variables
        * processor state/current location
    * `Memory address space is shared between threads`

**Memory**

* Each process has its own virtual memory.
* Each thread shares process virtual memory
* Sharing memory between threads:
    * access directly (global variables, use synchronization)
* sharing memory between processes
    * use Inter-Process Communication (IPC)


**Linux Signals**

### Users and Groups

uid (user id) `0` is the root user.

### Embedded Linux Toolchain

* compiler
* linker
* Run-time libraries
* GCC or Clang
    * Binutils : binary utilities
    * GCC
    * C Library: API based on POSIX definition

**setting us cross compilers**

* example toolchain for arm and use using QEMU (emulator)
    * link is given in the slides



