#define TAILLE_CASE 50

struct elem
{
	int x, y, d;
	struct elem* suiv;
};
typedef struct elem* LISTE; 

struct slider
{
	int L,H; // Largeur et hauteur de la grille
	int xent, yent;
	int xsor, ysor;
	int N;
	LISTE mur;
};
typedef struct slider SLIDER;
