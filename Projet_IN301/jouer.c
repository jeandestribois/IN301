#include <uvsqgraphics.h>
#include "mes_types.h"
#include "fonctions_liste.h"

SLIDER deplace_a_gauche(SLIDER S)
{
	LISTE M=S.mur;
	while(M!=NULL)
	{
		if(M->y==S.y && M->x<=S.x && M->d!=MUR_HAUT && M->d!=MUR_BAS)
		{
			if(M->d==MUR_GAUCHE) 
			{
				S.x=M->x;
				return S;
			}
			else if(M->d==MUR_DROITE && M->x!=S.x) 
			{
				S.x=M->x+TAILLE_CASE;
				return S;
			}
		}
		M=M->suiv;
	}
	S.x=0;
	return S;
}

SLIDER deplace_a_droite(SLIDER S)
{
	LISTE M=S.mur;
	while(M!=NULL)
	{
		if(M->y==S.y && M->x>=S.x && M->d!=MUR_HAUT && M->d!=MUR_BAS)
		{
			if(M->d==MUR_DROITE) 
			{
				S.x=M->x;
				return S;
			}
			else if(M->d==MUR_GAUCHE && M->x!=S.x) 
			{
				S.x=M->x-TAILLE_CASE;
				return S;
			}
		}
		M=M->suiv;
	}
	S.x=S.L;
	return S;
}

SLIDER deplace_en_bas(SLIDER S)
{
	LISTE M=S.mur;
	while(M!=NULL)
	{
		if(M->x==S.x && M->x<=S.x && M->d!=MUR_DROITE && M->d!=MUR_GAUCHE)
		{
			if(M->d==MUR_BAS) 
			{
				S.y=M->y;
				return S;
			}
			else if(M->d==MUR_HAUT && M->y!=S.y) 
			{
				S.y=M->y+TAILLE_CASE;
				return S;
			}
		}
		M=M->suiv;
	}
	S.y=0;
	return S;
}

SLIDER deplace_en_haut(SLIDER S)
{
	LISTE M=S.mur;
	while(M!=NULL)
	{
		if(M->x==S.x && M->x>=S.x && M->d!=MUR_DROITE && M->d!=MUR_GAUCHE)
		{
			if(M->d==MUR_HAUT) 
			{
				S.y=M->y;
				return S;
			}
			else if(M->d==MUR_BAS && M->y!=S.y) 
			{
				S.y=M->y-TAILLE_CASE;
				return S;
			}
		}
		M=M->suiv;
	}
	S.y=S.H;
	return S;
}

void est_fleche(int arrow, SLIDER* S, PILE_COUP coup)
{
	coup=ajoute_element_pile(coup,S->x,S->y);
	if(arrow==FLECHE_HAUT) *S=deplace_en_haut(*S);
	else if(arrow==FLECHE_BAS) *S=deplace_en_bas(*S);
	else if(arrow==FLECHE_DROITE) *S=deplace_a_droite(*S);
	else *S=deplace_a_gauche(*S);
}

void est_touche(char key, SLIDER* S, PILE_COUP coup)
{
	if(key=='u')
	{
		if(coup!=NULL)
		{
			S->x=coup->x;
			S->y=coup->y;
			coup=supprime_element_pile(coup);
		}
	 }
}

int gagne(SLIDER S)
{
	return (S.x==S.xsor && S.y==S.ysor);
}

void joue(SLIDER S)
{
	PILE_COUP coup=NULL;
	int a;
	char key;
	int arrow, last_arrow;
	POINT clic;
	while(!gagne(S))
	{
		a=wait_key_arrow_clic(&key,&arrow,&clic);
		if(a!=EST_RIEN)
		{
			if(a==EST_TOUCHE) est_touche(key,&S,coup);
			else if(a==EST_FLECHE && arrow!=last_arrow) est_fleche(arrow,&S,coup);
		}
	}
	
}
