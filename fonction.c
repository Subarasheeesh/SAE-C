#include <stdio.h>
#include <stdbool.h>
#include <time.h>
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
    float temps;
    clock_t t1, t2;


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

    t1 = clock();
    // Met les données saisit dans le tableau
    fprintf(fichier, "%s,%s,%s,%s,%s,%s,%s",prenom,nom,ville,codep,numero,email,metier);

    printf("\n- Personne ajouter avec succes -\n");
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("\ntemps d'execution = %f\n", temps);
    fclose(fichier);
    return 0;


}

void recherche(PERSONNE tab[6000], int taille)
{
    int user;
    char search[30];
    int i=0;
    float temps;
    clock_t t1, t2;

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
                t1 = clock();
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
                t1 = clock();
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
                    t1 = clock();
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
                    t1 = clock();
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
                    t1 = clock();
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
                    t1 = clock();
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
                    t1 = clock();
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
                    t1 = clock();
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
        t2 = clock();
        temps = (float)(t2-t1)/CLOCKS_PER_SEC;
        printf("\ntemps d'execution = %f\n", temps);
}

void supprimer(PERSONNE personne[], int index, int *ligne){
    int i;
    //Écrase la valeur i, a supprimer, par la valeur a i+1
    for (i = index; i < *ligne-1; i++){
        personne[i] = personne[i + 1];
    }

    //Enlève une ligne
    *ligne -= 1;
    printf("La personne %d vient d'etre supprimee [%d personnes restantes]\n", index, *ligne-1);
}

void sauvegarder(PERSONNE personne[],int ligne){
    char nom[100];
    float temps;
    clock_t t1, t2;
    printf("- ecris le nom de la sauvegarde -\n");
    scanf("%s", nom);
    t1 = clock();
    FILE * fichier = fopen(nom, "w");

    for (int i = 0 ; i<ligne ; i++){
        fprintf(fichier,"%s,%s,%s,%s,%s,%s,%s",personne[i].prenom,personne[i].nom,personne[i].ville,personne[i].codep,personne[i].numero,personne[i].email,personne[i].metier);
    }
    fclose(fichier);
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("\ntemps d'execution = %f\n", temps);
}

void recherchemanquante(PERSONNE personne[],int ligne){
    int j=0;
    for(int i = 0;i < ligne;i++){
        if (strlen(personne[i].prenom) == 0 || strlen(personne[i].nom) == 0 || strlen(personne[i].ville) == 0 || strlen(personne[i].codep) == 0 || strlen(personne[i].numero) == 0 || strlen(personne[i].email) == 0 || strlen(personne[i].metier) == 0){
            printf("client %d :\n Prenom: %s\n Nom: %s\n Ville: %s\n Codepostal: %s\n Numero: %s\n Email: %s\n Metier: %s\n",i,personne[i].prenom, personne[i].nom, personne[i].ville, personne[i].codep, personne[i].numero, personne[i].email, personne[i].metier);
            j++;
        }
    }
    printf("il y a %d client possedant des donnees manquantes\n",j);
}

