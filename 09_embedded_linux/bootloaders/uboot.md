# uboot

`Das U-Boot`, (the Universal Boot Loader") often referred to as just "U-Boot," is a popular `open-source bootloader` used in embedded systems. It is designed to boot a variety of hardware platforms, including ARM, MIPS, x86, and others. U-Boot is highly configurable and supports features such as network booting, USB support, and scripting capabilities. It is commonly used in embedded Linux systems, including those running on Raspberry Pi boards, to initialize the hardware and load the Linux kernel into memory for execution.

e.g. `openStLinux` is also based on `u-boot`.

U-Boot typically works in the following way:

1. `Initialization`: When the device is powered on or reset, U-Boot initializes the hardware, including memory, peripherals, and other components necessary for booting.

2. `Boot Selection`: U-Boot provides a `command-line interface (CLI)` that allows users to interact with the bootloader. From here, users can select the boot source, such as booting from an SD card, USB drive, network, or internal storage.

3. `Loading the Kernel`: Once the boot source is selected, U-Boot loads the Linux kernel image from the specified location (e.g., SD card, network) into memory.

4. `Device Tree`: U-Boot may also load a `device tree blob (DTB)` file, which describes the hardware configuration of the device. The device tree is used by the kernel to configure device drivers and other hardware-specific settings.

5. `Boot Parameters`: U-Boot passes boot parameters, such as the memory location of the kernel image and the DTB file, to the kernel before booting.

6. `Booting the Kernel`: Finally, U-Boot boots the Linux kernel by jumping to its entry point in memory, passing the boot parameters to the kernel. The kernel then takes over and continues the boot process, initializing drivers, mounting the root filesystem, and starting user-space processes.

## U-Boot Overview

### U-Boot SPL
`U-Boot SPL (Secondary Program Loader)` is a component of U-Boot that serves as a `first-stage bootloader`. It is designed to be small and efficient, allowing it to fit into the limited `boot ROM` or boot space available on many embedded devices. `U-Boot SPL` is responsible for initializing the hardware just enough to load the full `U-Boot bootloader` (often referred to as "U-Boot proper") into memory.

The typical boot process involving U-Boot SPL is as follows:

* `Power-on or Reset`: When the device is powered on or reset, the processor starts executing the code stored in the boot ROM or a fixed location in memory.

* `U-Boot SPL Execution`: The code executed by the processor is the U-Boot SPL. U-Boot SPL initializes the basic hardware necessary for the boot process, such as memory, clocks, and serial ports.

* `Loading U-Boot Proper`: After initializing the hardware, U-Boot SPL loads the full U-Boot bootloader (U-Boot proper) from a storage device, such as an SD card, NAND flash, or SPI flash, into memory.

* `Transfer Control to U-Boot Proper`: Once U-Boot proper is loaded into memory, U-Boot SPL transfers control to it, allowing U-Boot proper to continue the boot process, including loading the kernel and starting the operating system.

U-Boot SPL is typically used in scenarios where the full U-Boot bootloader is `too large` to fit into the limited boot ROM or boot space available on the device. By using U-Boot SPL as a first-stage bootloader, the full U-Boot bootloader can be loaded from storage into memory, enabling a more flexible and feature-rich bootloader setup.

### U-Boot: SSBL

#### U-Boot Description
U-Boot is the second-stage bootloader (SSBL) of boot chain for `STM32 Arm® Cortex® MPUs`.

SSBL main features are the following:

* It is configurable and expendable.
* It features a simple command line interface (CLI), allowing users to interact over a serial port console.
* It provides scripting capabilities.
* It loads the kernel into RAM and gives control to the kernel.
* It manages several internal and external devices such as NAND and NOR Flash memories, Ethernet and USB.
* It supports the following features and commands:
    * File systems: FAT, UBI/UBIFS, JFFS
    * IP stack: FTP
    * Display: LCD, HDMI, BMP for splashcreen
    * USB: host (mass storage) or device (DFU stack)

#### U-Boot execution sequence↑
U-Boot executes the following main steps in DDR memory:

* `Pre-relocation initialization` (common/board_f.c): minimal initialization (such as CPU, clock, reset, DDR and console) running at the CONFIG_SYS_TEXT_BASE load address.
* `Relocation`: copy of the code to the end of DDR memory.
* `Post-relocation initialization`:(common/board_r.c): initialization of all the drivers.
* `Command execution` through autoboot (CONFIG_AUTOBOOT) or console shell.
    * Execution of the boot command (by default `bootcmd=CONFIG_BOOTCOMMAND`):
for example, execution of the command `bootm` to:
        * load and check images (such as kernel, device tree and ramdisk)
        * fixup the kernel device tree
        * install the secure monitor (optional) or
        * pass the control to the Linux kernel (or to another target application)

## U-Boot Configuration
The U-Boot binary configuration is based on

* `Kbuild infrastructure` (as in Linux Kernel, you can use `make menuconfig` in U-Boot)
The configurations are based on:
    * options defined in `Kconfig` files (`CONFIG_` compilation flags)
    * the selected configuration file: `configs/stm32mp*_defconfig`
* other compilation flags defined in `include/configs/stm32mp*.h` (these flags are progressively migrated to Kconfig)
The file name is configured through `CONFIG_SYS_CONFIG_NAME`, for example on STMicroelectronics boards:
    * STM32MP13x lines More info.png: `include/configs/stm32mp13_st_common.h`
    * STM32MP15x lines More info.png: `include/configs/stm32mp15_st_common.h`
* `DeviceTree`: U-Boot binaries include a device tree blob that is parsed at runtime

All the configuration flags (prefixed by CONFIG_) are described in the source code, either in the `README` file or in the documentation directory (https://github.com/STMicroelectronics/u-boot/tree/v2022.10-stm32mp/doc/).

For example, CONFIG_SPL activates the SPL compilation.

Hence to compile U-Boot, select the <target> and the device tree for the board in order to choose a predefined configuration.

Refer to #U-Boot_build for examples.

### Kbuild
