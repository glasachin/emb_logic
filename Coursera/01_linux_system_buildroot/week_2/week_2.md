# Week 2
only points, details can be done later

## Linux file I/O
* File descriptor (fd), integer value
    * stdin (fd 0) => input
    * stdout (fd 1) => output
    * stderr (fd 2) => 
* open()
* read()
* write()
* close()
* fopen(), fclose() etc are not system calls
* by default, `write` is into a kernel buffer as disks are slow.
* synchronized I/O
    * several ways to do synchronization
    * fsync(), fdatasync(), O_SYNC => these works based on file descriptors
    * sync() avoid it due to performance reasons, it works globally.
* Positional Read/Write (alternative to `lseek`)
    * pread
    * pwrite
* Sparse Files
    * `ls -lh` => shows human readable format
    * `du -sh` => disk usage, it shows sparse file as well
* Multiplexed I/O
    * select()
    * pselect()
    * poll

**system call logging tool**

* strace

## Process Management

* pid : process ID
    * pid 0: Pne per processor, idle process
    * pid 1: init process
* execl() : executing a program
* execv(), execvp(), execve()
* PATH variable
* fork()
    * creates a new PID for child. Often used to start daemons.
    * zombie process
    * wait() --> to obtain information about terminated child
    * waitpid(), waitid()
* system()    

**processes and Daemons**

* Process should execute with minimum level of rights possible.
* single foreground process group in a session
* &
* `Daemons`: which runs in the background does not connect to a controlling terminal.
    * often ends with `d`
* exit() ==> allows daemon's grandparent (init) to continue
* setsid()
* chdir("/")
* Different Daemon Options ( other than mentioned in the book)


## Basics of Embedded Linux

**Linux Kernel Overview**

* Overview of kernel source directories
    * arch : architecture files
    * documentation
    * drivers
    * fs: filesystem
    * include: #include from user/kernel space
    * init
    * kernel: core functions, scheduling, locking and timers
    * mm: memory management
    * net: networking
    * scripts
    * tools
* Elements of embedded Linux
    * toolchain
    * bootloader
    * kernel
    * root filesystem
* QEMU for Emulation
    * emulates a processor architecture and a board.
    * `qemu-system-arm` simulates ARM architecture devices
    * it is initiated using command line .

**Building the Linux Kernel**

* KConfig
    * text format whch controls kernel configuration
    * e.g. drivers/char/Kconfig
* Menuconfig
    * Terminal based graphical tool to modify kernel configuration using KConfig files
    * `make menuconfig`
* KConfig Options
    * off, on, Module
* Kernel Defconfigs
* Compile with `Kbuild`
* Build Artifacts
    * `vmlinux` : ELF binary
    * 

`steps to build/create kernel`




**Linux Root File System**

* Option 1: initramfs
* Option 2: block device
* minimal root filesystem contents
    * init
    * shell
    * daemons
    * shared libraries
    * configuration files (/etc)
    * device nodes (/dev)
    * /proc and /sys pseudo filesystems
    * kernel modules (/lib/modules/`kernel-version`)
* Hierarch Standards
    * /bin : programs for all users, used at boot
    * /dev/
    * /etc
    * /lib
    * /proc, /sys
    * /sbin
    * /tmp
    * /usr /usr/bin, /usr/sbin
    * /var

`How do we create a rootfs`

* start by creating the folder tree
* Use `BusyBox` to create files

`BusyBox Overview`: Make and Install Busybox

* make disclean
* make defconfig
* make ARCH=
* make CONFIG_PREFIX
