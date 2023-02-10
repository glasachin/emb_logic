#! /bin/bash

DF=-DDEBUG

ll: main.o init.o mainMenu.o exitProgram.o createLinkList.o insertNode.o deleteNode.o createNode.o \
	displayLinkList.o sortLinkList.o insertMenu.o insertBeg.o insertEnd.o insertKey.o insertNth.o
	gcc -o ll main.o init.o mainMenu.o exitProgram.o createLinkList.o insertNode.o deleteNode.o \
	createNode.o displayLinkList.o sortLinkList.o insertMenu.o insertBeg.o insertEnd.o insertKey.o \
	insertNth.o


insertNth.o: insertNth.c headers.h structure.h declarations.h 
	gcc ${DF} -c insertNth.c 

insertKey.o: insertKey.c headers.h structure.h declarations.h 
	gcc ${DF} -c insertKey.c 

insertEnd.o: insertEnd.c headers.h structure.h declarations.h 
	gcc ${DF} -c insertEnd.c 

insertBeg.o: insertBeg.c headers.h structure.h declarations.h 
	gcc ${DF} -c insertBeg.c 

insertMenu.o: insertMenu.c headers.h structure.h declarations.h 
	gcc ${DF} -c insertMenu.c

sortLinkList.o: sortLinkList.c headers.h structure.h declarations.h 
	gcc ${DF} -c sortLinkList.c 

displayLinkList.o: displayLinkList.c headers.h structure.h declarations.h 
	gcc ${DF} -c displayLinkList.c

createNode.o: createNode.c headers.h structure.h declarations.h 
	gcc ${DF} -c createNode.c 

deleteNode.o: deleteNode.c headers.h structure.h declarations.h 
	gcc ${DF} -c deleteNode.c 

insertNode.o: insertNode.c headers.h structure.h declarations.h 
	gcc ${DF} -c insertNode.c 

createLinkList.o: createLinkList.c headers.h structure.h declarations.h 
	gcc ${DF} -c createLinkList.c 

exitProgram.o: exitProgram.c headers.h structure.h declarations.h 
	gcc ${DF} -c exitProgram.c

mainMenu.o: mainMenu.c headers.h structure.h declarations.h 
	gcc ${DF} -c mainMenu.c

init.o: init.c headers.h structure.h declarations.h 
	gcc ${DF} -c init.c

main.o: main.c headers.h structure.h declarations.h
	gcc ${DF} -c main.c

clean:
	-rm *.o
	-rm ll