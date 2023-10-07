used for file position

## for 'lseek'
*loff --> local offset. it stores the local copy of f_ops (kernel variable)

f_pos : it is the data structure in file operations header file.

this '*loff' will not increase automatically in the driver. We need to increment it to represent the lseek variable of file.

## llseek 
add--> llseek:lseek_dev in operations.h

add function in declarations.h: loff_t lseek_dev(struct file*, loff_t, int);

We modify the read file call. we will read using 'lseek' function.
pos = lseek(fd, pos, SEEK_SET); --> seeting the new position

* send seek position in multiples of quantum size as per your driver settings.

in read file of driver we need to start reading from *loff position to make functionality of lseek.