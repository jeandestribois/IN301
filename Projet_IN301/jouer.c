#include <uvsqgraphics.h>
#include "mes_types.h"
#include "fonctions_liste.h"

int mur_en_X(SLIDER S)
{
}

int mur_en_Y(SLIDER S)
{
}

int gagne(SLIDER S)
{
	return (S.x==S.xsor && S.y==S.ysor);
}

void est_touche(char key, SLIDER* S, PILE_COUP* coup)
{
	if(key=='u')
	{
		if(*coup!=NULL)
		{
			*S.x=*coup->x;
			*S.y=*coup->y;
			*coup=supprime_element_pile(*coup);
		}
	 }
}

void est_fleche(int arrow, SLIDER* S, PILE_COUP* coup)
{
	//if(arrow==FLECHE_BAS)
	//{
		
		
}

void joue(SLIDER S)
{
	PILE_COUP coup=NULL;
	int a;
	char key;
	int arrow, last_arrow;
	POINT clic;
	while(!gagne(S))
	{
		a=wait_key_arrow_clic(&key,&arrow,&clic);
		if(a!=EST_RIEN)
		{
			if(a==EST_TOUCHE) est_touche(key,&S,&coup);
			else if(a==EST_FLECHE && arrow!=last_arrow) est_fleche(arrow,&S,&coup);
			
		}
	}
	
}
