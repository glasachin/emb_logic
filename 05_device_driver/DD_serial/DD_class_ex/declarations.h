extern dev_t devid, devno;
extern int majorNo, minorNo, nod;
extern int size_of_device, no_of_reg, size_of_reg, size_of_data;

// it tells the device architecture i.e. number of devices etc.
// we also tells device related info, protocols etc.
typedef struct item
{
    struct item *next;
    void **data;
}Item;

// user defined data structure
// it will describe the hardware device architecture
typedef struct Device 
{
    int MajorNo;
    int MinorNo;
    struct cdev c_dev; // available in cdev header file
    // struct Item *itemptr;
    Item *first;
    int size_of_device;
    int no_of_reg;
    int size_of_reg;
    int size_of_data;
}Dev;

extern Dev *dev;

struct Registers
{
    unsigned char rbr;
    unsigned char thr;
    unsigned char dll;
    unsigned char dlm;
    unsigned char ier;
    unsigned char iir;
    unsigned char fcr;
    unsigned char lcr;
    unsigned char mcr;
    unsigned char lsr;
    unsigned char sci;
    unsigned char msi;
};

struct SerialDev
{
    struct Registers registers;
    struct Dev *dev;
};

extern struct SerialDev *serialdev;

int openDevice(struct inode *, struct file *);
int releaseDevice(struct inode *, struct file *);
ssize_t writeDevice(struct file *filep, const char __user *ubuff, size_t size, loff_t *loff);
ssize_t readDevice(struct file *filep, char __user *ubuff, size_t size, loff_t *loff);
Item* creatScull(size_t);

int set_baud_rate(void);
int initialize_registers(void);