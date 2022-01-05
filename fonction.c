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
    fprintf(fichier, "%s,%s,%s,%s,%s,%s,%s",prenom,nom,ville,codep,numero,email,metier);

    printf("\n- Personne ajouter avec succes -\n");

    fclose(fichier);
    return 0;


}

void supprimer(int taille)
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
    printf("------------------------------------------\n");
    printf("------- Assurez vous de connaitre --------\n");
    printf("-- le numero de la personne a supprimer --\n");
    printf("------------------------------------------\n");
    printf("--- saisissez le numero de la personne ---\n");
    printf("-------- que vous voulez supprimer -------\n");
    printf("-------- Ou entrez 0 pour annuler --------\n");
    printf("------------------------------------------\n\n");
    scanf("%d", &psuppr);
    if(psuppr!=0){
        printf("\n- La personne %d supprimer avec succes -\n", psuppr);
    }
    else{
        printf("\n- Annulation -\n");
    }
    fclose(fichier);
    return 0;
}


void recherche(PERSONNE tab[6000], int taille)
{
    int user;
    char search[30];
    int i=0;

    printf("\n----- QUEL EST L'OBJET DE LA RECHERCHE ----------\n");
    printf("-------------------------------------------------\n");
    printf("-- 0 -- Peut importe ----------------------------\n");
    printf("-- 1 -- Prenom ----------------------------------\n");
    printf("-- 2 -- Nom -------------------------------------\n");
    printf("-- 3 -- Ville -----------------------------------\n");
    printf("-- 4 -- Code Postale ----------------------------\n");
    printf("-- 5 -- Numero De Telephone ---------------------\n");
    printf("-- 6 -- Email -----------------------------------\n");
    printf("-- 7 -- Metier ----------------------------------\n");
    printf("-------------------------------------------------\n");
    printf("-- Autre -- Annuler -----------------------------\n");
    printf("-------------------------------------------------\n\n");
    scanf("%d", &user);
    switch(user) {
            case 0 :
                printf("\n- Recherche -\n");
                printf("\n- Entrez votre recherche (Pensez a la majuscule si il y en a une) -\n");
                scanf("%s", &search);
                printf("\n");
                do {
                    //debogage vvv
                    //printf("!---- %s %s %i ----!\n", search, tab[i].prenom, strcmp(search,tab[i].prenom));
                    if(strcmp(search,tab[i].prenom)==0 || strcmp(search,tab[i].nom)==0 || strcmp(search,tab[i].ville)==0 || strcmp(search,tab[i].codep)==0 || strcmp(search,tab[i].numero)==0 || strcmp(search,tab[i].email)==0 || strcmp(search,tab[i].metier)==0){
                        printf("client %d :\n Prenom: %s\n Nom: %s\n Ville: %s\n Codepostal: %s\n Numero: %s\n Email: %s\n Metier: %s\n",i,tab[i].prenom, tab[i].nom, tab[i].ville, tab[i].codep, tab[i].numero, tab[i].email, tab[i].metier);
                    }
                    i++;
                }
                while (i<taille);
                break;
            case 1 :
                printf("\n- Recherche par Prenom -\n");
                printf("\n- Entrez votre recherche (Pensez a la majuscule) -\n");
                scanf("%s", &search);
                printf("\n");
                do {
                    //debogage vvv
                    //printf("!---- %s %s %i ----!\n", search, tab[i].prenom, strcmp(search,tab[i].prenom));
                    if(strcmp(search,tab[i].prenom)==0){
                        printf("client %d :\n Prenom: %s\n Nom: %s\n Ville: %s\n Codepostal: %s\n Numero: %s\n Email: %s\n Metier: %s\n",i,tab[i].prenom, tab[i].nom, tab[i].ville, tab[i].codep, tab[i].numero, tab[i].email, tab[i].metier);
                    }
                    i++;
                }
                while (i<taille);
                break;
            case 2 : printf("\n- Recherche par Nom -\n");
                    printf("\n- Entrez votre recherche (Pensez a la majuscule) -\n");
                    scanf("%s", &search);
                    printf("\n");
                    do {
                        //debogage vvv
                        //printf("!---- %s %s %i ----!\n", search, tab[i].nom, strcmp(search,tab[i].nom));
                        if(strcmp(search,tab[i].nom)==0){
                            printf("client %d :\n Prenom: %s\n Nom: %s\n Ville: %s\n Codepostal: %s\n Numero: %s\n Email: %s\n Metier: %s\n",i,tab[i].prenom, tab[i].nom, tab[i].ville, tab[i].codep, tab[i].numero, tab[i].email, tab[i].metier);
                        }
                        i++;
                    }
                    while (i<taille);
                    break;
            case 3 : printf("\n- Recherche par Ville -\n");
                    printf("\n- Entrez votre recherche (En majuscule) -\n");
                    scanf("%s", &search);
                    printf("\n");
                    do {
                        //debogage vvv
                        //printf("!---- %s %s %i ----!\n", search, tab[i].ville, strcmp(search,tab[i].ville));
                        if(strcmp(search,tab[i].ville)==0){
                            printf("client %d :\n Prenom: %s\n Nom: %s\n Ville: %s\n Codepostal: %s\n Numero: %s\n Email: %s\n Metier: %s\n",i,tab[i].prenom, tab[i].nom, tab[i].ville, tab[i].codep, tab[i].numero, tab[i].email, tab[i].metier);
                        }
                        i++;
                    }
                    while (i<taille);
                    break;
            case 4 : printf("\n- Recherche par Code Postale -\n");
                    printf("\n- Entrez votre recherche -\n");
                    scanf("%s", &search);
                    printf("\n");
                    do {
                        //debogage vvv
                        //printf("!---- %s %s %i ----!\n", search, tab[i].codep, strcmp(search,tab[i].codep));
                        if(strcmp(search,tab[i].codep)==0){
                            printf("client %d :\n Prenom: %s\n Nom: %s\n Ville: %s\n Codepostal: %s\n Numero: %s\n Email: %s\n Metier: %s\n",i,tab[i].prenom, tab[i].nom, tab[i].ville, tab[i].codep, tab[i].numero, tab[i].email, tab[i].metier);
                        }
                        i++;
                    }
                    while (i<taille);
                    break;
            case 5 : printf("\n- Recherche par Numero De Telephone -\n");
                    printf("\n- Entrez votre recherche -\n");
                    scanf("%s", &search);
                    printf("\n");
                    do {
                        //debogage vvv
                        //printf("!---- %s %s %i ----!\n", search, tab[i].numero, strcmp(search,tab[i].numero));
                        if(strcmp(search,tab[i].numero)==0){
                            printf("client %d :\n Prenom: %s\n Nom: %s\n Ville: %s\n Codepostal: %s\n Numero: %s\n Email: %s\n Metier: %s\n",i,tab[i].prenom, tab[i].nom, tab[i].ville, tab[i].codep, tab[i].numero, tab[i].email, tab[i].metier);
                        }
                        i++;
                    }
                    while (i<taille);
                    break;
            case 6 : printf("\n- Recherche par Email -\n");
                    printf("\n- Entrez votre recherche -\n");
                    scanf("%s", &search);
                    printf("\n");
                    do {
                        //debogage vvv
                        //printf("!---- %s %s %i ----!\n", search, tab[i].email, strcmp(search,tab[i].email));
                        if(strcmp(search,tab[i].email)==0){
                            printf("client %d :\n Prenom: %s\n Nom: %s\n Ville: %s\n Codepostal: %s\n Numero: %s\n Email: %s\n Metier: %s\n",i,tab[i].prenom, tab[i].nom, tab[i].ville, tab[i].codep, tab[i].numero, tab[i].email, tab[i].metier);
                        }
                        i++;
                    }
                    while (i<taille);
                    break;
            case 7 : printf("\n- Recherche par Metier -\n");
                    printf("\n- Entrez votre recherche -\n");
                    scanf("%s", &search);
                    printf("\n");
                    do {
                        //debogage vvv
                        printf("!---- %s %s %i ----!\n", search, tab[i].metier, strcmp(search,tab[i].metier));
                        if(strcmp(search,tab[i].metier)==0){
                            printf("client %d :\n Prenom: %s\n Nom: %s\n Ville: %s\n Codepostal: %s\n Numero: %s\n Email: %s\n Metier: %s\n",i,tab[i].prenom, tab[i].nom, tab[i].ville, tab[i].codep, tab[i].numero, tab[i].email, tab[i].metier);
                        }
                        i++;
                    }
                    while (i<taille);
                    break;
            default : printf("\n- Annulation -\n");
        }
}
