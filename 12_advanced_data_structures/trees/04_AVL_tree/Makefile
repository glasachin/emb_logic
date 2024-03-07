#! /bin/bash

binFile="avlTree"
${binFile}: main.o mainMenu.o init.o createTree.o insertNode.o
	gcc -o ${binFile} *.o

createTree.o: createTree.c headers.h declarations.h structures.h 
	gcc -c createTree.c 

insertNode.o: insertNode.c headers.h declarations.h structures.h 
	gcc -c insertNode.c 

init.o: init.c headers.h declarations.h structures.h 
	gcc -c init.c 

mainMenu.o: mainMenu.c headers.h declarations.h structures.h
	gcc -c mainMenu.c 

main.o: main.c headers.h declarations.h structures.h 
	gcc -c main.c 

clean:
	rm -f *.o 
	rm ${binFile}