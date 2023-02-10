
array_sum: main.o get_array.o print_array.o find_sum.o
	gcc -o array_sum *.o

main.o: main.c headers.h
	gcc -c main.c

print_array.o: print_array.c print_array.h
	gcc -c print_array.c

find_sum.o: find_sum.c find_sum.h
	gcc -c find_sum.c

clean:
	rm *.o
	echo "All .o files removed"
