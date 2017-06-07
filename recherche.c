#include "recherche.h"

void rechercheCaractere(char chaineVerif[], char chemin[], char caractereRecherche)
{
    char ligne[MAX], TEMP;

    FILE *fichier =NULL;
    fichier = fopen(chemin, "r");

    strcpy(chaineVerif, "");
    if (fichier != NULL)
    {
        while(fgets(ligne,MAX,fichier)!= NULL /*&& TEMP != caractereRecherche*/) {
            TEMP = ligne[0];
            if (TEMP == caractereRecherche) {
                strcpy(chaineVerif, "");
                int i;
                for(i = 1;i<strlen(ligne);i++)
                    chaineVerif[i-1] = ligne[i];
                chaineVerif[strlen(chaineVerif)-1]='\0';
            }
        }
        fclose(fichier);
    }
}

void referencementArticle(produit tabRetourProduit[], int categorie)
{
    FILE *fichier=NULL;
    char TEMP, ligne[MAX], categorieTab[5][MAX]={"high-tech", "sport", "maison", "jouet", "auto"};
    fichier = fopen("catalogue", "r");
    if(fichier!= NULL) {
        if (categorie == 0) {
            int j;
            for(j=0;fgets(ligne,MAX,fichier)!= NULL;j++)/*&& TEMP != caractereRecherche*/{
                TEMP = ligne[0];
                if (TEMP == '#') {
                    int i, min =1;
                    char chaineFichier[MAX];
                    for (i = min; ligne[i] != ' '; i++)
                        chaineFichier[i-1]=ligne[i];
                    tabRetourProduit[j].reference = atoi(chaineFichier);
                    min=i;

                    for(i;ligne[i] != ' '; i++)
                        chaineFichier[i-min]=ligne[i];
                    tabRetourProduit[j].prix = atof(chaineFichier);
                    min=i;

                    for(i;ligne[i] != ' '; i++)
                        chaineFichier[i-min]=ligne[i];
                    tabRetourProduit[j].categorie = atof(chaineFichier);
                    min=i;
                }
            }
        }
    }
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