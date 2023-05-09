#!/bin/bash

divide: divide.o vThreadDivide.o
	gcc -o divide divide.o vThreadDivide.o 

divide.o: divide.c headers.h declarations.h
	gcc -c divide.c -DDEBUG

vThreadDivide.o: vThreadDivide.c headers.h declarations.h
	gcc -c vThreadDivide.c -DDEBUG

clean:
	-rm *.o