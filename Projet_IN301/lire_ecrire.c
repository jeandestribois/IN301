#include <stdio.h>
#include <stdlib.h>

#include "mes_types.h"
#include "fonctions_liste.h"
#include "jouer.h"

SLIDER lire_fichier(char *nom)
{
	int x, y, d;
	char chemin_fichier[100];
	printf("nom = %s\n", nom);
	SLIDER S;
	S.mur = NULL;
	FILE *fichier = NULL;
	sprintf(chemin_fichier, "dir_slider/%s", nom);
	fichier = fopen(chemin_fichier, "r");
	if (fichier != NULL)
	{
		fscanf(fichier, "%d %d\n", &S.L, &S.H);
		fscanf(fichier, "%d %d\n", &S.x, &S.y);
		fscanf(fichier, "%d %d\n", &S.xsor, &S.ysor);
		fscanf(fichier, "%d\n", &S.N);
		for (int i = 0; i < S.N; i++)
		{
			fscanf(fichier, "%d %d %d\n", &x, &y, &d);
			S.mur = ajoute_element_fin(S.mur, x, y, d);
		}
		fclose(fichier);
		return S;
	}
	else
	{
		fprintf(stderr,"Impossible d'ouvrir le fichier '%s'\n",nom);
		exit(-1);
	}
}

void jouer_tout_dossier()
{
	char nom[100];
	FILE *fichier;
	fichier=NULL;
	fichier=fopen("dir_slider/dir_slider.slider","r");
	if(fichier!=NULL)
	{
		while(fscanf(fichier,"%s\n",nom) != EOF) jouer_un_niveau(lire_fichier(nom));
		fclose(fichier);
	}
	else
	{
		fprintf(stderr,"Impossible d'ouvrir le fichier dir_slider.slider\n");
		exit(-1);
	}
}

void ecrire_fichier(SLIDER S, char *nom)
{
}
