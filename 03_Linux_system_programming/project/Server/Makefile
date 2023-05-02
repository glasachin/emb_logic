#! /bin/bash

DF=-DDEBUG

server: server.o init.o processRequest.o createInfra.o exitProgram.o readResult.o
	gcc -o server server.o init.o processRequest.o createInfra.o exitProgram.o readResult.o

readResult.o: readResult.c ../Common/headers.h ../Common/dataStructure.h 
	gcc -c ${DF} readResult.c

server.o: server.c ../Common/headers.h ../Common/dataStructure.h declarations.h
	gcc -c ${DF} server.c

createInfra.o: createInfra.c ../Common/headers.h ../Common/dataStructure.h declarations.h 
	gcc ${DF} -c createInfra.c 

init.o: init.c ../Common/headers.h ../Common/dataStructure.h declarations.h 
	gcc ${DF} -c init.c

processRequest.o: processRequest.c ../Common/headers.h ../Common/dataStructure.h declarations.h 
	gcc ${DF} -c processRequest.c

exitProgram.o: exitProgram.c ../Common/headers.h ../Common/dataStructure.h declarations.h 
	gcc ${DF} -c exitProgram.c 

clean:
	-rm *.o
	-rm server
	-unlink reqFIFO
