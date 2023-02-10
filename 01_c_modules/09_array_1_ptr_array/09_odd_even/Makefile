odd_even_array: main.o arrays_init.o print_array.o find_odd_even.o
	gcc -o odd_even_array *.o

main.o: main.c headers.h 
	gcc -c main.c 

arrays_init.o: arrays_init.c headers.h 
	gcc -c arrays_init.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

find_odd_even.o: find_odd_even.c headers.h 
	gcc -c find_odd_even.c 

clean:
	rm *.o