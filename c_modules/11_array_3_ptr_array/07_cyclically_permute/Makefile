cyclical: main.o arrays_init.o print_array.o cyclical.o
	gcc -o cyclical *.o

main.o: main.c headers.h 
	gcc -c main.c 

arrays_init.o: arrays_init.c headers.h 
	gcc -c arrays_init.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

cyclical.o: cyclical.c headers.h 
	gcc -c cyclical.c 

clean:
	rm *.o