//
// Created by antoine on 03/06/2017.
//
#include "recherche.h"

int recherchemdp(char chaineVerif[], char chemin[])
{
    char test[MAX], *recherche = NULL;
    char verif[] = "&";
    FILE* fichier = NULL;


    fichier = fopen(chemin, "r");

    if (fichier != NULL)
    {
        while(fgets(test,MAX,fichier)!= 0)
        {
            recherche = strchr(test,'&');
        }
        strcat(verif, chaineVerif);

        if (strcmp(recherche, verif)==0)
            return 1;

    }

    fclose(fichier);


}