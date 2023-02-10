count_duplicate: main.o get_array.o print_array.o count_duplicates.o
	gcc -o count_duplicate *.o

main.o: main.c headers.h
	gcc -c main.c

get_array.o: get_array.c headers.h
	gcc -c get_array.c 

print_array.o: print_array.c headers.h 
	gcc -c print_array.c 

count_duplicates.o: count_duplicates.c headers.h	
	gcc -c count_duplicates.c 

clean:
	rm *.o