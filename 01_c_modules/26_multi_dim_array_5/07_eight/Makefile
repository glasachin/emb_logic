
CC=gcc 
OF=-o
CF=-c

eight: main.o headers.h array_init.o array_print.o
	${CC} ${OF} eight *.o

main.o: main.c headers.h 
	${CC} ${CF} main.c

array_init.o: array_init.c headers.h 
	${CC} ${CF} array_init.c

array_print.o: array_print.c headers.h 
	${CC} ${CF} array_print.c


clean: 
	rm *.o