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
