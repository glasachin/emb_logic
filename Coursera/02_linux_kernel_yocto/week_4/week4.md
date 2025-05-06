# Week 4

## Advanced Char Driver Operations

### IOCTL

* Common interface used for device control
    * e.g. lock a door, eject media, report information

* Using `_IO` macros
    * first argument - `Magic` number
    * Second argument - `sequence (command) number`

* `write()` as ioctl alternative.
    * doesn't require a program to implement `echo "start" > /dev/device`


### Sleeping in the kernel

* Never sleep when holding a spinlock, seqlock or RCU lock.
* Never sleep if you have disabled interrupts.
* Avoid sleep/keep durations short while holding a semaphore/mutex.

**simple sleeping**

* `wait_queue`, `wait_event`

* `waking up`


### Kernel sleep continued

* Blocking I/O Buffering

* Task states
    * TASK_RUNNING
    * TASK_INTERRUPTIBLE and TASK_UNINTERRUPTIBLE
* schedule()

* Non-blocking I/O
    * O_NONBLOCK 

### Poll and select

* `poll_wait`

* To ensure transmissions complete to the device, the driver must provide `fsync`

**Seeking on a device**

* `lseek`

* call `nonseekable_open` in open function if seek doesn't make sense for device
    * serial port
    * keyboard

### Assignment: Kernel driver IOCTL implementation

* `f_pos`




