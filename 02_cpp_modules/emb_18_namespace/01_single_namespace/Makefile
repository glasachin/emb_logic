#! /bin/bash

name: main.o userNamespace.o 
	g++ -o name *.o 

main.o: main.cpp headers.h
	g++ -c main.cpp 

userNamespace.o: userNamespace.cpp headers.h userNamespace.h 
	g++ -c userNamespace.cpp 

clean:
	-rm *.o 
	-rm name