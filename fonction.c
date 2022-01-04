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


    if (!fichier) {
        // Erreur lors de l'ouverture du fichier
        printf("Can't open file\n");
        return 0;
    }


    // Demande à l'utilisateur de rentrer toutes les données requises pour l'ajout d'une nouvelle ligne
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

    printf("\nNouvelle ligne aoutée au tableau !");

    fclose(fichier);
    return 0;


}
