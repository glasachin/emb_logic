print_duplicates: main.o arrays_init.o print_array.o duplicates.o
	gcc -o print_duplicates *.o

main.o: main.c headers.h 
	gcc -c main.c 

arrays_init.o: arrays_init.c headers.h 
	gcc -c arrays_init.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

duplicates.o: duplicates.c headers.h 
	gcc -c duplicates.c 

clean:
	rm *.o