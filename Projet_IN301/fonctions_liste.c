#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"

// ###############################################
// Fonctions pour manupuler la liste de mur
// ###############################################

LISTE creer_element_liste(int x, int y, int d)
{
    LISTE L=malloc(sizeof(struct elem));
    if(L==NULL)
    {
        fprintf(stderr,"Allocation memoire echouee\n");
        exit(0);
    }
    L->x=x;
    L->y=y;
	L->d=d;
    L->suiv=NULL;
    return L;
}

LISTE ajoute_element_debut_liste(LISTE L, int x, int y, int d)
{
    LISTE Lres;
    Lres=creer_element_liste(x,y,d);
    Lres->suiv=L;
    return Lres;
}

LISTE supprime_element_debut_liste(LISTE L)
{
	if(L!=NULL)
	{
		LISTE LL;
		LL=L;
		L=L->suiv;
		free(LL);
	}
	return L;
}

LISTE libere_memoire_liste(LISTE L)
{
	if(L!=NULL)
	{
		L->suiv=libere_memoire_liste(L->suiv);
		free(L);
	}
	return NULL;
}

// ###############################################
// Fonctions pour manipuler la pile de coups joués
// ###############################################

PILE_COUP creer_elemen_pile(int x, int y)
{
	PILE_COUP P=malloc(sizeof(struct element_coup));
	if(P==NULL)
	{
		fprintf(stderr,"Allocation memoire echouee\n");
		exit(0);
	}
	P->x=x;
	P->y=y;
	P->suiv=NULL;
	return P;
}

PILE_COUP ajoute_element_debut_pile(PILE_COUP P, int x, int y)
{
	PILE_COUP Pres;
	Pres=creer_elemen_pile(x,y);
	Pres->suiv=P;
	return Pres;
}

PILE_COUP supprime_element_debut_pile(PILE_COUP P)
{
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
