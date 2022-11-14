merge_arrays: main.o arrays_init.o print_array.o merge_file.o sort_array.o
	gcc -o merge_arrays *.o

main.o: main.c headers.h 
	gcc -c main.c 

arrays_init.o: arrays_init.c headers.h 
	gcc -c arrays_init.c

print_array.o: print_array.c headers.h 
	gcc -c print_array.c

merge_file.o: merge_file.c headers.h
	gcc -c merge_file.c

sort_array.o: sort_array.c headers.h 
	gcc -c sort_array.c


clean:
	rm *.o