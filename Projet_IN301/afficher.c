#include <uvsqgraphics.h>
#include "mes_types.h"
#include "fonctions_liste.h"

void initialiser_affichage(SLIDER S)
{
	init_graphics (TAILLE_CASE*S.L+1,TAILLE_CASE*S.H+1); // On rajoute 1 pour faire apparaitre la derniere ligne/colonne de la grille
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
	// On diminue 2 pixel d'un côté et on rajoute 5 pixel 
	// de l'autre pour avoir un mur avec un peu de largeur
	
	POINT P1,P2;
	while(S.mur!=NULL)
	{
		if(S.mur->d==MUR_HAUT)
		{
			P1.x=S.mur->x*TAILLE_CASE, P1.y=S.mur->y*TAILLE_CASE+TAILLE_CASE-2;
			P2.x=P1.x+TAILLE_CASE, P2.y=P1.y+5; 
		}
		else if(S.mur->d==MUR_DROITE) 
		{
			P1.x=S.mur->x*TAILLE_CASE+TAILLE_CASE-2, P1.y= S.mur->y*TAILLE_CASE;
			P2.x=P1.x+5, P2.y=P1.y+TAILLE_CASE;
		}
		else if(S.mur->d==MUR_BAS)
		{
			P1.x=S.mur->x*TAILLE_CASE, P1.y=S.mur->y*TAILLE_CASE-2; 
			P2.x=P1.x+TAILLE_CASE, P2.y=P1.y+5;
		}
		else if(S.mur->d==MUR_GAUCHE)
		{
			P1.x=S.mur->x*TAILLE_CASE-2, P1.y=S.mur->y*TAILLE_CASE;
			P2.x=P1.x+5, P2.y=P1.y+TAILLE_CASE;
		}
		draw_fill_rectangle(P1,P2,yellow);
		S.mur=S.mur->suiv;
	}
}

void afficher_effacer_le_slider(SLIDER S, COULEUR c)
{
	int rayon=2*TAILLE_CASE/5;
	POINT P;
	P.x=S.x*TAILLE_CASE+(TAILLE_CASE/2);
	P.y=S.y*TAILLE_CASE+(TAILLE_CASE/2);
	draw_fill_circle(P,rayon,c);
}

void afficher_effacer_sortie(SLIDER S,COULEUR c)
{
	POINT P1, P2;
	P1.x=S.xsor*TAILLE_CASE+1, P1.y=S.ysor*TAILLE_CASE+1;
	P2.x=S.xsor*TAILLE_CASE+TAILLE_CASE-1, P2.y=S.ysor*TAILLE_CASE+TAILLE_CASE-1;
	draw_fill_rectangle(P1,P2,c);
}


void afficher_jeu(SLIDER S)
{
	afficher_grille(S);
	afficher_effacer_le_slider(S,bleu);
	afficher_effacer_sortie(S,vert);
	afficher_murs(S);
}

void afficher_instruction()
{
	int t=13;
	POINT P;
	P.x=WIDTH/2, P.y=8*HEIGHT/9;
	aff_pol_centre("Bienvenue dans le mode editeur",t,P,beige);
	P.y=7*HEIGHT/9;
	aff_pol_centre("Cliquez sur une case pour creer la case de depart",t,P,beige);
	P.y=6*HEIGHT/9;
	aff_pol_centre("Cliquez ensuite sur une autre pour creer la case de sortie",t,P,beige);
	P.y=5*HEIGHT/9;
	aff_pol_centre("Le reste des cliques vous permettront de creer des murs",t,P,beige);
	P.y=4*HEIGHT/9;
	aff_pol_centre("Vous pouvez annuler une action en appuyant sur la touche U",t,P,beige);
	P.y=3*HEIGHT/9;
	aff_pol_centre("Appuyez sur la touche ESCAPE pour quitter sans enregistrer",t,P,beige);
	P.y=2*HEIGHT/9;
	aff_pol_centre("Appuyez sur la touche F pour quitter et enregistrer",t,P,beige);
	P.y=1*HEIGHT/9;
	aff_pol_centre("Appuyez sur une touche ou cliquez pour commencer",t,P,beige);
}

void finir_affichage(int i)
{
	if(i==1)	// En mode un seul niveau
	{
		POINT P;
		P.x=WIDTH/2, P.y=HEIGHT/2;
		aff_pol_centre("Bravo, vous avez reussi ce niveau",20,P,rouge);
		wait_escape();
	}
	if(i==2)	// En mode tout les niveaux
	{
		POINT P;
		P.x=WIDTH/2, P.y=HEIGHT/2;
		aff_pol_centre("Bravo, vous avez reussi tout les niveaux",20,P,rouge);
		wait_escape();
	}
	if(i==3)	// En mode création d'un niveau
	{
		POINT P;
		P.x=WIDTH/2, P.y=HEIGHT/2;
		aff_pol_centre("Bravo, vous avez cree un nouveau niveau",20,P,rouge);
		wait_escape();
	}
}


























