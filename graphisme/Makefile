all: main clean

run:
	./main
	
main: main.o liste.o simul.o graphics.o 
	gcc `sdl-config --libs` -lSDL_ttf main.o liste.o simul.o graphics.o -o main -Wall -lm
	
main.o: main.c
	gcc `sdl-config --cflags` -c main.c -o main.o -Wall -lm
	
liste.o: liste.c liste.h
	gcc `sdl-config --cflags` -c liste.c -o liste.o -Wall -lm
	
simul.o: simul.c simul.h liste.h
	gcc `sdl-config --cflags` -c simul.c -o simul.o -Wall -lm

#construit le fichier binaire graphics.o
graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	gcc -Wall `sdl-config --cflags`  -c graphics.c

clean:
	rm -rf *.o

mrproper:
	rm -f main
