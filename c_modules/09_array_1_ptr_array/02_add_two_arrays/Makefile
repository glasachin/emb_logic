add_array: main.o arrays_init.o print_array.o add_array.o
	gcc -o add_array *.o

main.o: main.c headers.h 
	gcc -c main.c 

arrays_init.o: arrays_init.c headers.h 
	gcc -c arrays_init.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

add_array.o: add_array.c headers.h 
	gcc -c add_array.c 

clean:
	rm *.o