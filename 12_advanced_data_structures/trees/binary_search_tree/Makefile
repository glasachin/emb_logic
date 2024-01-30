#! /bin/bash
binFile="binaryTree"
${binFile}: main.o init.o mainMenu.o createTree.o exitFunc.o insertNode.o inOrderTraverse.o preOrderTraverse.o findSmallest.o \
			findLargest.o
	gcc -o ${binFile} *.o

findLargest.o: findLargest.c headers.h structure.h declarations.h 
	gcc -c findLargest.c 

findSmallest.o: findSmallest.c headers.h structure.h declarations.h
	gcc -c findSmallest.c 

preOrderTraverse.o: preOrderTraverse.c headers.h structure.h declarations.h 
	gcc -c preOrderTraverse.c 

inOrderTraverse.o: inOrderTraverse.c headers.h structure.h declarations.h 
	gcc -c inOrderTraverse.c 

insertNode.o: insertNode.c headers.h structure.h declarations.h 
	gcc -c insertNode.c 

exitFunc.o: exitFunc.c headers.h structure.h declarations.h 
	gcc -c exitFunc.c 

createTree.o: createTree.c headers.h structure.h declarations.h
	gcc -c createTree.c 

main.o: main.c headers.h structure.h declarations.h 
	gcc -c main.c 

init.o: init.c headers.h structure.h declarations.h 
	gcc -c init.c 

mainMenu.o: mainMenu.c headers.h structure.h declarations.h 
	gcc -c mainMenu.c

clean:
	rm *.o
	rm ${binFile}