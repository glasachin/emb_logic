
application:	main.o init.o mainMenu.o exitApplication.o openDev.o releaseDev.o
	gcc -o application *.o -lpthread

main.o:	main.c declarations.h headers.h 
	gcc -c main.c

init.o: init.c declarations.h headers.h 
	gcc -c init.c

mainMenu.o: mainMenu.c declarations.h headers.h 
	gcc -c mainMenu.c

exitApplication.o: exitApplication.c declarations.h headers.h 
	gcc -c exitApplication.c

openDev.o: openDev.c declarations.h headers.h 
	gcc -c openDev.c

releaseDev.o: releaseDev.c declarations.h headers.h 
	gcc -c releaseDev.c	

clean: 
	rm *.o 