#ifndef __DECLARATIONS_H__
#define __DECLARATIONS_H__

extern int nod;
extern dev_t devId; // it contains the Major and Minor Number of driver
extern struct class devClass;
extern struct cdev *dev;

extern uint8_t *kbuff;


#endif