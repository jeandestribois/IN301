#include "graphics.h"
#include "liste.h"
#include "constante.h"


// ############################
// 3. Simulation
// ############################


void simulChaine(){
  Liste l = NULL;
  int i = 0;
  char c;
  POINT p;
  while(i < NB_POINTS){
    p = wait_key_or_clic(&c);
    if(c == 0){//ajoute un point
      l = ajoutDebut(l, p);
      i++;
    }
    else if(c == 'a'){//annule le dernier point
      l = supprimeDebut(l);
      i--;
    }
    else if(c == 'z')
    {
		l = supprimeFin(l);
		i--;
	}
	else if(c == 1)
	{
		decalepoint(l,p);		
	}
	else if(c == t)
	{
		alignepoint(l);
	}
	
    dessineListe(l);
  }
}



