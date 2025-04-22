# /sys/class/

This folder on embedded board contains different folders by the name of different devices available on the SOM.

The `/sys/class/` directory is part of the `Linux sysfs virtual filesystem`. It provides a user-space interface to the kernel's device model, especially for interacting with hardware classes.

## sysfs

`sysfs` is a virtual filesystem in Linux, mounted typically at `/sys`, that exposes information and control interfaces for `kernel objects—like devices, drivers, buses, classes, and modules`.

It’s not a real filesystem on disk — it lives in memory, and is maintained by the Linux kernel.


## 🧠 Purpose of sysfs
🧩 Gives user-space programs a way to interact with kernel components

📖 Lets you query hardware details or modify behavior

🛠️ Commonly used in embedded systems, drivers, and power/thermal control


## 🗂️ Structure of /sys
Here's what you’ll usually find:

Path	|What It Represents
---|---
/sys/class/	|Device classes (e.g. net, gpio, leds)
/sys/block/	|Block devices (like sda, mmcblk0)
/sys/bus/	|System buses (e.g. i2c, spi, usb)
/sys/devices/	|Actual hardware device tree
/sys/module/	|Kernel modules
/sys/firmware/	|Boot and firmware info (like ACPI or UEFI)

## Example

`cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq`


## Problems with `sysfs`
* The `/sys/class/gpio` interface (a.k.a. sysfs GPIO) is:

    * Deprecated since Linux kernel 4.8

    * Removed from many newer kernels (like RPi OS Bookworm)

* Not great for high-performance or real-time GPIO

* No support for edge interrupts, debouncing, or events (you have to poll it manually)

