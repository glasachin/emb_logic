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

* `SOCK_STREAM`, `SOCK_DGRAM`


