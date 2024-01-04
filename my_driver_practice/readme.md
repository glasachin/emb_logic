# Driver Development
In this driver development exercise, I have used modular approach and one file should (but not limited) contain only one function.

## Important information

### Kernel Version and Source Code
In order to build the driver, we need to have the linux kernel source code. On ubuntu, we can get the source code with the distribution itself but this may not be the case with other Linux distributions. 

1. To check the current kernel version: `$uname -r`
2. The source of the current kernel can be found in the following folder by the same name (if present) `/lib/modules/`

We can also download the latest version of the kernel from `https://mirrors.edge.kernel.org/pub/linux/kernel/` and can use the same for build process by providing the path in the `Makefile`.

**Updating Kernel**

We can also update the latest kernel. Instructions for doing the same are given [here](./updaet_latest_kernel.md). 

### Some Basic Commands 

1. `dmesg`
2. `$sudo insmod <file_name>`
3. `$sudo rmmod <file_name>`
4. `$modinfo <file_name>`
5. `lsmod`

## 01_basic_driver
It is based on the notes from internet for writing very basic driver.