//
// Created by antoine on 03/06/2017.
//
#include "recherche.h"

void recherchemdp(char chaineVerif[], char chemin[])
{
    char test[MAX], *recherche = NULL;
    char *verif;
    FILE* fichier = NULL;


    fichier = fopen(chemin, "r");


        while(fgets(test,MAX,fichier)!= 0)
        {
            recherche = strchr(test,'&');
            verif = strcat("&", chaineVerif);
            printf("%s", verif);

            printf("%s", recherche);

        }

    fclose(fichier);


}