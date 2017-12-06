#define TAILLE_CASE 50

#define MUR_HAUT 0
#define MUR_DROITE 3
#define MUR_BAS 6
#define MUR_GAUCHE 9

struct elem
{
	int x, y, d;
	struct elem* suiv;
};
typedef struct elem* LISTE; 

struct slider
{
	int L,H; // Largeur et hauteur de la grille
	int x, y;
	int xsor, ysor;
	int N;
	LISTE mur;
};
typedef struct slider SLIDER;

struct element_coup
{
	int x,y;
	struct element_coup* suiv;
};
typedef struct element_coup* PILE_COUP;

