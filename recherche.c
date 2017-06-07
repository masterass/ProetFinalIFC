#include "recherche.h"

int rechercheCaractere(char chaineVerif[], char chemin[], char caractereRecherche)
{
    char ligne[MAX], TEMP;

    FILE *fichier =NULL;
    fichier = fopen(chemin, "r");

    strcpy(chaineVerif, "");
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
        fclose(fichier);
    }
    else
        return 1;
}

produit recherchearticle(char NOM[], produit tableau[])
{
    int i ;


    for (i = 0; i < 1000 || (strcmp(NOM, tableau[i].nom)==0) ; i ++)
    {
        if ( strcmp(NOM, tableau[i].nom) == 0 )
            printf("\nNous avons trouvé votre produit");
        else
            printf("\nProduit introuvable !");
    }

}