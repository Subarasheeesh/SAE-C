#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonction.h"
#include "variable.h"



int main ()
{
    PERSONNE tab[6000];
    /*Declaration Variable*/
    char line[250];
    int taille =0,i;
    int user;

    /*Ouverture Fichier*/
    FILE *fichier = fopen ("annuaire5000.csv", "r");
    if (fichier == NULL) {
                printf("impossible d'ouvrir le fichier\n");
                return EXIT_FAILURE;
        }

    /*Recuperation Ligne Par Ligne*/
    do
    {
        if (fgets(line, sizeof(line), fichier))
        {
           tab[taille]=stock(line);
           taille++;
        }

    }

    while(!feof(fichier));

    for(i=0;i<taille;i++)

      printf("client %d :\n Prenom: %s\n Nom: %s\n Ville: %s\n Codepostale: %s\n Numero: %s\n Email: %s\n Metier: %s\n",i,tab[i].prenom, tab[i].nom, tab[i].ville, tab[i].codep, tab[i].numero, tab[i].email, tab[i].metier);

    printf("-------------- NAVIGATEUR ANNUAIRE --------------\n");
    printf("-------------------------------------------------\n");
    printf("-- 1 -- Rechercher ------------------------------\n");
    printf("-- 2 -- Trier par ordre alphabetique ------------\n");
    printf("-- 3 -- Supprimer -------------------------------\n");
    printf("-- 4 -- Ajouter ---------------------------------\n");
    printf("-------------------------------------------------\n\n");
    scanf("%d", &user);
    switch(user) {
        case 1 : printf("\n- Recherche -\n");
                break;
        case 2 : printf("\n- Trie par ordre alphabetique -\n");
                break;
        case 3 : printf("\n- Supprimer -\n");
                break;
        case 4 : printf("\n- Ajouter -\n");
                break;
        default : printf("\n- Erreur -\n");
    }
    fclose (fichier);
    return EXIT_SUCCESS;
}
