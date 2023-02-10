
ar_print: main.o array_in.o
	gcc -o ar_print main.o array_in.o
	rm *.o

main.o: main.c array_in.h
	gcc -c main.c

array_in.o: array_in.c array_in.h
	gcc -c array_in.c

