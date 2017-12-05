#include <uvsqgraphics.h>
#include "mes_types.h"
#include "fonctions_liste.h"

void initialiser_affichage(SLIDER S)
{
	init_graphics (TAILLE_CASE*S.L+1,TAILLE_CASE*S.H+1);
}

void afficher_grille(SLIDER S)
{
	int i;
	POINT P1, P2;
	P1.y=0, P2.y=HEIGHT;
	for(i=0; i<=S.L; i++)
	{
		P1.x=i*TAILLE_CASE, P2.x=P1.x;
		draw_line(P1,P2,white);
	}
	P1.x=0, P2.x=WIDTH;
	for(i=0; i<=S.H; i++)
	{
		P1.y=i*TAILLE_CASE, P2.y=P1.y;
		draw_line(P1,P2,white);
	}
}

void afficher_murs(SLIDER S)
{
	POINT P1, P2;
	while(!est_vide(S.mur))
	{
		if(S.mur->d==0)
		{
			P1.x=S.mur->x*TAILLE_CASE, P1.y=S.mur->y*TAILLE_CASE+TAILLE_CASE-2; 
			P2.x=P1.x+TAILLE_CASE, P2.y=P1.y+5; 
		}
		else if(S.mur->d==3) 
		{
			P1.x=S.mur->x*TAILLE_CASE+TAILLE_CASE-2, P1.y= S.mur->y*TAILLE_CASE;
			P2.x=P1.x+5, P2.y=P1.y+TAILLE_CASE;
		}
		else if(S.mur->d==6)
		{
			P1.x=S.mur->x*TAILLE_CASE, P1.y=S.mur->y*TAILLE_CASE-2; 
			P2.x=P1.x+TAILLE_CASE, P2.y=P1.y+5;
		}
		else
		{
			P1.x=S.mur->x*TAILLE_CASE-2, P1.y=S.mur->y*TAILLE_CASE;
			P2.x=P1.x+5, P2.y=P1.y+TAILLE_CASE;
		}
		draw_fill_rectangle(P1,P2,yellow);
		S.mur=S.mur->suiv;
	}
}

void afficher_le_slider(SLIDER S)
{
	int rayon=2*TAILLE_CASE/5;
	POINT P;
	P.x=S.x*TAILLE_CASE+(TAILLE_CASE/2);
	P.y=S.y*TAILLE_CASE+(TAILLE_CASE/2);
	draw_fill_circle(P,rayon,blue);
}

void afficher_sortie(SLIDER S)
{
	POINT P1, P2;
	P1.x=S.xsor*TAILLE_CASE+1, P1.y=S.ysor*TAILLE_CASE+1;
	P2.x=S.xsor*TAILLE_CASE+TAILLE_CASE-1, P2.y=S.ysor*TAILLE_CASE+TAILLE_CASE-1;
	draw_fill_rectangle(P1,P2,green);
}


void afficher_slider (SLIDER S) {
	afficher_grille(S);
	afficher_murs(S);
	afficher_le_slider(S);
	afficher_sortie(S);
}


void finir_affichage(SLIDER S)
{
	wait_escape();
}
