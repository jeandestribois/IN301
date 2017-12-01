#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"


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

LISTE ajoute_element_debut(LISTE L, int x, int y, int d)
{
    LISTE Lres=creer_element(x,y,d);
    Lres->suiv=L;
    return Lres;
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
		printf("%d %d %d",L->x, L->y, L->d);
		L=L->suiv;
	}
}

LISTE libere_memoire(LISTE L)
{
	if(!est_vide(L))
	{
		L->suiv = libere_memoire(L->suiv);
		free(L);
	}
	return NULL;
}
