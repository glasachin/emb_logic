/**
 * This file defines different kernel operation related structures
*/
#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__

const struct kernel_param_ops my_param_ops = 
{
    .set = &notify_param_change, // our set function
    .get = &param_get_int, // standard get
}


#endif