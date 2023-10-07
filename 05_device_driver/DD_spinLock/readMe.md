# Spin Lock

spin lock are generally not used in read-write applicaiton

Don't use spin-lock and semaphore at same place as we can not send the process into sleep mode while using the spin lock.