void tri_insert(PERSONNE personne[],int ligne){
    int i = 1;
    int j;
    PERSONNE petit;
    int choice;
    float temps;
    clock_t t1, t2;

    printf("------------------------------------------\n");
    printf("------- Trier par : ----------------------\n");
    printf("-- 1 -- Prenom ---------------------------\n");
    printf("-- 2 -- Nom ------------------------------\n");
    printf("-- 3 -- Ville ----------------------------\n");
    printf("-- 4 -- Code Postal ----------------------\n");
    printf("-- 5 -- Telephone ------------------------\n");
    printf("-- 6 -- Email ----------------------------\n");
    printf("-- 7 -- Metier ---------------------------\n");
    printf("------------------------------------------\n");
    scanf("%d",&choice);
    t1 = clock();
    switch(choice){
        case 1 :
            while(i<ligne){
                petit=personne[i];
                j=i-1;
                while(j>0&&strcasecmp(petit.prenom,personne[j].prenom)<0){
                    personne[j+1]=personne[j];
                    j=j-1;
                }
                personne[j+1]=petit;
                i=i+1;
            }
            break;
        case 2 :
            while(i<ligne){
                petit=personne[i];
                j=i-1;
                while(j>0&&strcasecmp(petit.nom,personne[j].nom)<0){
                    personne[j+1]=personne[j];
                    j=j-1;
                }
                personne[j+1]=petit;
                i=i+1;
            }
            break;
        case 3 :
            while(i<ligne){
                petit=personne[i];
                j=i-1;
                while(j>0&&strcasecmp(petit.ville,personne[j].ville)<0){
                    personne[j+1]=personne[j];
                    j=j-1;
                }
                personne[j+1]=petit;
                i=i+1;
            }
            break;
        case 4 :
            while(i<ligne){
                petit=personne[i];
                j=i-1;
                while(j>0&&strcasecmp(petit.codep,personne[j].codep)<0){
                    personne[j+1]=personne[j];
                    j=j-1;
                }
                personne[j+1]=petit;
                i=i+1;
            }
            break;
        case 5 :
            while(i<ligne){
                petit=personne[i];
                j=i-1;
                while(j>0&&strcasecmp(petit.numero,personne[j].numero)<0){
                    personne[j+1]=personne[j];
                    j=j-1;
                }
                personne[j+1]=petit;
                i=i+1;
            }
            break;
        case 6 :
            while(i<ligne){
                petit=personne[i];
                j=i-1;
                while(j>0&&strcasecmp(petit.email,personne[j].email)<0){
                    personne[j+1]=personne[j];
                    j=j-1;
                }
                personne[j+1]=petit;
                i=i+1;
            }
            break;
        case 7 :
            while(i<ligne){
                petit=personne[i];
                j=i-1;
                while(j>0&&strcasecmp(petit.metier,personne[j].metier)<0){
                    personne[j+1]=personne[j];
                    j=j-1;
                }
                personne[j+1]=petit;
                i=i+1;
            }
            break;
    }
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("\ntemps d'execution = %f\n", temps);
}

void modifier(PERSONNE personne[],int ligne){
    int lignemodif;
    int user;
    char modif[30];
    printf("- Entrez la ligne a modifier -\n");
    scanf("%d",&lignemodif);
    if (lignemodif>ligne-1&&lignemodif<0){
        printf("- Impossible, ligne vide -");
    }
    else{
        printf("------------------------------------------\n");
        printf("------- modifier : -----------------------\n");
        printf("-- 0 -- Tout modifier --------------------\n");
        printf("-- 1 -- Prenom ---------------------------\n");
        printf("-- 2 -- Nom ------------------------------\n");
        printf("-- 3 -- Ville ----------------------------\n");
        printf("-- 4 -- Code Postal ----------------------\n");
        printf("-- 5 -- Telephone ------------------------\n");
        printf("-- 6 -- Email ----------------------------\n");
        printf("-- 7 -- Metier ---------------------------\n");
        printf("------------------------------------------\n");
        scanf("%d",&user);
        switch(user){
            case 0 : printf("- changer le prenom -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].prenom,modif);
                     printf("- changer le nom -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].nom,modif);
                     printf("- changer le ville -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].ville,modif);
                     printf("- changer le code postal -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].codep,modif);
                     printf("- changer le telephone -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].numero,modif);
                     printf("- changer le email -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].email,modif);
                     printf("- changer le metier -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].metier,modif);
                     break;
            case 1 : printf("- changer le prenom -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].prenom,modif);
                     break;
            case 2 : printf("- changer le nom -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].nom,modif);
                     break;
            case 3 : printf("- changer le ville -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].ville,modif);
                     break;
            case 4 : printf("- changer le code postal -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].codep,modif);
                     break;
            case 5 : printf("- changer le telephone -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].numero,modif);
                     break;
            case 6 : printf("- changer le email -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].email,modif);
                     break;
            case 7 : printf("- changer le metier -\n");
                     scanf("%s",&modif);
                     strcpy(personne[lignemodif].metier,modif);
                     break;
            default : printf("- Erreur -\n");
            }
        }
}



