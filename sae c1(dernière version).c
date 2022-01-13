#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "fonction.h"
#include "variable.h"

int main ()
{
    /*Declaration Variable*/
    PERSONNE tab[6000];
    char line[250];
    int taille =1,i;
    int user;
    int exit =1;
    int suppr;
    float temps;
    clock_t t1, t2;

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

    while(exit!=3){
        printf("\n-------------- NAVIGATEUR ANNUAIRE --------------\n");
        printf("-------------------------------------------------\n");
        printf("-- 0 -- Afficher --------------------------------\n");
        printf("-- 1 -- Rechercher ------------------------------\n");
        printf("-- 2 -- Trier par ordre alphabetique ------------\n");
        printf("-- 3 -- Supprimer -------------------------------\n");
        printf("-- 4 -- Ajouter ---------------------------------\n");
        printf("-- 5 -- Modifier ---------------------------------\n");
        printf("-- 6 -- Recherche manquante ---------------------\n");
        printf("-- 7 -- Sauvegarder -----------------------------\n");
        printf("-- 8 -- Quitter ---------------------------------\n");
        printf("-------------------------------------------------\n\n");
        fflush(stdin);
        scanf("%d", &user);
        switch(user) {
            case 0 :t1 = clock();
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
                    t2 = clock();
                    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
                    printf("\ntemps d'execution = %f\n", temps);
                    break;
            case 1 : printf("\n- Recherche -\n");
                    recherche(tab, taille);
                    break;
            case 2 : printf("\n- Trie par ordre alphabetique -\n");
                    tri_insert(tab,taille);
                    printf("\n- Trie effectuer -\n");
                    break;
            case 3 : printf("\n--------------- SUPPRIMER ----------------\n");
                    printf("- Insert la ligne a supprimer -\n");
                    scanf("%d", &suppr);
                    t1 = clock();
                    supprimer(tab, suppr ,&taille);
                    t2 = clock();
                    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
                    printf("\ntemps d'execution = %f\n", temps);
                    break;
            case 4 : printf("\n- Ajouter -\n");
                    ajout();
                    break;
            case 5 : printf("\n- Modifier -\n");
                    modifier(tab,taille);
                    break;
            case 6 : printf("\n- Affichage des personnes avec des informations manquantes -\n");
                    t1 = clock();
                    recherchemanquante(tab,taille);
                    t2 = clock();
                    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
                    printf("\ntemps d'execution = %f\n", temps);
                    break;
            case 7 : printf("\n- sauvegarder -\n");
                    sauvegarder(tab,taille);
                    break;
            case 8 : printf("\n- Exit -\n");
                    printf("- Les modifications non sauvegarder seront perdu -\n");
                    printf("- etes vous sur ? -\n");
                    printf("- 1 - Oui -\n");
                    printf("- 2 - Non -\n");
                    scanf("%d", &user);
                    if (user==1){
                        exit = 3;
                    }
                    break;
            default : printf("\n- Erreur -\n");
        }
    }
    fclose (fichier);
    return EXIT_SUCCESS;
}
