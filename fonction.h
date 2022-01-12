#include "variable.h"

PERSONNE stock(char line[250]);
void ajout();
void supprimer();
void recherche();
void deleterow(PERSONNE personne[], int index, int *nbrow);
void sauvegarder(PERSONNE personne[],int ligne);
void recherchemanquante(PERSONNE personne[],int ligne);
void tri_insert(PERSONNE personne[],int ligne);
