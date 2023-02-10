#! /bin/bash
CC=gcc 
OF=-o
CF=-c 

compress: main.o mainMenu.o exitProgram.o compression.o compStats.o deCompression.o deCompStats.o
	$(CC) $(OF) compress *.o 

compStats.o: compStats.c headers.h declarations.h 
	$(CC) $(CF) compStats.c 

deCompression.o: deCompression.c headers.h declarations.h 
	$(CC) $(CF) deCompression.c 

deCompStats.o: deCompStats.c headers.h declarations.h 
	$(CC) $(CF) deCompStats.c

main.o: main.c headers.h declarations.h 
	$(CC) $(CF) main.c 

mainMenu.o: mainMenu.c headers.h declarations.h 
	$(CC) $(CF) mainMenu.c

exitProgram.o: exitProgram.c headers.h declarations.h
	$(CC) $(CF) exitProgram.c 

compression.o: compression.c headers.h declarations.h 
	$(CC) $(CF) compression.c 

clean:
	rm *.o