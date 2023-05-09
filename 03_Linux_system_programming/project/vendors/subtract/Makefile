#! /bin/bash

subtract: subtract.o vThreadSubtract.o
	gcc -o subtract subtract.o vThreadSubtract.o 

subtract.o: subtract.c headers.h declarations.h
	gcc -c subtract.c -DDEBUG

vThreadSubtract.o: vThreadSubtract.c headers.h declarations.h
	gcc -c vThreadSubtract.c -DDEBUG