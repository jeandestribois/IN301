SLIDER deplace_a_gauche(SLIDER S);

SLIDER deplace_a_droite(SLIDER S);

SLIDER deplace_en_bas(SLIDER S);

SLIDER deplace_en_haut(SLIDER S);

void est_fleche(int arrow, SLIDER* S, PILE_COUP coup);

void est_touche(char key, SLIDER* S, PILE_COUP coup);

int gagne(SLIDER S);

void jouer_un_niveau(SLIDER S);
