extern dev_t devid;
extern int majorNo, minorNo, nod;

// user defined data structure
// it will describe the hardware device architecture
typedef struct Device 
{
    int MajorNo;
    int MinorNo;
    struct cdev c_dev; // available in cdev header file
}Dev;

extern Dev *dev;
