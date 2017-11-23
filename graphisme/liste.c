#include "graphics.h"
#include "constante.h"


// ############################
// 1. Les structures de données
// ############################


struct element{
  POINT p;
  struct element *suiv;
};
typedef struct element *Liste;


// ############################
// 2. Fonctions listes chainees
// ############################


Liste ajoutDebut(Liste l, POINT p){
  Liste tmp = malloc(sizeof(struct element));
  tmp->p = p;
  tmp->suiv = l;
  return tmp;
}

Liste supprimeDebut(Liste l){
  Liste ll;
  if(l != NULL){
    ll = l;
    l = l->suiv;
    free(ll);
  }
  return l;
}

Liste supprimeFin(Liste l)
{
	Liste ll, lll;
	ll = l;
	if(l != NULL)
	{
		if(l->suiv == NULL)
		{
			free(l);
			return NULL;
		}
		while(l->suiv->suiv != NULL)
		{
			l=l->suiv;
		}
		lll = l->suiv;
		l->suiv = NULL;
		free(lll);
	}
	return ll;
}

void decalepoint(Liste l, POINT p)
{
	if(l != NULL)
	{
		while(l != NULL)
		{
			l->p.x += 5*p.x;
			l->p.y += 5*p.y;
			l = l->suiv;
		}
	}
}

void dessineListeRec(Liste l){
  if(l != NULL){
    draw_fill_circle(l->p, 5, bleu);
    if(l->suiv != NULL)
      draw_line(l->p, l->suiv->p, rouge);
    dessineListeRec(l->suiv);
  }
}

void dessineListe(Liste l){
  fill_screen(COUL_FOND);
  dessineListeRec(l);
  affiche_all();
}
