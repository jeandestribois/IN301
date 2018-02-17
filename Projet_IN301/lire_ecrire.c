#include <stdio.h>
#include <stdlib.h>

#include "mes_types.h"
#include "fonctions_liste.h"
#include "jouer.h"

SLIDER lire_fichier(char *nom)
{
	int x, y, d;
	char chemin_fichier[100];	// "chemin_fichier" va contenir le chemin nous permettant de trouver les niveau stocké dans un sous dossier
	printf("nom = %s\n",nom);
	SLIDER S;
	S.mur=NULL;
	FILE *fichier=NULL;
	sprintf(chemin_fichier,"dir_slider/%s",nom); 
	fichier=fopen(chemin_fichier,"r");
	if(fichier != NULL)	// On vérifie que le fichier a bien été ouvert
	{
		fscanf(fichier,"%d %d\n",&S.L,&S.H);		// On copie les informations du niveau dans la structure SLIDER
		fscanf(fichier,"%d %d\n",&S.x,&S.y);
		fscanf(fichier,"%d %d\n",&S.xsor,&S.ysor);
		fscanf(fichier,"%d\n",&S.N);
		for(int i=0; i<S.N; i++)
		{
			fscanf(fichier,"%d %d %d\n",&x,&y,&d);
			S.mur = ajoute_element_debut_liste(S.mur,x,y,d);
		}
		fclose(fichier);
		return S;
	}
	else	// Dans le cas où le fichier n'a pas été ouvert
	{
		fprintf(stderr,"Impossible d'ouvrir le fichier '%s'\n",nom);
		exit(0);
	}
}

void jouer_tout_dossier()
{
	char nom[100];
	FILE *fichier;
	fichier=NULL;
	fichier=fopen("dir_slider/dir_slider.slider","r");	// On ouvre le fichier contenant les noms de tout les niveaux
	if(fichier!=NULL)
	{
		while(fscanf(fichier,"%s\n",nom) != EOF) jouer_un_niveau(lire_fichier(nom));	// Tant qu'on ne se trouve pas à la fin du fichier on joue les niveaux 
		fclose(fichier);
	}
	else
	{
		fprintf(stderr,"Impossible d'ouvrir le fichier dir_slider.slider\n");
		exit(0);
	}
}

void ecrire_fichier(SLIDER S, char *nom)		// On effectue la même chose que dans la fonction lire_fichier mais en faisant l'inverse
{
	char chemin_fichier[100];
	FILE *fichier=NULL;
	sprintf(chemin_fichier,"dir_slider/%s",nom);
	fichier=fopen(chemin_fichier,"w");
	if(fichier!=NULL)
	{
		fprintf(fichier,"%d %d\n",S.L,S.H);
		fprintf(fichier,"%d %d\n",S.x,S.y);
		fprintf(fichier,"%d %d\n",S.xsor,S.ysor);
		fprintf(fichier,"%d\n",S.N);
		LISTE mur=S.mur;
		for(int i=0; i<S.N; i++)
		{
			fprintf(fichier,"%d %d %d\n",mur->x,mur->y,mur->d);
			mur=mur->suiv;
		}
		fclose(fichier);

		FILE *fichier_dir=NULL;		// Ici on ecrit dans le fichier dir_slider.slider le nom du nouveau niveau crée
		fichier_dir=fopen("dir_slider/dir_slider.slider","a");
		fprintf(fichier_dir,"%s\n",nom);
	}
	else
	{
		fprintf(stderr,"Impossible de creer le fichier '%s'\n",nom);
		exit(0);
	}
	S.mur=libere_memoire_liste(S.mur);
}
