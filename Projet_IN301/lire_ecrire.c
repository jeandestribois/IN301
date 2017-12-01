#include <stdio.h>
#include "mes_types.h"
#include "fonctions_liste.h"

SLIDER lire_fichier(char *nom) 
{
	int x,y,d;
	printf("nom = %s\n",nom);
	SLIDER S;
	S.mur=NULL;
	FILE *fichier=NULL;
	fichier = fopen(nom, "r");
	if(fichier != NULL)
	{
		fscanf(fichier, "%d %d\n", &S.L, &S.H);
		fscanf(fichier, "%d %d\n", &S.xent, &S.yent);
		fscanf(fichier, "%d %d\n", &S.xsor, &S.yent);
		fscanf(fichier, "%d\n", &S.N);
		for(int i=0; i<S.N; i++)
		{
			fscanf(fichier, "%d %d %d\n", &x, &y, &d);
			S.mur=ajoute_element_fin(S.mur,x,y,d);
		}
		fclose(fichier);
	}
	return S;
}


void ecrire_fichier(SLIDER S, char *nom)
{
}
