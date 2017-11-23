#include "graphics.h"
#include "simul.h"


// ############################
// 1. Les structures de données
// ############################


#include "constante.h"

 
// ##########
// 4. Le main
// ##########

int main()
{

  init_graphics(LARGEUR,HAUTEUR);
  affiche_auto_off();
  fill_screen(COUL_FOND);
  affiche_all();

  simulChaine();



  wait_escape();
  return 0;
}
