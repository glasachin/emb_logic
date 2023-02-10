prime: main.o arrays_init.o print_array.o prime_array.o sort_array.o
	gcc -o prime *.o

main.o: main.c headers.h 
	gcc -c main.c 

arrays_init.o: arrays_init.c headers.h 
	gcc -c arrays_init.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

prime_array.o: prime_array.c headers.h
	gcc -c prime_array.c

sort_array.o: sort_array.c headers.h 
	gcc -c sort_array.c


clean:
	rm *.o