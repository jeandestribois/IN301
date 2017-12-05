#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"

// ########################################
// Fonctions pour manupuler la liste (file) de mur
// ########################################

int est_vide(LISTE L)
{
    return L==NULL;
}

LISTE creer_element(int x, int y, int d)
{
    LISTE L=malloc(sizeof(struct elem));
    if(L==NULL)
    {
        printf("\nAllocation mémoire echouée\n");
        exit(EXIT_FAILURE);
    }
    L->x=x;
    L->y=y;
	L->d=d;
    L->suiv=NULL;
    return L;
}

LISTE ajoute_element_fin(LISTE L, int x, int y, int d)
{
    LISTE Lres, L2;
    Lres=creer_element(x,y,d);
    if(est_vide(L))
    {
        return Lres;
    }
    L2=L;
    while(!est_vide(L->suiv))
    {
        L=L->suiv;
    }
    L->suiv=Lres;
    return L2;
}

void afficher_liste(LISTE L)
{
	while(!est_vide(L))
	{
		printf("%d %d %d\n",L->x, L->y, L->d);
		L=L->suiv;
	}
}

LISTE libere_memoire(LISTE L)
{
	if(!est_vide(L))
	{
		L->suiv=libere_memoire(L->suiv);
		free(L);
	}
	return NULL;
}

// ###############################################
// Fonctions pour manipuler la pile de coups joués
// ###############################################

/*Liste ajoute_element_pile(Liste l, POINT p)
{
  Liste tmp = malloc(sizeof(struct element_coup));
  tmp->P = P;
  tmp->suiv = l;
  return tmp;
}*/

PILE_COUP supprime_element_pile(PILE_COUP P){
  PILE_COUP PP;
  if(P!=NULL)
  {
    PP=P;
    P=P->suiv;
    free(PP);
  }
  return P;
}