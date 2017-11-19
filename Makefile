all: ploum

run: ploum
	./ploum

plam.o: plam.c
	gcc -c plam.c -Wall

plim.o: plim.c
	gcc -c plim.c -Wall

ploum.o: ploum.c plam.h plim.h
	gcc -c ploum.c -Wall

ploum: plam.o plim.o ploum.o 
	gcc *.o -Wall -o ploum


