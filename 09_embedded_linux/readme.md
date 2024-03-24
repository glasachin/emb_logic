# Embedded Linux with ARM

## Bootloaders
* `uboot` related docs can be found [here](./bootloaders/uboot.md)
* `Generic Boot Chain` Overview can be found [here](./bootloaders/bootChainOverview.md)
* Information related to `Device Tree` can be found [here](./bootloaders/deviceTree.md)

## Yocto Project
The Yocto Project is a Linux Foundation collaborative open source project whose goal is to produce tools and processes that enable the creation of Linux distributions for embedded and IoT software that are independent of the underlying architecture of the embedded hardware. It was started by `Linux Foundation` in 2010.

### Introduction

#### Framework Tools Methods
`Yocto Project` is a set of templates, tools and methods that allow to build custom embedded Linux-based systems.3

#### Yocto Project Components
* `bitbake` : handles the building process
* `metadata (Recipes)`: Software bundles, like meta-raspberry
* `Configuration Files`: Machine type

#### The Process
1. Download meta-packages
2. Configure the platform/Machine
3. Building the image with `bitbake`
4. Running the image in an Emulator or put it on the SD card to start it with RPi.

#### Support OS

* Ubuntu

### Creating Customized Embedded Linux Using Yocto

#### Preparing Host computer
It will be needed to cross-compile the Linux for target system.

**Ubntu and Debian Support Packages**

`sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm`

`sudo locale-gen en_US.UTF-8`
`export LC_ALL="en_US.UTF-8"`
`sudo apt-get install lz4`

**Creating a Test Image**

* Test image are not deployed on a target system like the RPi.
* There's a build to run in an Emulator called `Qemu` on the host computer.

**Building an Image**

`Note: Don't move the folder, it may cause un-necessary errors`

repository link: `https://wiki.yoctoproject.org/wiki/Releases`

* `git clone http://git.yoctoproject.org/git/poky` : `poky` is the main project name.
* `cd poky`
* `git checkout -b fido origin/fido` ==> `fido` is current release. we can search for latest. Use latest here.
* `source oe-init-build-env` ==> this will need python depending upon the release
* `bitbake -k core-image-sato`

#### Running the Test Image
goto build folder. by running `sourece oe-init-build-env`. 

`runqemu qemux86` or `runqemu qemux86-64`

There is a difference between default and target image configuration file.

There is two main configuration file inside `./poky/build/conf/`
1. local.conf ==> contains target machine info
2. bblayers.conf 


### Building the basic console image for Raspberry Pi

* `cd poky`
* `git clone -b fido git://git.yoctoproject.org/meta-raspberrypi`
* `ls meta-raspberrypi/recipes-core/images/` => witin the `meta-raspberrypi` layer, we will find three available images.
* `source oe-init-build-env rpi-build`
* `bitbake-layers add-layer $HOME/udemy-yocto/poky/meta-raspberrypi/` --> `rpi-build/conf/bblayers.conf`
* `nano /poky/rpi-build/conf/local.conf` ==> `MACHINE=raspberrypi2 or raspberrypi or raspberrypi3 or other
* `bitbake -k rpi-basic-image`

* `bblayers.conf` file should be modified as per shown in the video

* `local.conf` file ---> go through video or other info to modify the same.

**Image**
Once file is build image can be found:

`~/rpi/rpi-build/tmp/deploy/images/raspberyypi2/rpibasic-image-raspberrypi2.rpi-sdimg`

we need disk image writer for writing the image on SD card.

**Starting the RPi**
with the rpi-basic-image
1. TV, keyboard,ethernet cable to find the IP address
`user: root, no password`
2. Connect via `ssh`

#### Building the QT5 Basic Image




