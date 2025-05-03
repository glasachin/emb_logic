# Week 3

## Linux Kernel Concurrency

### Concurrency and Race Conditions

* `SMP` (Symmetric multi processing) vs `AMP` (Assymetric multi processing)
* i.e. multiprocessor having single ram

* Sources of concurrency
    * multiple user space processes are running
    * device could disappear while you are trying to access

**AVoid Race Conditions**

* Avoid shared resources


### Kernel Critical Sections

* critical sections/ `atomic`
* Make critical sections `atomic`

* `atomic`: entire operation happens at once as far as threads of execution are concerned (i.e. in a single assembly instruction).

* `semaphores & mutexes` : work with/use sleep
* `spinlocks` : work in all cases (including when we can't sleep)
* It is not safe to sleep in `critical section`
* `kmalloc` may sleep so not good to use in critical section
* `mutex` allowing only 1 process

* `down_trylock()`
* `up()`

### Additional Kernel Locking Options

* `Mutex` in SCULL

* Reader/writer semaphores. Only writer threads need exclusive access.

* `completions`
    * wait for some activity to complete


### More fun with locking

* `spinlocks` : can be used in code which cannot sleep, e.g. `interrupt handlers`
    * higher performance than semaphores

* `irqsave/irqrestore`

* `deadlock` in spinlocks

* Core Rules for Spin Lock
    * Code must be atomic while holding the spinlock.
    * Must be held for `minimum time possible`

* Rules on Lock Ordering

* Alternatives to locking
    * atomic variables and bit operations
    * lock-free algorithms
        * circular buffer with excatly 2 threads and atomic count values
        * read-copy-update

## Kernel Driver Development
Mainly on assignment

### Additional on DEBUG

* compile with `CONFIG_DEBUG_INFO`

* `dynamic probing`
    * replaced by `systemTap`

* Kernel Memory Leaks
    * `kmemleak`

* `bash -x (or sh -x)`

* `strace`


