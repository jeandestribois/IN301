NOM=DESTRIBOIS

test: slider

# Edition de liens

slider: slider.o lire_ecrire.o afficher.o fonctions_liste.o jouer.o creer.o
	gcc slider.o lire_ecrire.o afficher.o fonctions_liste.o jouer.o creer.o -o slider -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

# Compilation

slider.o: slider.c mes_types.h lire_ecrire.h afficher.h fonctions_liste.h jouer.h creer.h
	gcc -c -Wall `sdl-config --cflags` slider.c

lire_ecrire.o: lire_ecrire.c
	gcc -c -Wall lire_ecrire.c

afficher.o: afficher.c
	gcc -c -Wall  `sdl-config --cflags` afficher.c
	
fonctions_liste.o: fonctions_liste.c
	gcc -c -Wall fonctions_liste.c
	
jouer.o: jouer.c
	gcc -c -Wall `sdl-config --cflags` jouer.c

creer.o: creer.c
	gcc -c -Wall `sdl-config --cflags` creer.c

# Edition

editeur:
	subl Makefile mes_types.h slider.c afficher.c afficher.h lire_ecrire.c lire_ecrire.h fonctions_liste.c fonctions_liste.h jouer.c jouer.h creer.c creer.h &

# Zip

zip:
	rm -f $(NOM).zip
	mkdir $(NOM)
	cp *.c $(NOM)
	cp *.h $(NOM)
	cp Makefile $(NOM)
	cp -r dir_slider/ $(NOM)
	cp dir_slider/*.slider $(NOM)/dir_slider
	zip $(NOM)/dir_slider.zip dir_slider/*
	rm -rf $(NOM)/dir_slider/
	zip $(NOM).zip $(NOM)/*
	rm -fr $(NOM)

#Clean

clean:
	rm -rf $(NOM)
	rm -f $(NOM).zip
	rm -f *.o
	rm -f slider
