#! /bin/bash

pq: main.o init.o mainMenu.o exitFunc.o createPQueue.o enQueue.o deQueue.o display.o
	gcc -o pq main.o init.o mainMenu.o exitFunc.o createPQueue.o enQueue.o deQueue.o display.o
 
main.o: main.c headers.h declarations.h structures.h
	gcc -c main.c

init.o: init.c headers.h declarations.h structures.h 
	gcc -c init.c 

mainMenu.o: mainMenu.c headers.h declarations.h structures.h 
	gcc -c mainMenu.c 

exitFunc.o: exitFunc.c headers.h declarations.h structures.h 
	gcc -c exitFunc.c 

createPQueue.o: createPQueue.c headers.h declarations.h structures.h 
	gcc -c createPQueue.c 

enQueue.o: enQueue.c headers.h declarations.h structures.h 
	gcc -c enQueue.c 

deQueue.o: deQueue.c headers.h declarations.h structures.h 
	gcc -c deQueue.c 

display.o: display.c headers.h declarations.h structures.h 
	gcc -c display.c 


clean: 
	rm *.o 

