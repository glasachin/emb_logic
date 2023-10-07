#ifndef DEBUG
#define DEBUG
#endif

#ifndef CDDNAME
#define CDDNAME "MYCDD"
#endif

#ifndef DEVSIZE
#define DEVSIZE 128
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif

#ifndef MINORNO
#define MINORNO 0
#endif

#ifndef NOD
#define NOD 20
#endif

#ifndef NOOFREG
#define NOOFREG 4
#endif
// updated NOOFREG because the data would be larger than NOOFREG*REGSIZE
// ,earlier it was 4 size of data passed would be 8 now it would be 16 which
// will fit properly
#ifndef REGSIZE
#define REGSIZE 4
#endif

#ifndef DATASIZE
#define DATASIZE 0
#endif
