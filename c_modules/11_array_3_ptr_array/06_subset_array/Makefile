subset: main.o arrays_init.o print_array.o subset_check.o
	gcc -o subset *.o

main.o: main.c headers.h 
	gcc -c main.c 

arrays_init.o: arrays_init.c headers.h 
	gcc -c arrays_init.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

subset_check.o: subset_check.c headers.h 
	gcc -c subset_check.c 

clean:
	rm *.o