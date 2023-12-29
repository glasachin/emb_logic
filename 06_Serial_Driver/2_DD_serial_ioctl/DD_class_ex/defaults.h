#ifndef DEBUG
#define DEBUG
#endif

#ifndef CDDNAME
#define CDDNAME "MySerialDev"
#endif

#ifndef DEVNAME
#define DEVNAME "serialDevice"
#endif

#ifndef DEVSIZE
#define DEVSIZE 96
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif

#ifndef MINORNO
#define MINORNO 0
#endif

#ifndef NOD
#define NOD 1
#endif

// number of registers
#ifndef NOOFREG
#define NOOFREG 12
#endif

#ifndef REGSIZE
#define REGSIZE 1   
#endif

#ifndef DATASIZE
#define  DATASIZE 0
#endif

#ifndef SERIAL_ADDRESS
#define SERIAL_ADDRESS  0x03F8
#endif

#ifndef SERIAL_ADD_LEN
#define SERIAL_ADD_LEN  8
#endif

// Defining registers for serial device according the hardware chip
#ifndef RBR
#define RBR         0x03F8
#endif

#ifndef THR
#define THR         0x03F8
#endif

#ifndef DLL
#define DLL         0x03F8
#endif

#ifndef DLM
#define DLM         0x03F9
#endif

#ifndef IER
#define IER         0x03F9
#endif

#ifndef IIR
#define IIR         0x03FA
#endif

#ifndef FCR
#define FCR         0x03FA
#endif

#ifndef LCR
#define LCR         0x03FB
#endif

#ifndef MCR
#define MCR         0x03FC
#endif

#ifndef LSR
#define LSR         0x03FD
#endif

#ifndef MSR
#define MSR         0x03FE
#endif

#ifndef SCR
#define SCR         0x03FF
#endif