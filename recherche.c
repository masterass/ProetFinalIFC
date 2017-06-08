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
            if (TEMP == caractereRecherche)
            {
                strcpy(chaineVerif, "");
                int i;
                for(i = 1;i<strlen(ligne);i++)
                    chaineVerif[i-1] = ligne[i];
                //if(caractereRecherche == '&')
                chaineVerif[i-2]='\0';
                //else
                //    chaineVerif[strlen(chaineVerif)-1]='\0';
            }
        }
        fclose(fichier);
    }
}

void referencementArticle(produit tabRetourProduit[], int categorie)
    {
    FILE *fichier=NULL;
    char TEMP, ligne[MAX];
    fichier = fopen("catalogue", "r");
    if(fichier!= NULL) {
        int j=0;
        while(fgets(ligne,MAX,fichier)!= NULL){
            TEMP = ligne[0];
            if (TEMP == '#') {
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

                if(tabRetourProduit[j].categorie != categorie && categorie != 0) {
                    clear_produit(tabRetourProduit[j]);
                    j--;
                }
            }
            j++;
        }
    }
}

produit recherchearticle(char NOM[], produit tableau[],int tailleTab)
{
    if(strcmp(NOM,"") != 0){
        int i;
        for (i = 0; i < tailleTab + 1 || (strcmp(NOM, tableau[i].nom) == 0); i++) {
            if (strcmp(NOM, tableau[i].nom) == 0)
                printf("\nNous avons trouvé votre produit");
            else
                printf("\nProduit introuvable !");
        }
    }
}