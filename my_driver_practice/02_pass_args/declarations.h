/**
 * This file contain global variables and other parameters
 */
#ifndef __DECLARATIONS_H__
#define __DECLARATIONS_H__

#define NOE 4

extern int value;
extern char *name;
extern int varArray[NOE];
extern int cb_value; // this is callback variable and CB function will invoke if it gets modified externally

int notify_param_change(const char *val, const struct kernel_param *kp);

#endif