#include "headers.h"
#include "declaration.h"

int majorno, nsectors, hardsect_size;
struct blkdev *bdev;

char *blkdev_catalog = "blkdev1,1024; blkdev2,2048";

static int __init initialization_func(void)
{
    int ret = 0, len;
    char *catalog, *nextToken, *token;
    #ifdef DEBUG
    printk(KERN_INFO "Begin: %s\n", __func__);
    #endif

    majorno = MAJORNO;
    nsectors = NSECTORS;
    hardsect_size = HARDSECT_SIZE;

    majorno = register_blkdev(majorno, BDDNAME);
    if(majorno <= 0)
    {
        #ifdef DEBUG
        pr_err("%s: Error: register_blkdev() failure.\n", __func__);
        return -EBUSY;
        #endif
        // goto OUT;
    }
    #ifdef DEBUG
    printk(KERN_INFO "Major No: %d\n", majorno);
    printk(KERN_INFO "END: %s\n", __func__);
    #endif

    bdev = kzalloc(sizeof(struct blkdev), GFP_KERNEL);
    if(!bdev)
    {
        ret = -ENOMEM;
        pr_err("%s: Error: Line-%d; kzalloc failure.\n", __func__, __LINE__);
        goto FAIL;
    }

    len = strlen(blkdev_catalog);
    if((len < 1) && (len > PAGE_SIZE))
    {
        pr_err("%s: Error: Line-%d: Invalid Module Parameter. Catalog\n", __func__, __LINE__);
        ret = -EBUSY;
        goto FAIL;
    }

    catalog = kzalloc(len + 1, GFP_KERNEL);
    if(!catalog)
    {
        ret = -ENOMEM;
        pr_err("%s: Error: Line-%d; kzalloc failure.\n", __func__, __LINE__);
        goto FAIL;
    }

    strcpy(catalog, blkdev_catalog);
    nextToken = catalog;

    while((token = strsep(&nextToken, ";")))
    {
        char *name;
        char *capacity;
        sector_t capacity_value;

        name = strsep(&token, ",");
        if(!name)
            continue;
        capacity = strsep(&token, ",");
        if(!capacity)
            continue;
        pr_info("%s; %d; name: %s\n", __func__, __LINE__, name);
        pr_info("%s; %d; cpacity: %s\n", __func__, __LINE__, capacity);
        // if(strncmp(capacity, "1024", 4) == 0)
        //     capacity_value = 1024;
        // else if(strncmp(capacity, "2048", 4) == 0)
        //     capacity_value = 2048;
        // pr_info("%s; %d: Capacity value: %d\n", __func__,__LINE__, capacity_value);

        ret = kstrtoull(capacity, 10, (unsigned long long *)&capacity_value);
        if(ret == -EINVAL)
        {
            pr_info("%s; %d: kstrtoull() Failure, invalid value\n", __func__, __LINE__);
            break;
        }
        if(ret == -ERANGE)
        {
            pr_info("%s; %d: Kstrtoull() Failure, Out of range\n", __func__, __LINE__);
            break;
        }
        pr_info("%s; %d: Kstrtoull() capacity_value: %ld\n", __func__, __LINE__, (long int)capacity_value);

    }

    printk(KERN_INFO "%s: End.\n",__func__);
    return 0;

FAIL:
    #ifdef DEBUG
        pr_err("Error: register_blkdev() failure.");
    #endif
    return ret;
}

module_init(initialization_func);