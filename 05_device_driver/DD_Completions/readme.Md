# Completions

In this We have modified the driver to test the synchronization technique in the driver.

<!-- Completions are implemented after semaphores -->
apply semaphore in the write and the use complete function.
in read, only wait_for_completeion function.
<!--  -->
In this example completion is implemented on read_device

Steps will be as follows:

1. Create driver and install the device.
2. Create application to read and write the device (as done for driver)
3. Run multiple read applications in different windows (run 3 applications)
4. Run write Device application in different window.(run 3 one by one). On every one write, one read will close.
5. read processes will keep closing one by one after each write call. 