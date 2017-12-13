#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "fonctions_liste.h"
#include "jouer.h"

int main (int argc, char*argv[])
{	
	printf("Debut slider\n");
	
	if(!strcmp(argv[1],"dir_slider"))
	{
		char nom[100];
		FILE *fichier;
		fichier=NULL;
		fichier=fopen("dir_slider/dir_slider.slider","r");
		if(fichier!=NULL)
		{
			while(fscanf(fichier,"%s\n",nom) != EOF) joue(lire_fichier(nom));
		}
		
		fclose(fichier);	
	}
	else
	{
		SLIDER S;
		S=lire_fichier(argv[1]);
		joue(S);
	}

	printf("Fin slider\n");
	
	finir_affichage();
	exit(0);
}
