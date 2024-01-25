# Kernel Build and Update Procedure
Some times we need to update the kernel to the latest one available at `https://kernel.org/ (https://mirrors.edge.kernel.org/pub/)`. There are set of commands to compile the new kernel and then update the system to use the new compiled kernel.

**Know current Kernel Version**

```$uname -r  or $cat /proc/version```

The steps involved in updating the kernel are as follows:

## 1. Get the latest kernel
Download the kernel from `https://mirrors.edge.kernel.org/pub/linux/kernel/v6.x/`

extract the same, UI methor or through commands:
1. tar -xvf <file_name>
2. cd <folder_name>

## 2. Make the configuration file
The configuration file contain lots of variables to help one understand what are the modules we need to compile. We can use `make` command to build the configuration file but it is an interactive command and asks lot of questions.

So, easier way is to copay the existing Linux config file, stored in **/boot/config-...**

```$cp /boot/config-2.6.35.22-generic .config```

we can change/add new configuration settings (if wish) using ```make menuconfig``` or ```make gconfig``` (for this we may need to install **libgtk2.0-dev, libglad2-dev**) or ```make xconfig``` (for this we need **qt-dev** tools)

## 3. Compile the Kernel
There are two ways to compile the kernel
1. Generic way (lots of steps)
2. Debian specific way (sime, use **make-kpkg tool**)

### 3.1: Generic way

**3.1.1: Compile the Kernel and its modules**

```make```

```
Note: in case of error (openssl/opensslv.h: No such file of director), install the same.
$sudo apt-get install openssl-devel
or 
$sudo yum install openssl-devel
```

**3.1.2: Install Kernel Modules**

```make modules_install```

**3.1.3: Install kernel**

```make install```

**3.1.4: Create Initramfs file**

On next boot up we need to choose the latest kernel. So, we need to prepare the boot-loader and its support files. When systerm turns on, after bios and boot loader load the kernel to main memory and mount initial dummy file system as a root file system of system. This initial file system have necessary drivers for disk hardware (SCSI or IDE) and mount the correct file system as a root file system.

so we need to create `initramfs` file using `update-initramfs` or `mkinitfs` tool

```update-initramfs -c -k <kernel-version>```

```
NOTE: if this doesn't work then do the following on Fedora (it depends upon distributin).

dracut -f /boot/initramfs-currentimage

where initramfs-currentimage is replaced with the name of the image we are using currently.
```

**3.1.5: Update GRUB Bootloader**

The last step is to update the boot loader (here we are using GRUB boot-loader)

```update-grub```

This command automatically probe the kernels in `/boot` folder and add the entries in its configuration file, `grub.cfg`

```
NOTE: if this doesn't work then (on fedora),
grub2-mkconfig -o "$(readlink /etc/grub2.conf)"
```

Now, reboot the system and check the kernel version.