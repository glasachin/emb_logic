hollow_rhombus: main.o headers.h array_init.o array_print.o
	gcc -o hollow_rhombus *.o

main.o: main.c headers.h 
	gcc -c main.c

array_init.o: array_init.c headers.h 
	gcc -c array_init.c

array_print.o: array_print.c headers.h 
	gcc -c array_print.c

clean: 
	rm *.o