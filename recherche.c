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
                    tabRetourProduit[j].reference = charToInt(chaineFichier);
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

/*int rechercheMaxChaine(char *chaineVerif, char *chemin, char *chaineRecherche)
{
    char ligne[MAX], TEMP[MAX];
    FILE *fichier =NULL;
    int i=0;

    fichier = fopen(chemin, "r");

    if (fichier != NULL)
    {
        while(fgets(ligne,MAX,fichier)!= NULL && strcmp(TEMP, chaineRecherche)!=0) //tan que il existe une ligne et que TEMP == chaine recherché
        {
            strncpy(TEMP,ligne,strlen(chaineRecherche));
            TEMP[strlen(chaineRecherche)] = '\0';
            if (strcmp(TEMP,chaineRecherche) == 0)
            {
                strcpy(chaineVerif, "");
                for(i = 0;i< (strlen(ligne)-strlen(chaineRecherche));i++)
                    chaineVerif[i] = ligne[i+strlen(chaineRecherche)];
                chaineVerif[i-1]='\0';
            }
        }
        if(i==0)
            chaineVerif[i]='\0';
        fclose(fichier);
    }
    else
        return 1;
}*/