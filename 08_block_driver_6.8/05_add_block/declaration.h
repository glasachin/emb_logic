#ifndef __DECLARATION_H__
#define __DECLARATION_H__

#define DEBUG
#define BDDNAME "BDD6.8"
#define MAJORNO 0
#define MINORNO 0

#define NSECTORS 128       // number of sectors
#define HARDSECT_SIZE 1024 // hardware sector size

extern int majorno;
extern int nsectors, hardsect_size;

extern char *blkdev_catalog;

struct blkdev
{
    struct list_head link;
    sector_t capacity; /* Device size in sectors */
    u8 *data;          /* The Data in virtual memory */
#ifdef CONFIG_SBLKDEV_REQUESTS_BASED
    struct blk_mq_tag_set tag_set;
#endif
};

extern struct blkdev *bdev;

struct blkdev *blkdev_add(int, int, char *, sector_t);

#endif