# Introduction

Boot loaders manages the boot process of a computer system. It initializes the hardware components and load the operating system into memory. 

Upon powering on, the CPU looks for the boot loader in the firmware (BIOS or UEFI) or on a specific storage device. The boot loader's job starts by testing the hardware (POST: Power on self test) and then loading the kernel of an operating system into RAM. 

In multi-boot systems, the boot loader presents a menu to select the desired OS to boot.

## Linux Boot Loaders
For Linux, boot loader not only loads the main Linux kernel but also the initial RAM disk (`initrd`), which contains temporary file systems and drivers needed by the kernel at boot time.

This process is critical in preparing the system before the actual kernel takes over and mounts the main file system.

