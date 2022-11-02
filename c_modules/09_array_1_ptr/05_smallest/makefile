
smallest: main.o get_array.o print_array.o smallest.o
	gcc -o smallest *.o

main.o: main.c headers.h
	gcc -c main.c

get_array.o: get_array.c headers.h
	gcc -c get_array.c

print_array.o: print_array.c headers.h
	gcc -c print_array.c

smallest.o: smallest.c headers.h
	gcc -c smallest.c

clean:
	rm *.o
