
exp1: main.o members.o
	g++ -o exp1 *.o

main.o: main.cpp class.h headers.h 
	g++ -c main.cpp 

members.o: members.cpp class.h headers.h 
	g++ -c members.cpp 


clean:
	- rm *.o
	- rm exp1
