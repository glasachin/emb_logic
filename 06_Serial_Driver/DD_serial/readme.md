# Serial Driver 

In this we have done the following:

1. intialized the registers for baud rate and other data
2. modified 'writeSerialDevice.c' file to send the characted sent by the application directly.
3. In application we are sending one character at a time.


## Process to test
1. Inster the driver using ```sudo insmod <driver_name.ko>```
2. on another terminal first create the device node using ``` mknod <node_name> c majorno minorno```. Make sure that the node is in the same folder where application is (if we have not provided the specific path)
3. then run the application.

once test is done then
1. unlink the node by ``` unlink <node_name>```
2. remove device ```sudo rmmod <driver_name.ko>```

for debug information of driver use ```dmesg```