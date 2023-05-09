#!/bin/bash

adder: adder.o vThreadAdder.o
	gcc -o adder adder.o vThreadAdder.o 

adder.o: adder.c headers.h declarations.h
	gcc -c adder.c -DDEBUG

vThreadAdder.o: vThreadAdder.c headers.h declarations.h
	gcc -c vThreadAdder.c -DDEBUG

clean:
	-rm *.o