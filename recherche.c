#include "recherche.h"

int recherchemdp(char chaineVerif[], char chemin[])
{
    char ligne[MAX], recherche[MAX];
    char transition[MAX];

    FILE *fichier =NULL;
    fichier = fopen(chemin, "r");

    if (fichier != NULL)
    {
        while(fgets(ligne,30,fichier)!= NULL)
        {
            recherche[0] = ligne[0];
            if (recherche != NULL && recherche[0] == '&')
            {
                strcpy(recherche, "");
                int i;
                for(i = 1;i<strlen(ligne);i++)
                {
                    recherche[i-1] = ligne[i];
                }
                recherche[strlen(ligne)-2] = '\0';
                strcpy(transition, recherche);
                printf("%s\n%s",recherche,transition);
            }
        }
        fclose(fichier);
        printf("%s %s", chaineVerif, transition);
       if (strcmp(chaineVerif, transition)==0)
           return 0;
       else
           return  1;
    }
    else
    {
        return 1;
    }

}