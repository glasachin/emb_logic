reverse: main.o get_array.o print_array.o reverse_array.o
	gcc -o reverse *.o

main.o: main.c headers.h 
	gcc -c main.c

get_array.o: get_array.c headers.h
	gcc -c get_array.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

reverse_array.o: reverse_array.c headers.h 
	gcc -c reverse_array.c

clean:
	rm *.o