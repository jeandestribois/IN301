#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"

// ###############################################
// Fonctions pour manupuler la liste (file) de mur
// ###############################################

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

LISTE libere_memoire_liste(LISTE L)
{
	if(!est_vide(L))
	{
		L->suiv=libere_memoire_liste(L->suiv);
		free(L);
	}
	return NULL;
}

// ###############################################
// Fonctions pour manipuler la pile de coups joués
// ###############################################

PILE_COUP ajoute_element_pile(PILE_COUP P, int x, int y)
{
  PILE_COUP tmp = malloc(sizeof(struct element_coup));
  tmp->x=x;
  tmp->y=y;
  tmp->suiv=P;
  return tmp;
}

PILE_COUP supprime_element_pile(PILE_COUP P){
  if(P!=NULL)
  {
	PILE_COUP PP;
    PP=P;
    P=P->suiv;
    free(PP);
  }
  return P;
}

PILE_COUP libere_memoire_pile(PILE_COUP P)
{
	if(P!=NULL)
	{
		P->suiv=libere_memoire_pile(P->suiv);
		free(P);
	}
	return NULL;
}
