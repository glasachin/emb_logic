#ifndef __DECLARATION_H__
#define __DECLARATION_H__

#define DEBUG
#define BDDNAME "BDD6.8"
#define MAJORNO 0

#define NSECTORS 128    // number of sectors
#define HARDSECT_SIZE 1024  // hardware sector size

extern int majorno;
extern int nsectors, hardsect_size;

struct blkdev 
{
    struct list_head link;
};


extern struct blkdev *bdev;

#endif