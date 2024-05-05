#ifndef __DECLARATION_H__
#define __DECLARATION_H__

#define DEBUG
#define DEVNAME "BlockDriver"
#define MAJORNO 0

#define NSECTORS 128    // number of sectors
#define HARDSECT_SIZE 1024  // hardware sector size

extern int majorno;
extern int nsectors, hardsect_size;

struct Dev 
{
    int size;
    u8 *data;   // The data array
    short users;
    spinlock_t lock;
    struct request_queue *queue;
};


extern struct Dev *bdev;
void bdev_request(struct request_queue *);

#endif