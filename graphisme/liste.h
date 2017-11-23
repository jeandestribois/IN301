struct element{
  POINT p;
  struct element *suiv;
};
typedef struct element *Liste;


Liste ajoutDebut(Liste l, POINT p);

Liste supprimeFin(Liste l);

Liste supprimeDebut(Liste l);

void dessineListeRec(Liste l);

void dessineListe(Liste l);

void decalepoint(Liste l, POINT p);
