#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "fonctions_liste.h"
#include "jouer.h"

int main(int argc, char*argv[])
{	
	if(!strcmp(argv[1],"dir_slider")) // Vérifie que la commande tapé sur le terminal est dir_slider
	{
		jouer_tout_dossier();
	}
	
	else if(!strcmp(argv[1],"-c")) // Vérifie que la commande tapé sur le terminal est -c
	{
		
	}
	
	else // Pour jouer à un niveau donné en ligne de commande
	{
		jouer_un_niveau(lire_fichier(argv[1]));
	}
	
	finir_affichage();
	exit(0);
}
