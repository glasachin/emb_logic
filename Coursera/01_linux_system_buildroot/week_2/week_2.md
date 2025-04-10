# Week 2
only points, details can be done later

## Linux file I/O
* File descriptor (fd), integer value
    * stdin (fd 0) => input
    * stdout (fd 1) => output
    * stderr (fd 2) => 
* open()
* read()
* write()
* close()
* fopen(), fclose() etc are not system calls
* by default, `write` is into a kernel buffer as disks are slow.
* synchronized I/O
    * several ways to do synchronization
    * fsync(), fdatasync(), O_SYNC => these works based on file descriptors
    * sync() avoid it due to performance reasons, it works globally.
* Positional Read/Write (alternative to `lseek`)
    * pread
    * pwrite
* Sparse Files
    * `ls -lh` => shows human readable format
    * `du -sh` => disk usage, it shows sparse file as well
* Multiplexed I/O
    * select()
    * pselect()
    * poll

**system call logging tool**

* strace

## Process Management

* pid : process ID
    * pid 0: Pne per processor, idle process
    * pid 1: init process
* execl() : executing a program
* execv(), execvp(), execve()
* PATH variable
* fork()
    * creates a new PID for child. Often used to start daemons.
    * zombie process
    * wait() --> to obtain information about terminated child
    * waitpid(), waitid()
* system()    

**processes and Daemons**

* Process should execute with minimum level of rights possible.
* single foreground process group in a session
* &
* `Daemons`: which runs in the background does not connect to a controlling terminal.
    * often ends with `d`
* exit() ==> allows daemon's grandparent (init) to continue
* setsid()
* chdir("/")
* Different Daemon Options ( other than mentioned in the book)


## Basics of Embedded Linux


