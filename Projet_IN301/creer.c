#include <uvsqgraphics.h>
#include "mes_types.h"
#include "fonctions_liste.h"
#include "afficher.h"

SLIDER creer_niveau(char *largeur, char *hauteur)
{
	SLIDER S;
	S.L=atoi(largeur);
	S.H=atoi(hauteur);
	
	initialiser_affichage(S);
	afficher_grille(S);
	
	return S;
}
