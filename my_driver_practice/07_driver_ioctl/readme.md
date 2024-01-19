# IOCTL enabled driver 
input output control (IOCTL) commands are used to perform some device driver related specific tasks such as:

1. changing the baud rate of serial driver
2. Ejecting the cd rom

## Steps of IOCTL
Same `ioctl.h` file should be used in the driver and application code.

1. Creaet `IOCTL` command in the driver
2. Write `IOCTL` function in the driver
3. create `IOCTL` command in a Userspace application
4. Use `IOCTL` system call in userspace.


