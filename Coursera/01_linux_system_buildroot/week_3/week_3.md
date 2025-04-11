# week 3

## Threads, Multithreading and Synchronization

### Threads and Multithreading

* threads have their own virtualized memory
* Context switching
* Memory savings
* Amdahl's Law

### Synchronization

* critical region: region of code which needs synchronization
* `atomic` operation
    * we need to make the instruction atomic
* mutex
* `Deadlocks`
    * lock data not code
* PThread library
* Detached thread
* Memory Leak
* Pthread mutex
* Scoped locks : uses C++ allocaiton


## Introduction to Buildroot

### Introduction
`Linux Components` with respect to embedded linux

1. toolchain
2. Boot loader
3. Kernel
4. Root filesystem

**Buld Systems**

* buildroot, yocto, openWrt
* or build your own (as we did in previous weeks)


### Buildroot Builds

* config.h

`more is through assignment only`
