//
// Created by antoine on 03/06/2017.
//
#include "recherche.h"

int recherchemdp(char chaineVerif[], char chemin[])
{
    char ligne[MAX], *recherche = NULL;
    char transition[] = "";
    FILE *fichier =NULL;
    fichier = fopen(chemin, "r");

    if (fichier != NULL)
    {
        while(fgets(ligne,100,fichier))
        {
            recherche = strchr(ligne, '&');
            if (recherche != NULL)
                strcat(transition,recherche);
        }

       if (strcmp(chaineVerif, transition)==0)
       {
           return 0;
       }
    }
    else
    {
        return 1;
    }

    fclose(fichier);
}