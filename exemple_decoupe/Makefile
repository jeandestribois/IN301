all: ploum test clean mrproper

test: ploum
	./ploum

ploum: ploum.o plim.o plam.o
	gcc ploum.o plim.o plam.o -o ploum -Wall

ploum.o: ploum.c plim.h plam.h
	gcc -c ploum.c -o ploum.o -Wall

plim.o: plim.c
	gcc -c plim.c -o plim.o -Wall

plam.o: plam.c
	gcc -c plam.c -o plam.o -Wall

clean:
	rm -rf *.o

mrproper:
	rm -f ploum
