#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

ssize_t writeDevice(struct file* filep, const char __user *ubuff, size_t size, loff_t *loff)
{
  Dev *ldev;
  size_t lsize;
  int not,noq,i,l,nocsw,noctw;
  Item *curr;

#ifdef DEBUG
  printk(KERN_INFO "Begin:%s\n",__func__);    
#endif

  if(size == 0)
  {
    printk(KERN_INFO "%s: Nothing to Write\n",__func__);
    goto RET;
  }
  ldev = (Dev*)filep->private_data;
  if(!ldev)
  {
    printk(KERN_ERR "%s: ERROR: Device Not Found for Writing.\n",__func__);
    goto OUT;
  }
  if( size > ldev->size_of_device )
    noctw = lsize = ldev->size_of_device;
  else
    noctw = lsize = size;
  printk(KERN_INFO "%s: size:%ld.\n",__func__,(long)lsize);

  if(down_interruptible(&ldev->sem))
    return -ERESTARTSYS;
  if(ldev->first || ldev->size_of_data == 0)
    trimDevice(ldev);
  curr = ldev->first = createScull(lsize);
  //curr = ldev->first;
  noq = lsize/ldev->size_of_reg;
  if( lsize % ldev->size_of_reg )
    noq++;

  for( nocsw = l = i = 0; l<noq; l++ )
  { 
    if( noctw > ldev->size_of_reg )
      noctw = ldev->size_of_reg;
    not = copy_from_user(curr->data[i], ubuff+nocsw, noctw);
    if(not == -1)
    {
      printk(KERN_ERR "%s:ERROR: copy_from_user() failure.\n",__func__);
      goto OUT;
    }
    nocsw = nocsw + size_of_reg - not;
    noctw = lsize-nocsw;
    if( i == ldev->no_of_reg-1 )
    {
      curr = curr->next;
      i = 0;
    }
    else 
      i++;
  }
  //up(&ldev->sem);
  //ldev->size_of_data = nocsw;
RET:  
  ldev->size_of_data = size_of_data = nocsw;
#ifdef DEBUG
  printk(KERN_INFO "End:%s\n",__func__);
  //up(&ldev->sem);
#endif
  up(&ldev->sem);
  return nocsw;

OUT:
#ifdef DEBUG
  printk(KERN_ERR "%s: ERROR: End.\n",__func__);
  //up(&ldev->sem);
#endif
  up(&ldev->sem);
  return -1;

}

