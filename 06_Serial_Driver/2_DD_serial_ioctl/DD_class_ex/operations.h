struct file_operations fops=
{
    open:openSerialDevice,
    release : releaseSerialDevice,
    write:  writeSerialDevice,
    read:   readSerialDevice
};