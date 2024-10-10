# Standard Class Overview

* Classes are supported by the OS


1. MSC - Mass Storage Class
2. MTP - Multimedia Transfer Protocol
3. CDC Class (Virtual COM Port)
    * used as USB-to-serial bridge
    * often used for data acquisition systems
    * Usually bulk transfer also possible.
4. Human Interface Device (HID) class
    * HID Devices: mouse, keyboard, gaming controllers etc.
    * Interrupt oriented communication
    * HID Specific descriptors
    * Custom HID
5. Device Firmware Update (DFU) class
    * DfuSe extension
    * Downloads new firmware to the device
    * can upload the firmware from the device
6. Audio Class
    * Used for speakers and microphones
    * Real-time audio transfer
        * Uses isochornous transer
7. Composite Device
    * Contains multiple interfaces for different USB classes.
        * all classes can operate at the same time.
        * Possible to use OS system drivers for standard interfaces.
    * e.g. ST-Link can work as a different devices simultaneously.

