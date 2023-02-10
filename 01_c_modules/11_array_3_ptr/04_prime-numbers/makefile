primes: main.o get_array.o print_array.o find_primes.o sort_array.o
	gcc -o primes *.o

main.o: main.c headers.h
	gcc -c main.c

get_array.o: get_array.c headers.h 
	gcc -c get_array.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

sort_array.o: sort_array.c headers.h 
	gcc -c sort_array.c 

find_primes.o: find_primes.c headers.h 
	gcc -c find_primes.c

clean:
	rm *.o