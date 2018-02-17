#include <uvsqgraphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "fonctions_liste.h"
#include "jouer.h"
#include "creer.h"



int est_entier(char* s)		// Vérifie que la chaîne de caractère s est un entier
{
	int i=0;
	if(!isdigit(s[i])) return 0;
	i++;
	while(isdigit(s[i])) i++;
	if(s[i]=='\0') return 1;
	else return 0;
}

void verification_arguments(int argc, char** argv)
{
	if((argc<2) || (!strcmp(argv[1],"-c") && argc<5))
	{
		fprintf(stderr,"Pas assez d'argument passé en ligne de commande\n");
		exit(0);
	}
	if((argc>2 && strcmp(argv[1],"-c")) || (!strcmp(argv[1],"-c") && argc>5))
	{
		fprintf(stderr,"Trop d'argument passé en ligne de commande\n");
		exit(0);
	}
	if(!strcmp(argv[1],"-c"))
	{
		if(!est_entier(argv[2]))
		{
			fprintf(stderr,"%s n'est pas un entier\n",argv[2]);
			exit(0);
		}
		if(!est_entier(argv[3]))
		{
			fprintf(stderr,"%s n'est pas un entier\n",argv[3]);
			exit(0);
		}
	}
}


int main(int argc, char** argv)
{	
	verification_arguments(argc,argv);
	
	if(!strcmp(argv[1],"dir_slider")) // Pour jouer tout les niveaux
	{
		jouer_tout_dossier();
		finir_affichage(2);
	}
	
	else if(!strcmp(argv[1],"-c")) // Pour éditer un niveau
	{
		ecrire_fichier(creer_niveau(argv[2],argv[3]),argv[4]);
		finir_affichage(3);
	}
	
	else // Pour jouer à un niveau donné en ligne de commande
	{
		jouer_un_niveau(lire_fichier(argv[1]));
		finir_affichage(1);
	}
	
	exit(0);
}
