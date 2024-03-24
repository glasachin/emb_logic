# Copy on SD Card

we will copy compiled files and build linux files on SD card.

## Mount Both Partiton of SD Card

```
mkdir ~/sdcard
mkdir ~/sdcard/vfat
mkdir ~/sdcard/root
sudo mount /dev/<partion_fat> ~/sdcard/vfat
sudo mount /dev/<partion_root> ~/sdcard/root
```

## Copy Kernel Image and Device Tree files (in boot folder)

These files are from the `linux` compiled process from official page.s

```
sudo cp arch/arm64/boot/Image mnt/fat32/$KERNEL.img
sudo cp arch/arm64/boot/dts/broadcom/*.dtb mnt/fat32/
sudo cp arch/arm64/boot/dts/overlays/*.dtb* mnt/fat32/overlays/
sudo cp arch/arm64/boot/dts/overlays/README mnt/fat32/overlays/
```

## configure the bootloader
first try without this step. Generally, this step is required if we copy the kernel imange with another file name

```
kernel=kernel.img
device_tree=<device_tree_file>.dtb
```

## Copy the rootfs to sd card
Finally copy the `rootfs` folder content on the `sd card`.

`sudo rsync -av --progress <path to root>/rootfs ~/sdcard/root`

## Unmount SD Card
Now, unmount the SD card

```
sudo umount ~/sdcard/vfat
sudo umount ~/sdcard/root
```

and insert the sd card in RPi and power it up.

