#!/bin/bash

server: main_server.o processRequest.o
	gcc -o server main_server.o processRequest.o

main_server.o: main_server.c ../common/headers.h
	gcc -c main_server.c

processRequest.o: processRequest.c ../common/headers.h 
	gcc -c processRequest.c

clean:
	rm -r *.o