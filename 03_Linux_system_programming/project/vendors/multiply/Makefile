#!/bin/bash

multiply: multiply.o vThreadMultiply.o
	gcc -o multiply multiply.o vThreadMultiply.o 

multiply.o: multiply.c headers.h declarations.h
	gcc -c multiply.c -DDEBUG

vThreadMultiply.o: vThreadMultiply.c headers.h declarations.h
	gcc -c vThreadMultiply.c -DDEBUG