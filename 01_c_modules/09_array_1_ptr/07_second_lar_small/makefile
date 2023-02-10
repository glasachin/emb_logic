sl_sm: main.o get_array.o print_array.o sec_large.o sec_small.o
	gcc -o sl_sm *.o

main.o: main.c headers.h
	gcc -c main.c

get_array.o: get_array.c headers.h 
	gcc -c get_array.c

print_array.o: print_array.c headers.h
	gcc -c print_array.c

sec_large.o: sec_large.c headers.h 
	gcc -c sec_large.c

sec_small.o: sec_small.c headers.h
	gcc -c sec_small.c

clean:
	rm *.o