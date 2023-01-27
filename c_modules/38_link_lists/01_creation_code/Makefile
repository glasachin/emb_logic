#! /bin/bash

DF=-DDEBUG

ll: main.o init.o mainMenu.o exitProgram.o createLinkList.o insertNode.o deleteNode.o createNode.o
	gcc -o ll main.o init.o mainMenu.o exitProgram.o createLinkList.o insertNode.o deleteNode.o \
	createNode.o

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