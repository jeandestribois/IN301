#include <stdio.h>
#include "mes_types.h"


SLIDER lire_fichier(char *nom) 
{

	printf("nom = %s\n",nom);
	SLIDER S;
	FILE fichier = NULL;
	fichier = fopen(nom, "r");
	if(fichier != NULL)
	{
		fscanf(nom, "%d %d\n", &S.L, &S.H);
		fscanf(nom, "%d %d\n", &S.xent, &S.yent);
		fscanf(nom, "%d %d\n", &S.xsor, &S.yent);
		fscanf(nom, "%d\n", &S.N);
		for(int i=0; i<S.N; i+)
		{
			fscanf(nom "%d %d %d\n", &S.mur->x, &S.mur->y, &S.mur->d);
			S.mur=S.mur->suiv;
		}
		fclose(fichier);
	}
	
	return S;
}


void ecrire_fichier(SLIDER S, char*nom)
{
}
