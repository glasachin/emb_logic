#! /bin/bash

dis_convert: main.o functions.o 
	gcc -o dis_convert *.o

main.o: main.c headers.h declarations.h 
	gcc -c main.c

functions.o: functions.c headers.h declarations.h
	gcc -c functions.c 

clean:
	rm *.o