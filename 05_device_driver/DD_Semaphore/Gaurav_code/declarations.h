extern int majorNo;
extern int minorNo,nod;
extern dev_t devid,devno;
extern int size_of_device,size_of_data, no_of_reg, size_of_reg;

typedef struct item
{
  struct item *next;
  void **data;
}Item;
typedef struct Device
{
  int MajorNo;
  int MinorNo;
  struct cdev c_dev;
  Item *first; //earlier *itemptr
  int size_of_device;
  int no_of_reg;
  int size_of_data;
  int size_of_reg;
  struct semaphore sem;
}Dev;
extern Dev *dev;

int openDevice(struct inode*, struct file*);
int releaseDevice(struct inode*, struct file*);
int trimDevice(Dev*);
ssize_t writeDevice(struct file*, const char __user *, size_t size, loff_t *);
ssize_t readDevice(struct file*, char __user*, size_t size, loff_t*);
Item *createScull(size_t);
