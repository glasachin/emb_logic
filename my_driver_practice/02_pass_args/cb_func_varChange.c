/**
 * This is a call back function which will be called whenever variable gets changed from outside
*/
#include"headers.h"
#include"declarations.h"

int notify_param_change(const char *val, const struct kernel_param *kp)
{
    int res = param_set_int(val, kp); // stndard set function from kernel.

    if(res == 0)
    {
        printk(KERN_INFO "%s: Call back function called----\n", __func__);
        printk(KERN_INFO "%s: New value of cb_value is %d\n", cb_value);
        return 0;
    }
    return -1;
}
