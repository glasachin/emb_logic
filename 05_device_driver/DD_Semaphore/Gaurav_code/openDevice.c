#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

int openDevice(struct inode *inode, struct file *filep)
{
    Dev *ldev;
    #ifdef DEBUG
    printk(KERN_INFO "Begin:%s\n",__func__);
    #endif

/*int fd =  open(file,O_WRONLY);
if(fd == -1)
{
printk(KERN_ERR, __func__);
}*/
    ldev = container_of(inode->i_cdev,Dev,c_dev);
    if(!ldev)
    {
      printk(KERN_ERR "%s: ERROR: container_of() failed.\n",__func__);
      goto OUT;
    }
    filep->private_data = ldev;
    if((filep->f_flags & O_ACCMODE) == O_WRONLY ) 
          filep->f_pos = 0;
    else if((filep->f_flags & O_ACCMODE) == O_RDONLY ) 
          printk(KERN_INFO "%s: Device opened for reading.\n",__func__);       
   // else if((filep->f_flags & O_ACCMODE) == O_APPEND ) 
         // printk(KERN_INFO "%s: Device opened for appending.\n",__func__);       
    else
    {
      printk(KERN_INFO "%s:Invalid device opened.\n",__func__);
        goto OUT;
    }
          filep->f_pos = 0;

    #ifdef DEBUG
    printk(KERN_INFO "End:%s\n",__func__);
    #endif

    return 0;
OUT:
#ifdef DEBUG
      printk(KERN_ERR "%s: ERROR: End.\n",__func__);
#endif
      return -1;
      }

