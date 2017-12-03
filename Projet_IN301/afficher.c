#include <uvsqgraphics.h>

#include "mes_types.h"


void initialiser_affichage(SLIDER S)
{
	init_graphics (TAILLE_CASE*S.L,TAILLE_CASE*S.H);
}

void afficher_grille(SLIDER S)
{
	POINT P1, P2;
	P1.y=0, P2.y=TAILLE_CASE*S.H;
	for(int i=0; i<S.L; i++)
	{
		P1.x=i*TAILLE_CASE, P2.x=P1.x;
		draw_line(P1,P2,white);
	}
	P1.x=0, P2.x=TAILLE_CASE*S.L;
	for(int i=0; i<S.H; i++)
	{
		P1.y=i*TAILLE_CASE, P2.y=P1.y;
		draw_line(P1,P2,white);
	}
}

void afficher_murs(SLIDER S) {
}

void afficher_le_slider(SLIDER S) {
}

void afficher_sortie(SLIDER S) {
}


void afficher_slider (SLIDER S) {
	afficher_grille(S);
	afficher_murs(S);
	afficher_le_slider(S);
	afficher_sortie(S);
}


void finir_affichage(SLIDER S) {
	wait_escape();
}
