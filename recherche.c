#include "recherche.h"

int rechercheCaractere(char chaineVerif[], char chemin[], char caractereRecherche)
{
    char ligne[MAX], TEMP;
    int nombreCaractere=0;
    FILE *fichier =NULL;
    fichier = fopen(chemin, "r");

    strcpy(chaineVerif, "");
    if (fichier != NULL)
    {
        while(fgets(ligne,MAX,fichier)!= NULL) {
            TEMP = ligne[0];
            if (TEMP == caractereRecherche)
            {
                int i;
                for(i = 1;i<strlen(ligne) && ligne[i] != ' ';i++)
                    chaineVerif[i-1] = ligne[i];
                if(caractereRecherche == '&' || caractereRecherche == '$' || caractereRecherche == '@')
                    chaineVerif[i-2]='\0';
                else
                    chaineVerif[strlen(chaineVerif)]='\0';
                nombreCaractere++;
            }
        }
        fclose(fichier);
    }
    return nombreCaractere;
}

int referencementArticle(produit tabRetourProduit[],char chemin[], int categorie,char caractereRecherche)
{
    FILE *fichier=NULL;
    char TEMP, ligne[MAX];
    fichier = fopen(chemin, "r");
    if(fichier!= NULL) {
        int j=0;
        while(fgets(ligne,MAX,fichier)!= NULL){
            TEMP = ligne[0];
            if (TEMP == caractereRecherche) {
                int i, min =1;
                char chaineFichier[MAX];
                strcpy(chaineFichier,"");
                for (i = min; ligne[i] != ' '; i++)
                    chaineFichier[i-1]=ligne[i];
                chaineFichier[i-min] = '\0';
                tabRetourProduit[j].reference = atoi(chaineFichier);
                i++;
                min=i;

                for(i;ligne[i] != ' '; i++)
                    tabRetourProduit[j].nom[i-min]=ligne[i];
                chaineFichier[i-min] = '\0';
                tabRetourProduit[j].nom[i-min] = '\0';
                i++;
                min=i;

                for(i;ligne[i] != ' '; i++)
                    chaineFichier[i-min]=ligne[i];
                chaineFichier[i-min] = '\0';
                tabRetourProduit[j].prix = atof(chaineFichier);
                i++;
                min=i;
                strcpy(chaineFichier,"");

                for(i;ligne[i] != ' '; i++)
                    chaineFichier[i-min]=ligne[i];
                chaineFichier[i-min] = '\0';
                tabRetourProduit[j].categorie = atoi(chaineFichier);
                i++;
                min=i;

                for(i;ligne[i] != ' '; i++)
                    chaineFichier[i-min]=ligne[i];
                chaineFichier[i-min] = '\0';
                tabRetourProduit[j].quantite = atoi(chaineFichier);
                i++;
                min=i;

                for(i;ligne[i] != '\n'; i++)
                    tabRetourProduit[j].vendeur[i-min]=ligne[i];
                chaineFichier[i-min] = '\0';
                tabRetourProduit[j].vendeur[i-min]='\0';
                i++;

                if((tabRetourProduit[j].categorie != categorie && categorie != 0) || tabRetourProduit[j].quantite<1) {
                    clear_produit(&tabRetourProduit[j]);
                    j--;
                }
                j++;
            }
        }
        return j-1;
    }
}

int rechercheArticle(char NOM[], produit tableau[], int tailleTab)
{
    if(strcmp(NOM,"") != 0){
        int i,trouve=0;
        for (i = 0; i < tailleTab || (strcmp(NOM, tableau[i].nom) == 0); i++) {
            if (strcmp(NOM, tableau[i].nom) == 0) {
                printf("\nNous avons trouve votre produit\n");
                printf("Le produit est : %s\n",tableau[i].nom);
                printf("Il coute : %1.2f\n",tableau[i].prix);
                printf("Il en reste : %i",tableau[i].quantite);
                trouve = 1;
                return i;
            }
        }
        if(trouve == 0)
            printf("Nous n'avons pas trouve votre article");
    }
    else
        return -1;
}