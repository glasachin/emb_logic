#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

Item* createScull( size_t lsize )
{
    int no_of_items, size_of_item, i,l,noq;
    Item *first,*itemPtr;
    //Dev *ldev;
    #ifdef DEBUG
    printk(KERN_INFO "Begin:%s\n",__func__);
    #endif
    size_of_item = no_of_reg * size_of_reg;
    no_of_items = lsize / size_of_item;
    if( lsize % size_of_item )
      no_of_items++;
    for( i = 0; i< no_of_items; i++)
    {
      if( i == 0 )
        itemPtr = first = (Item*)kmalloc(sizeof(Item),GFP_KERNEL);
      else
      {
        itemPtr->next = (Item*)kmalloc(sizeof(Item), GFP_KERNEL);
        itemPtr = itemPtr->next;
      }
      if(!itemPtr)
      {
        printk(KERN_ERR "%s: ERROR: kmalloc() failure\n",__func__);
        goto OUT;
      }
      memset(itemPtr,'\0',sizeof(Item));
  }
    itemPtr = first;

    for( i = 0;i< no_of_items; i++)
    {
      itemPtr->data = (void**)kmalloc(sizeof(char*)*no_of_reg, GFP_KERNEL);
      if(!itemPtr->data)
      {
        printk(KERN_ERR "%s: ERROR : kmalloc() failure\n",__func__);
        goto OUT;
      }
      memset(itemPtr->data,'\0',sizeof(char*)*no_of_reg);
      itemPtr = itemPtr->next;
    }
    
    noq = lsize / size_of_reg;
    if( lsize % size_of_reg)
                 noq++;
 
    itemPtr = first;
    for( l = i = 0; l < noq; l++)
        {
                itemPtr->data[i] = kmalloc(size_of_reg, GFP_KERNEL);
                if(!itemPtr->data[i])
                  {
                    printk(KERN_ERR "%s: ERROR: kmalloc() failure.\n",__func__);
                    goto OUT;
                  }
                 if(i == no_of_reg-1)
                 {
                         itemPtr = itemPtr->next;
                         i = 0;
                  }
                else
                  i++;
        }


#ifdef DEBUG
    printk(KERN_INFO "%s:End.\n",__func__);
#endif
    return first;
OUT:
#ifdef DEBUG
    printk(KERN_ERR "%s: ERROR: End.\n",__func__);
#endif
    return 0;
}

