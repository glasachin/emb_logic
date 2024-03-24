# RootFS
Rootfs is the root file system and it contains the everything which is required to run the Linux. These entire files will go into the `root` partition of the SD card. 

There are several points which needs to be remembered.
* `Linux kernel` comilation is different from the `rootfs`.
* compiled image of `linux kernel` goes into the `rootfs`.

Hence, we can divide this task as a following process:

1. Cross compiling the `Linux Kernel`
2. Creating the `rootfs` and putting the compiled kerenel into `rootfs`.

## Cross-Compiling the Linux Kernel
In this case, we are compiling the RPi Linux provided the RPI foundation. For compiling the same we need to install some of the dependencies.

The following instructions are from the RPi official website.

**Required Dependencies**

`sudo apt install git bc bison flex libssl-dev make libc6-dev libncurses5-dev`

**Install the 64-bit toolchain for a 64-bit kernel**

`sudo apt install crossbuild-essential-arm64`

**Download Kerenel**

`git clone --depth=1 https://github.com/raspberrypi/linux`

```
Note: we can checkout the more latest kernel by the following command:
git checkout rpi-5.3.y
or
git clone --depth=1 --branch <branch> https://github.com/raspberrypi/linux
```

### Build Sources
Enter the following commands to build the sources and Device Tree files:

**64-bit configs**

```
cd linux
KERNEL=kernel8
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- bcm2711_defconfig
```

**Build with configs**

To speed up compilation on multiprocessor systems, and get some improvement on single-processor devices, use `-j n`, where `n` is the `number of processors × 1.5`. You can use the nproc command to see how many processors you have.

`make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- Image modules dtbs`

These above mentioned steps compiles the kernel for the target system (i.e. RPi). But this alone is not sufficient to bootup the system. Now, we need to setup the `root file system` for RPi.


## Prepare rootfile system
There are several ways to create the `rootfs` such as
* copy any standard `root base` such as `ubuntu` or `debian`
* we can use `buildroot` to create custom root file system.

Here we are using `ubuntu` root base as demo. Other instructions will be used as required.

### Rootfs Base

#### Ubuntu Based
Note: for first time use this method only.
**download the base**

for ubuntu base

`wget http://cdimage.ubuntu.com/ubuntu-base/releases/18.04/release/ubuntu-base-18.04.1-base-arm64.tar.gz`

Create “rootfs” directory anywhere, and extract root filesystem in it.

`sudo tar xzvf ubuntu-base-18.04.1-base-arm64.tar.gz -C <path to the root>/rootfs`

#### Other debian
use debootstrap to create a minimal Debian-based root file system:

```
sudo apt-get install debootstrap
sudo debootstrap --arch=armhf buster /path/to/rootfs http://deb.debian.org/debian/
```
Replace buster with the desired Debian version (e.g., stretch, bullseye).

Alternatively, you can use a tool like buildroot to create a custom root file system. Follow the buildroot documentation for detailed instructions.

### Installing additional packages
If you need additional packages or tools in your root file system (apt, drivers etc.), you can install them using `chroot`:


**emulator**

Because we are setting up root filesystem for “AARCH64”, we need emulator to execute commands on foreign filesystem. Install “qemu”.

`sudo apt install qemu-user-static`

Then copy this binary into root filesystem.

`sudo cp /usr/bin/qemu-aarch64-static rootfs/usr/bin/`

**mount and bind**

```
sudo mount -o bind /dev /path/to/rootfs/dev
sudo mount -o bind /proc /path/to/rootfs/proc
sudo mount -o bind /sys /path/to/rootfs/sys
```

**apt**

Also, to run “apt” command, you need “resolv.conf” from host PC.

`sudo cp /etc/resolv.conf rootfs/etc/`


**Install Linux Kernel Modules to rootfs**

Now, we will install the Linux Kernel which was build in earlier steps. We will install it in the `rootfs` directory.

`sudo env PATH=$PATH make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- INSTALL_MOD_PATH=<path to root>/rootfs modules_install`

**use chroot to run on host system**

`sudo chroot <path_to_rootfs>/rootfs`

**Crete Users and Install all other**

```
useradd -G sudo -m -s /bin/bash <user name>
passwd <user name>

passwd root
```

Change host name.

```
echo “<host name>” > /etc/hostname
echo "127.0.0.1	localhost" > /etc/hosts
echo "127.0.1.1	<host name>" >> /etc/hosts
```

Update the system in rootfs

```
apt-get update
apt install locales
locale-gen “en_US.UTF-8”
apt upgrade
apt install sudo apt-utils dialog ssh kmod udev perl net-tools ethtool ifupdown dhcpcd5 wireless-tools iputils-ping wpasupplicant vim
```

add this to fstab to avoid mounting root filesystem as `read-only`.

`echo "/dev/sda1	/	ext4	defaults,noatime	0	1" >> <path to root>/rootfs/etc/fstab`

return to host PC

`exit`

**unmount**

```
sudo umount /path/to/rootfs/dev
sudo umount /path/to/rootfs/proc
sudo umount /path/to/rootfs/sys
```




### Copy rootfs folder to SD card root partition

