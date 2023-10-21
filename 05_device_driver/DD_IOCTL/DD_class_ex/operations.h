struct file_operations fops=
{
    open:   openDevice,
    release : releaseDevice,
    write:  writeDevice,
    read:   readDevice,
    llseek: lseek_dev,
    unlocked_ioctl:ioctl_dev
};