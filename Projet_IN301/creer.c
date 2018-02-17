#include <uvsqgraphics.h>
#include "mes_types.h"
#include "fonctions_liste.h"
#include "afficher.h"


SLIDER creer_mur(SLIDER S, POINT P)
{
	int x,y,dh,dv;				// x et y pour la case où on a cliqué, dh pour le coté de la case la plus proche horizontalemnt
	x=P.x/TAILLE_CASE;			// et dy pour la case la plus proche verticalement
	y=P.y/TAILLE_CASE;
	
	if(P.x-x*TAILLE_CASE < TAILLE_CASE/2) dh=9;		// Conditions pour connaître la position du mur
	else dh=3;										// horizontalement et verticalement
	if(P.y-y*TAILLE_CASE < TAILLE_CASE/2) dv=6;
	else dv=0;
	
	if(dh==9 && dv==6)		// Ces  conditions permettent de savoir si on choisi le côté verticale ou horizontale
	{
		if(P.x-x*TAILLE_CASE < P.y-y*TAILLE_CASE) S.mur=ajoute_element_debut_liste(S.mur,x,y,dh);
		else S.mur=ajoute_element_debut_liste(S.mur,x,y,dv);
	}
	else if(dh==9 && dv==0)
	{
		if(P.x-x*TAILLE_CASE < TAILLE_CASE-(P.y-y*TAILLE_CASE)) S.mur=ajoute_element_debut_liste(S.mur,x,y,dh);
		else S.mur=ajoute_element_debut_liste(S.mur,x,y,dv);
	}
	else if(dh==3 && dv==6)
	{
		if(TAILLE_CASE-(P.x-x*TAILLE_CASE) < P.y-y*TAILLE_CASE) S.mur=ajoute_element_debut_liste(S.mur,x,y,dh);
		else S.mur=ajoute_element_debut_liste(S.mur,x,y,dv);
	}
	else 
	{
		if(P.x-x*TAILLE_CASE > P.y-y*TAILLE_CASE) S.mur=ajoute_element_debut_liste(S.mur,x,y,dh);
		else S.mur=ajoute_element_debut_liste(S.mur,x,y,dv);
	}
	
	afficher_murs(S);
	S.N++;
	return S;
}

SLIDER creer_sortie(SLIDER S, POINT P)
{
	S.xsor=P.x/TAILLE_CASE;
	S.ysor=P.y/TAILLE_CASE;
	afficher_effacer_sortie(S,vert);
	return S;
}

SLIDER creer_depart(SLIDER S, POINT P)
{
	S.x=P.x/TAILLE_CASE;
	S.y=P.y/TAILLE_CASE;
	afficher_effacer_le_slider(S,bleu);
	return S;
}

SLIDER creer_niveau(char *largeur, char *hauteur)
{
	SLIDER S;
	S.mur=NULL;
	
	S.L=atoi(largeur);		// On transforme les entiers passés en arguments en entiers
	S.H=atoi(hauteur);
	S.N=0;
	
	int quoi_faire=1;	// Cette variable permet de savoir si on clique pour le départ (1), la sortie (2) ou un mur (3);
	int a;
	char key;
	int arrow;
	POINT clic;
	
	initialiser_affichage(S);
	afficher_instruction();
	wait_key_arrow_clic(&key,&arrow,&clic);
	fill_screen(noir);		// Permet d'effacer le texte avec les instructions
	afficher_grille(S);
	
	while(key!='F')
	{
		affiche_auto_off();
		a=wait_key_arrow_clic(&key,&arrow,&clic);
		if(a!=EST_RIEN || a!=EST_FLECHE)
		{
			if(a==EST_CLIC)
			{
				if(quoi_faire==1) S=creer_depart(S,clic);
				else if(quoi_faire==2) S=creer_sortie(S,clic);
				else if(quoi_faire==3) S=creer_mur(S,clic);
				if(quoi_faire!=3) quoi_faire++;
			}
			else if(a==EST_TOUCHE && key=='U' && quoi_faire!=1)		// Lorsque quoi_faire est égal à 1, rien est affiché et donc il n'y a rien à effacer
			{
				if(quoi_faire==2)
				{
					afficher_effacer_le_slider(S,noir);
					quoi_faire--;
				}
				else if(quoi_faire==3)		// Si il ne reste plus de mur, on efface la case de sortie sinon on efface le dernier mur
				{
					if(S.mur!=NULL)
					{
						S.mur=supprime_element_debut_liste(S.mur);
						fill_screen(noir);
						afficher_jeu(S);
						S.N--;
					}
					else
					{
						afficher_effacer_sortie(S,noir);
						quoi_faire--;
					}
				}
			}
		} 
		affiche_all();	
	}
	affiche_auto_on();
	return S;
}
