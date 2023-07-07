#!/bin/bash

client: client.o
	gcc -o client client.o

client.o: client.c ../common/headers.h 
	gcc -c client.c 

clean:
	rm -r *.o
