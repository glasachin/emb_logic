#! /bin/bash

gTree: main.o init.o mainMenu.o exitFunc.o createTree.o insertNode.o deleteNode.o traverseTree.o
	gcc -o gTree main.o init.o mainMenu.o exitFunc.o createTree.o insertNode.o deleteNode.o traverseTree.o


main.o: main.c headers.h declarations.h structures.h
	gcc -c main.c

init.o: init.c headers.h declarations.h structures.h 
	gcc -c init.c

mainMenu.o: mainMenu.c headers.h declarations.h structures.h 
	gcc -c mainMenu.c

exitFunc.o: exitFunc.c headers.h declarations.h structures.h 
	gcc -c exitFunc.c 

createTree.o: createTree.c headers.h declarations.h structures.h 
	gcc -c createTree.c 

insertNode.o: insertNode.c headers.h declarations.h structures.h 
	gcc -c insertNode.c 

deleteNode.o: deleteNode.c headers.h declarations.h structures.h 
	gcc -c deleteNode.c

traverseTree.o: traverseTree.c headers.h declarations.h structures.h 
	gcc -c traverseTree.c 

clean:
	-rm -f *.o
	-rm gTree