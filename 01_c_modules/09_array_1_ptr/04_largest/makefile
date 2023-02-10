
largest: main.o get_array.o print_array.o largest.o
	gcc -o largest *.o

main.o: main.c headers.h
	gcc -c main.c

get_array.o: get_array.c headers.h
	gcc -c get_array.c

print_array.o: print_array.c headers.h
	gcc -c print_array.c

largest.o: largest.c headers.h
	gcc -c largest.c

clean:
	rm *.o
