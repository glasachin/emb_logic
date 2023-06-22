#!/bin/bash

server: main_server.o
	gcc -o server main_server.o

main_server.o: main_server.c ../common/headers.h
	gcc -c main_server.c

clean:
	rm -r *.o