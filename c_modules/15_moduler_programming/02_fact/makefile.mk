fact: main.o functions.o
	gcc -o fact main.o functions.o
	rm *.o

main.o: main.c functions.h
	gcc -c main.c

functions.o: functions.c functions.h
	gcc -c functions.c

