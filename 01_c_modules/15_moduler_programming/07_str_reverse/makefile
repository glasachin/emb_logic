
rev_array: main.o get_array.o print_array.o rev_array.o
	gcc -o rev_array *.o

main.o: main.c headers.h
	gcc -c main.c

get_array.o: get_array.c get_array.h
	gcc -c get_array.c

print_array.o: print_array.c print_array.h
	gcc -c print_array.c

rev_array.o: rev_array.c rev_array.h
	gcc -c rev_array.c

clean:
	rm *.o
	
