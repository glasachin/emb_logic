bankAccount: main.o bank.o
	g++ -o bankAccount *.o

main.o: main.cpp 
	g++ -c main.cpp

bank.o: bank.cpp bank.h
	g++ -c bank.cpp

clean:
	rm *.o

