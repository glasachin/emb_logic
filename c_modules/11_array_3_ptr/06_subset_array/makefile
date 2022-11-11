subset: main.o get_array.o print_array.o check_subset.o
	gcc -o subset *.o

main.o: main.c headers.h
	gcc -c main.c

get_array.o: get_array.c headers.h 
	gcc -c get_array.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

check_subset.o: check_subset.c headers.h 
	gcc -c check_subset.c 

clean:
	rm *.o