#ifndef __DECLARATION_H__
#define __DECLARATION_H__

#define DEBUG
#define BDDNAME "BDD6.8"
#define MAJORNO 0

#define NSECTORS 128    // number of sectors
#define HARDSECT_SIZE 1024  // hardware sector size

extern int majorno;
extern int nsectors, hardsect_size;

extern char *blkdev_catalog;

struct blkdev 
{
    struct list_head link;
    sector_t capacity;  /* Device size in sectors */
    u8 *data;           /* The Data in virtual memory */
};

extern struct blkdev *bdev;


#endif