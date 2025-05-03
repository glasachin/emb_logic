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


