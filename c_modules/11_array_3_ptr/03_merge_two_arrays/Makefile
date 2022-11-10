
merge_array: main.o get_array.o print_array.o merge_arrays.o sort_array.o
	gcc -o merge_array *.o

main.o: main.c headers.h
	gcc -c main.c

get_array.o: get_array.c headers.h 
	gcc -c get_array.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

merge_arrays.o: merge_arrays.c headers.h 
	gcc -c merge_arrays.c

sort_array.o: sort_array.c headers.h 
	gcc -c sort_array.c

clean:
	rm *.o