#include <uvsqgraphics.h>
#include "mes_types.h"
#include "fonctions_liste.h"
#include "afficher.h"


SLIDER creer_mur(SLIDER S, POINT P)
{
	return S;
}

SLIDER creer_sortie(SLIDER S, POINT P)
{
	S.xsor=P.x/TAILLE_CASE;
	S.ysor=P.y/TAILLE_CASE;
	afficher_sortie(S);
	return S;
}

SLIDER creer_depart(SLIDER S, POINT P)
{
	S.x=P.x/TAILLE_CASE;
	S.y=P.y/TAILLE_CASE;
	afficher_le_slider(S);
	return S;
}

SLIDER creer_niveau(char *largeur, char *hauteur)
{
	SLIDER S;
	S.L=atoi(largeur);		// On transforme les entiers passés en arguments en entiers
	S.H=atoi(hauteur);
	
	int quoi_faire=1;	// Cette variable permet de savoir si on clique pour le départ(1), la sortie(2) ou un mur(3);
	int a;
	char key;
	int arrow;
	POINT clic;
	
	initialiser_affichage(S);
	afficher_instruction();
	wait_key_arrow_clic(&key,&arrow,&clic);
	fill_screen(noir);		// Permet d'effacer le texte avec les instructions
	afficher_grille(S);
	
	while(key!='F')
	{
		a=wait_key_arrow_clic(&key,&arrow,&clic);
		if(a!=EST_RIEN || a!=EST_FLECHE)
		{
			if(a==EST_CLIC)
			{
				if(quoi_faire==1) S=creer_depart(S,clic);
				else if(quoi_faire==2) S=creer_sortie(S,clic);
				else if(quoi_faire==3) S=creer_mur(S,clic);
				if(quoi_faire!=3) quoi_faire++;
			}
		} 
		
	}
	return S;
}
