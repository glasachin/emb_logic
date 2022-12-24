CC=gcc 
OF=-o
CF=-c 

encryption: main.o headers.h
	$(CC) $(OF) encryption *.o 

main.o: main.c headers.h
	$(CC) $(CF) main.c 

clean:
	rm *.o