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