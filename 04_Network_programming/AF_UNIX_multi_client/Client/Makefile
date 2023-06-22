#!/bin/bash

client: main_client.o
	gcc -o client main_client.o

main_client.o: main_client.c ../common/headers.h 
	gcc -c main_client.c 

clean:
	rm -r *.o
