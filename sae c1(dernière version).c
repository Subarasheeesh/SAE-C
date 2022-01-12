#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonction.h"
#include "variable.h"
#include <stdbool.h>



int main ()
{
    PERSONNE tab[6000];
    /*Declaration Variable*/
    char line[250];
    int taille =0,i;
    int user;
    int exit =1;
    int suppr;

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


    taille = taille-1;
    while(exit!=3){
        printf("\n-------------- NAVIGATEUR ANNUAIRE --------------\n");
        printf("-------------------------------------------------\n");
        printf("-- 1 -- Rechercher ------------------------------\n");
        printf("-- 2 -- Trier par ordre alphabetique ------------\n");
        printf("-- 3 -- Supprimer -------------------------------\n");
        printf("-- 4 -- Ajouter ---------------------------------\n");
        printf("-- 5 -- recherche manquante ---------------------\n");
        printf("-- 6 -- Quitter ---------------------------------\n");
        printf("-------------------------------------------------\n\n");
        scanf("%d", &user);
        switch(user) {
            case 1 : printf("\n- Recherche -\n");
                    recherche(tab, taille);
                    break;
            case 2 : printf("\n- Trie par ordre alphabetique -\n");
                    break;
            case 3 : printf("\n--------------- SUPPRIMER ----------------\n");
                    printf("- Insert la ligne a supprimer -\n");
                    scanf("%d", &suppr);
                    deleterow(tab, suppr-1 ,&taille);
                    sauvegarder(tab,taille);
                    break;
            case 4 : printf("\n- Ajouter -\n");
                    ajout();
                    break;
            case 5 : printf("\n- Affichage des personne avec des informations manquantes -\n");
                    recherchemanquante(tab,taille);
                    break;
            case 6 : printf("\n- Exit -\n");
                    exit = 3;
                    break;
            default : printf("\n- Erreur -\n");
        }
    }
    fclose (fichier);
    return EXIT_SUCCESS;
}
