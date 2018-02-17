#define TAILLE_CASE 50

#define MUR_HAUT 0
#define MUR_DROITE 3
#define MUR_BAS 6
#define MUR_GAUCHE 9

struct elem			// Liste chaînée contenant les informations de tout les murs
{
	int x, y, d;
	struct elem* suiv;
};
typedef struct elem* LISTE; 

struct slider		// Structure contenant toute les informations d'un niveau
{
	int L,H;
	int x, y;
	int xsor, ysor;
	int N;
	LISTE mur;
};
typedef struct slider SLIDER;

struct element_coup		// Liste chainée contenant les coup joués par l'utilisateur
{
	int x,y;
	struct element_coup* suiv;
};
typedef struct element_coup* PILE_COUP;

