#! /bin/bash

binFile="avlTree"
${binFile}: main.o mainMenu.o init.o exitFunc.o createNode.o createTree.o insertNode.o
	gcc -o ${binFile} *.o

exitFunc.o: exitFunc.c headers.h declarations.h structures.h 
	gcc -c exitFunc.c 

createTree.o: createTree.c headers.h declarations.h structures.h 
	gcc -c createTree.c 

insertNode.o: insertNode.c headers.h declarations.h structures.h 
	gcc -c insertNode.c 

createNode.o: createNode.c headers.h declarations.h structures.h 
	gcc -c createNode.c 
	
init.o: init.c headers.h declarations.h structures.h 
	gcc -c init.c 

mainMenu.o: mainMenu.c headers.h declarations.h structures.h
	gcc -c mainMenu.c 

main.o: main.c headers.h declarations.h structures.h 
	gcc -c main.c 

clean:
	rm -f *.o 
	rm ${binFile}