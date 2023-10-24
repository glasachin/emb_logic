/**
 * This file needs to same in application as well as in driver
*/
#ifndef MAGIC
#define MAGIC 'K'
#endif

#ifndef DEVRESET
#define DEVRESET _IO(MAGIC, 0)
#endif

#ifndef GETREGSIZE
#define GETREGSIZE _IOR(MAGIC, 1, int)
#endif

#ifndef GETNOOFREG
#define GETNOOFREG _IOR(MAGIC, 2, int)
#endif

#ifndef GETDEVICESIZE
#define GETDEVICESIZE _IOR(MAGIC, 3, int)
#endif

#ifndef GETDATASIZE
#define GETDATASIZE _IOR(MAGIC, 4, int)
#endif

#ifndef SETREGSIZE
#define SETREGSIZE _IOR(MAGIC, 5, int)
#endif

#ifndef SETNOOFREG
#define SETNOOFREG _IOR(MAGIC, 6, int)
#endif

#ifndef SETDEVICESIZE
#define SETDEVICESIZE _IOR(MAGIC, 7, int)
#endif

#ifndef SETDATASIZE
#define SETDATASIZE _IOR(MAGIC, 8, int)
#endif