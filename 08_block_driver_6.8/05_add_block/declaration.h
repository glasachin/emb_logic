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

int init_tag_set(struct blk_mq_tag_set*, void*);
static blk_status_t _queue_rq(struct blk_mq_hw_ctx *, const struct );

static struct blk_mq_ops mq_ops = 
{
    .queue_rq = _queue_rq,
};

struct blkdev
{
    struct list_head link;
    sector_t capacity; /* Device size in sectors */
    u8 *data;          /* The Data in virtual memory */
#ifdef REQUESTS_BASED
    struct blk_mq_tag_set tag_set;
#endif
};

extern struct blkdev *bdev;

struct blkdev *blkdev_add(int, int, char *, sector_t);


#endif