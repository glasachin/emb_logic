# Week 4

## Time

* wall time
* process time
* monotonic time

* `tick` or `jiffy`
    * `jiffies` counter 64-bit
* `time_t` in `time.h`
* timeval (microsecond resolution), timespec (nano second resolution)

### Sleeping and Timers

* `sleep(5)` : 5 : number of seconds
* `usleep(5)` : for microsecond
* `nanosleep(2)`
* `clock_nanosleep()`
* `sleep` is appropriate for shot (<1 sec) infrequent events.
    * best way is to use timers.


### Timers
 * `alarm`
 * signal reeentrancy limitations. some complications are there with respect to `SIGALRM`

 * `getitimer`, `setitimer`
 * POSIX Timers
    * `timer_create`, `timer_delete`

## Sockets

Another mechanism for IPC

### Sockets

* also known as `BSD` or `Berkeley Sockets`
* Connection oriented Sockets
* Port forwarding
* `port` for local addressing

* `SOCK_STREAM`, 
* `SOCK_DGRAM`
* Socket is used using a `file descriptor`
* domain `PF_INET` or `PF_INET6`
* `sockaddr`
* `socketlen_t`





## Embedded Socket Server

### Linux System Initialization

Basics of writing `init` script files.

* busybox init
    * Default for buildroot projects
* System V init
    * default for Yocto Projects
* systemd
    * More sophisticated startup manager

* Busybox
    * `/etc/init.d/rcS` ==> during startup, S: startup level
    * `/etc/init.d/rcK` ==> during shutdown. 

* `start-stop-daemon`
    * /etc/init.d/S<-mydaemon-> start

### Embedded Debug Strategies

* `GDB`
* `-g` argument to GCC for debug symbols
* `gdb ./<-file-name->`
* Commands
    * r
    * b
    * p
    * n
    * finish
    * info b
    * delete <-x->
    * bt : backtrace



