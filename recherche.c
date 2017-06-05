#include "recherche.h"

int recherche(char chaineVerif[], char chemin[],char caractereRecherche)
{
    char ligne[MAX], TEMP;

    FILE *fichier =NULL;
    fichier = fopen(chemin, "r");

    if (fichier != NULL)
    {
        while(fgets(ligne,MAX,fichier)!= NULL && TEMP != caractereRecherche)
        {
            TEMP = ligne[0];
            if (TEMP == caractereRecherche)
            {
                strcpy(chaineVerif, "");
                int i;
                for(i = 1;i<strlen(ligne);i++)
                    chaineVerif[i-1] = ligne[i];
                chaineVerif[strlen(chaineVerif)-1]='\0';
            }
        }
        printf("%s\n",chaineVerif);
        fclose(fichier);
    }
    else
        return 1;
}