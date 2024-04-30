# Block Driver (notes from Class)

block driver creates a `priority queue` first.

sectors in device (HDD or storage) ![](./main-qimg-5d2affa5ac2d66acbd1cfef07f360f24.webp)

## General Algorithm

* Register block device
* Allocate space for dev
* set device parameters ==> size and data
* Initialize Spinlock ==> spin_lock_init(). Try to find the location of the same. `/usr/src/linux-headers-6.5.0-26-generic/include/linux`.
* Initialize request queue


## Schedulers
There are four differnet types of schedulers running on OS.

**for information**

`cd /sys/block/sda/queue`

`cat scheduler` ==> It will give the available scheduler

## register and unregister block driver

`register_blkdev(majorno, DEVNAME);`

`unregister_blkdev(majorno, DEVNAME);`

`cat /proc/devices`

## Struct dev
`SBULL`: Simple block utility for loading localities

The `sbull` device is described by an internal structure:

```
struct Dev 
{
 		int size;						/* Device size in sectors */
 		u8 *data;					/* The data array */
 		short users;					/* How many users */
 		short media_change;		       /* Flag a media change? */
 		spinlock_t lock;			       /* For mutual exclusion */
 		struct request_queue *queue;  /* The device request queue *	/
 		struct gendisk *gd;		       /* The gendisk structure */
 		struct timer_list timer;	               /* For simulated media changes */
}
```

**vmalloc**

* allocating noncontiguous chunks of physical memory. as in OS required continuous memory may not be available.
* `fixing up` the page tables to map the memory into a continuous chunk.

`dev->data = vmalloc(dev->size);`

**spin lock**


**Request Queue**
request from application

requests are represented using struct request. Requests are queued up in the request queue.

* every device has a request queue
* This is because actual transfers to and from a disk can take place far away from the time the kernel requests them.
* A request function, is associated with a request queue when that queue is started

```
struct request_queue
{

}
```

**Initializing Requests Queue**
* 

**The Request Function**

* The block driver request method prototype:
`void request()`
