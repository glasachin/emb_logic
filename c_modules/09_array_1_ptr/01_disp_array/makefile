display: main.o get_array.o print_array.o
	gcc -o display *.o

main.o: main.c headers.h
	gcc -c main.c

get_array.o: get_array.c headers.h 
	gcc -c get_array.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

clean:
	rm *.o