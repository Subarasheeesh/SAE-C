#include <stdio.h>
#include "variable.h"
#include "fonction.h"



PERSONNE stock(char line[250])
{
        char d= ',';
        char buffer[50];
        int i =0;
        int k;
        PERSONNE p;
            i=0;
            k=0;
                /*on contruit le prenom*/
                while(line[i]!=d && line[i]!= '\0')
                {
                    buffer[k] = line[i];
                    k++;
                    i++;
                }
                if (line[i] == d)
                {
                    buffer[k]='\0';
                    strcpy(p.prenom,buffer);
                    k=0;
                    i++;
                }
                /*on contruit le nom*/
                while(line[i]!=d && line[i]!= '\0')
                {
                    buffer[k] = line[i];
                    k++;
                    i++;
                }
                if (line[i] == d)
                {
                    buffer[k]='\0';
                    strcpy(p.nom,buffer);
                    k=0;
                    i++;
                }
                /*on contruit le ville*/
                while(line[i]!=d && line[i]!= '\0')
                {
                    buffer[k] = line[i];
                    k++;
                    i++;
                }
                if (line[i] == d)
                {
                    buffer[k]='\0';
                    strcpy(p.ville,buffer);
                    k=0;
                    i++;
                }
                /*on contruit le codep*/
                while(line[i]!=d && line[i]!= '\0')
                {
                    buffer[k] = line[i];
                    k++;
                    i++;
                }
                if (line[i] == d)
                {
                    buffer[k]='\0';
                    strcpy(p.codep,buffer);
                    k=0;
                    i++;
                }
                /*on contruit le numero*/
                while(line[i]!=d && line[i]!= '\0')
                {
                    buffer[k] = line[i];
                    k++;
                    i++;
                }
                if (line[i] == d)
                {
                    buffer[k]='\0';
                    strcpy(p.numero,buffer);
                    k=0;
                    i++;
                }
                /*on contruit l'email*/
                while(line[i]!=d && line[i]!= '\0')
                {
                    buffer[k] = line[i];
                    k++;
                    i++;
                }
                if (line[i] == d)
                {
                    buffer[k]='\0';
                    strcpy(p.email,buffer);
                    k=0;
                    i++;
                }
                /*on contruit le metier*/
                while(line[i]!= '\0')
                {
                    buffer[k] = line[i];
                    k++;
                    i++;
                }
                buffer[k]='\0';
                strcpy(p.metier,buffer);
        return p;
}

void ajout()
{
    FILE* fichier = fopen("annuaire5000.csv", "a+");

    char prenom[30];
    char nom[30];
    char ville[30];
    char codep[30];
    char numero[30];
    char email[50];
    char metier[30];
    int nb=0;


    if (!fichier) {
        // Erreur lors de l'ouverture du fichier
        printf("Can't open file\n");
        return 0;
    }

    // Demande à l'utilisateur de rentrer toutes les données requises pour l'ajout d'une nouvelle ligne attention pas d'espace
    printf("\nPrenom\n");
    scanf("%s", &prenom);
    printf("\nNom\n");
    scanf("%s", &nom);
    printf("\nVille\n");
    scanf("%s", &ville);
    printf("\nEntrez un numéro de département\n");
    scanf("%s", &codep);
    printf("\nEntrez un numéro de téléphone\n");
    scanf("%s", &numero);
    printf("\nEntrez une adresse mail\n");
    scanf("%s", &email);
    printf("\nEntrez un métier\n");
    scanf("%s", &metier);

    // Met les données saisit dans le tableau
    fprintf(fichier, "%s, %s, %s, %s, %s, %s, %s\n", prenom,
            nom, ville, codep,numero, email, metier);

    printf("\n- Personne ajouter avec succes -\n");

    fclose(fichier);
    return 0;


}

void supprimer()
{
    int psuppr;
    int i=0;

    //Ouverture du fichier
    FILE* fichier = fopen("annuaire5000.csv", "r+");
    //Erreur
    if (!fichier) {
        printf("Can't open file\n");
        return 0;
    }

    printf("\n- saisissez le numero de la personne que vous voulez supprimer -\n");
    scanf("%d", &psuppr);

    printf("\n- La personne %d supprimer avec succes -\n", psuppr);

    fclose(fichier);
    return 0;
}


void recherche()
{
    int user;

    printf("\n----- QUEL EST L'OBJET DE LA RECHERCHE ----------\n");
    printf("-------------------------------------------------\n");
    printf("-- 1 -- Prenom ----------------------------------\n");
    printf("-- 2 -- Nom -------------------------------------\n");
    printf("-- 3 -- Ville -----------------------------------\n");
    printf("-- 4 -- Code Postale ----------------------------\n");
    printf("-- 5 -- Numero De Telephone ---------------------\n");
    printf("-- 6 -- Email -----------------------------------\n");
    printf("-- 7 -- Metier ----------------------------------\n");
    printf("-------------------------------------------------\n");
    printf("-- Autre -- Annuler ---------------------------------\n");
    printf("-------------------------------------------------\n\n");
    scanf("%d", &user);
    switch(user) {
            case 1 : printf("\n- Recherche par Prenom -\n");

                    break;
            case 2 : printf("\n- Recherche par Nom -\n");
                    break;
            case 3 : printf("\n- Recherche par Ville -\n");
                    break;
            case 4 : printf("\n- Recherche par Code Postale -\n");
                    break;
            case 5 : printf("\n- Recherche par Numero De Telephone -\n");
                    break;
            case 6 : printf("\n- Recherche par Email -\n");
                    break;
            case 7 : printf("\n- Recherche par Metier -\n");
                    break;
            default : printf("\n- Annulation -\n");
        }
}
