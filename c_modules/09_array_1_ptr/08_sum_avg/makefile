sum_avg: main.o get_array.o print_array.o sum_array.o avg_array.o
	gcc -o sum_avg *.o

main.o: main.c headers.h
	gcc -c main.c

get_array.o: get_array.c headers.h 
	gcc -c get_array.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

sum_array.o: sum_array.c headers.h 
	gcc -c sum_array.c

avg_array.o: avg_array.c headers.h 
	gcc -c avg_array.c 

clean:
	rm *.o