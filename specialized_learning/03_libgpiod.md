# libgpiod

there are multiple version, check version by `gpiodetect --version`
* v1.6.x ==> older version
* v2.x.x ==> latest and not backward compatible



libgpiod is a C library and set of tools designed for interacting with the Linux GPIO (General Purpose Input/Output) character device, which is the standard interface for GPIOs in Linux systems. It's a replacement for the older, now deprecated, sysfs interface, offering a more flexible and efficient way to control GPIO lines. Essentially, `libgpiod provides a standardized API and utilities for accessing and managing GPIOs`, making it easier for userspace applications to interact with the kernel's GPIO subsystem. [1, 2, 3, 4]  
Here's a more detailed breakdown: [1, 1, 4, 4]  

• Replacement for sysfs: The older sysfs interface for GPIOs was deprecated in favor of the character device interface, and libgpiod is the primary library for using this newer interface. [1, 1, 4, 4]  
• Character Device: libgpiod works with the /dev/gpiochipN character device, which is the standard way for Linux userspace to interact with GPIOs. [3, 3, 4, 4]  
• C Library and Utilities: It provides a C API for programming GPIOs, as well as command-line utilities like gpiodetect, gpioinfo, gpioget, gpioset, gpiofind, and gpiomon. [1, 1, 5, 5]  
• Standardized API: libgpiod offers a standardized API for interacting with GPIO controllers and pins, simplifying the development of GPIO-based applications. [1, 1]  
• Features: It includes features like: [1, 1]  
	• Multiple GPIO pin access: You can read or write multiple GPIO pins at once. [1, 1]  
	• Pin configuration: You can configure GPIO pin settings like pull-up/pull-down at runtime. [1, 1]  
	• Interrupt-driven event monitoring: You can monitor GPIO lines for rising or falling edges using interrupts. [1, 1, 6]  
	• GPIO controller and pin naming: You can find GPIO controllers and pins by their names, making it easier to manage them. [1, 1]  

• Benefits: [4, 4]  
	• More efficient: The character device interface is more efficient than the old sysfs interface. [4, 4]  
	• More flexible: It offers more features and functionality. [4, 4]  
	• Standardized: It provides a consistent API for interacting with GPIOs. [1, 1]  

• Languages: While the core libgpiod is in C, it also provides bindings for higher-level languages like Python. [1, 1, 4, 4]  


[1] https://www.variscite.com/blog/introducing-libgpiod/

[2] https://kernel.googlesource.com/pub/scm/libs/libgpiod/libgpiod/+/v0.2.x/README.md

[3] https://forums.raspberrypi.com/viewtopic.php?t=366693

[4] https://libgpiod.readthedocs.io/en/stable/

[5] https://www.beyondlogic.org/an-introduction-to-chardev-gpio-and-libgpiod-on-the-raspberry-pi/

[6] https://github.com/starnight/libgpiod-example


## Test

`https://libgpiod.readthedocs.io/en/latest/gpio_tools.html`

**Installation of the gpiod tools**

* `$ sudo apt install gpiod`
* `$ apt show gpiod`
* `apt show libgpiod2`

**Installation of the gpio Libraries**

* `sudo apt install libgpiod-dev`
* `$ sudo apt info libgpiod-dev`

**useful commands**

* `gpioinfo`
* `gpiodetect`
* `gpiofind`
* `gpiomon`
* `gpioset` and `gpioget`

## Hardware Constraints or Limitations

**⚡ Estimated Frequency with gpiod:**

1. Typical Max Frequency: ~1–3 kHz (reliable).

2. Upper Limit: Up to ~10 kHz, but not stable.

3. **Why limited?**

	* gpiod is a userspace library interacting with GPIO through the Linux GPIO character device.

	* It incurs system call overhead and is not real-time, which causes jitter and delays.

	* The toggling is done by issuing IOCTL calls for every state change, which adds latency.


## Interrupts using libgpiod


