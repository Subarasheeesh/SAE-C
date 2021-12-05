#include <stdio.h>
#include <stdlib.h>



struct personne
{
    char prenom[30];
    char nom[30];
    char ville[30];
    int codep[30];
    char numero[30];
    char email[30];
    char metier[30];
}PERSONNE;


int main ()
{
    /*Declaration Variable*/
    char buffer[250];
    char d[] = ",";
    int i;
    int j;

    /*Ouverture Fichier*/
    FILE *fichier = fopen ("annuaire5000.csv", "r");
    if (fichier == NULL) {
                printf("impossible d'ouvrir le fichier\n");
                return EXIT_FAILURE;
        }

    /*Recuperation Ligne Par Ligne*/
    do{
    fgets(buffer, sizeof(buffer), fichier);
    printf("%s",buffer);

    i=0;
    j=0;
    while(j!=NULL)
    {
        j=buffer[i];

    }


    }
    while(!feof(fichier));

    printf("-------------- NAVIGATEUR ANNUAIRE --------------");




        fclose (fichier);
    return EXIT_SUCCESS;
}
