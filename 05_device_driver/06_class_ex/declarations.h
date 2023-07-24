extern dev_t devid;
extern int majorNo, minorNo, nod;

typedef struct Device 
{
    int MajorNo;
    int MinorNo;
}Dev;

extern Dev *dev;
