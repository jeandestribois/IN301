#include <uvsqgraphics.h>
#include "mes_types.h"
#include "fonctions_liste.h"
#include "afficher.h"

SLIDER deplace_a_gauche(SLIDER S)
{
	int x_compare=0;
	LISTE M=S.mur;
	while(M!=NULL)
	{
		if(M->y==S.y && M->x<=S.x && M->d!=MUR_HAUT && M->d!=MUR_BAS)
		{
			if(M->d==MUR_GAUCHE && M->x>x_compare) x_compare=M->x;
			else if(M->d==MUR_DROITE && M->x!=S.x && M->x+1>x_compare) x_compare=M->x+1;
		}
		M=M->suiv;
	}
	S.x=x_compare;
	return S;
}

SLIDER deplace_a_droite(SLIDER S)
{
	int x_compare=S.L-1;
	LISTE M=S.mur;
	while(M!=NULL)
	{
		if(M->y==S.y && M->x>=S.x && M->d!=MUR_HAUT && M->d!=MUR_BAS)
		{
			if(M->d==MUR_DROITE && M->x<x_compare) x_compare=M->x;
			else if(M->d==MUR_GAUCHE && M->x!=S.x && M->x-1<x_compare) x_compare=M->x-1;
		}
		M=M->suiv;
	}
	S.x=x_compare;
	return S;
}

SLIDER deplace_en_bas(SLIDER S)
{
	int y_compare=0;
	LISTE M=S.mur;
	while(M!=NULL)
	{
		if(M->x==S.x && M->y<=S.y && M->d!=MUR_DROITE && M->d!=MUR_GAUCHE)
		{
			if(M->d==MUR_BAS && M->y>y_compare) y_compare=M->y;
			else if(M->d==MUR_HAUT && M->y!=S.y && M->y+1>y_compare) y_compare=M->y+1;
		}
		M=M->suiv;
	}
	S.y=y_compare;
	return S;
}

SLIDER deplace_en_haut(SLIDER S)
{
	int y_compare=S.H-1;
	LISTE M=S.mur;
	while(M!=NULL)
	{
		if(M->x==S.x && M->y>=S.y && M->d!=MUR_DROITE && M->d!=MUR_GAUCHE)
		{
			if(M->d==MUR_HAUT && M->y<y_compare) y_compare=M->y;
			else if(M->d==MUR_BAS && M->y!=S.y && M->y-1<y_compare) y_compare=M->y-1;
		}
		M=M->suiv;
	}
	S.y=y_compare;
	return S;
}

SLIDER est_fleche(int arrow, SLIDER S, PILE_COUP coup)
{
	if(arrow==FLECHE_HAUT) S=deplace_en_haut(S);
	else if(arrow==FLECHE_BAS) S=deplace_en_bas(S);
	else if(arrow==FLECHE_DROITE) S=deplace_a_droite(S);
	else S=deplace_a_gauche(S);
	return S;
}

SLIDER est_touche(char key, SLIDER S, PILE_COUP coup)
{
	if(key=='U')
	{
		if(coup!=NULL)
		{
			S.x=coup->x;
			S.y=coup->y;
		}
	 }
	 return S;
}

int gagne(SLIDER S)
{
	return (S.x==S.xsor && S.y==S.ysor);
}

void jouer_un_niveau(SLIDER S)
{
	PILE_COUP coup=NULL;
	int a;
	char key;
	int arrow, last_arrow;
	last_arrow=1;	//Initialisation à 1 car arrow ne prendra jamais la valeur 1
	POINT clic;
	
	initialiser_affichage(S);
	afficher_jeu(S);
	
	printf("Debut slider\n");
	
	while(!gagne(S))
	{
		a=wait_key_arrow_clic(&key,&arrow,&clic);
		if(a!=EST_RIEN && a!=EST_CLIC)
		{
			if(a==EST_TOUCHE)
			{
				effacer_le_slider(S);
				
				S=est_touche(key,S,coup);
				coup=supprime_element_pile(coup);
	
				afficher_le_slider(S);
				
				last_arrow=1;	//On laisse au joueur la possibilité de faire la même touche car il a effectué un undo
			}
			else if(a==EST_FLECHE && arrow!=last_arrow)
			{
				effacer_le_slider(S);
				
				coup=ajoute_element_pile(coup,S.x,S.y);
				S=est_fleche(arrow,S,coup);
				
				afficher_le_slider(S);
				
				last_arrow=arrow;
			}
		}
	}
	
	printf("Fin slider\n");
}
