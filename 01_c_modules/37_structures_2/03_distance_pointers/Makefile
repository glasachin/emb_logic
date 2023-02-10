#! /bin/bash

convert: main.o headers.h declarations.h constants.h getInput.o display.o convert_dis.o
	gcc -o convert *.o 

main.o: main.c headers.h declarations.h 
	gcc -c main.c -D DEBUG

getInput.o: getInput.c headers.h declarations.h 
	gcc -c getInput.c -D DEBUG

display.o: display.c headers.h declarations.h  
	gcc -c display.c -D DEBUG

convert_dis.o: convert_dis.c headers.h declarations.h 
	gcc -c convert_dis.c -D DEBUG

clean:
	rm *.o