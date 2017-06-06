#include "catalogue.h"

void afficherMenuCatalogue(identifiant *IDPersonneConnecte)
{
    if(estConnecte(IDPersonneConnecte) == 0)
        printf("Veuillez d'abord vous connecter");
    else {
        int choix;
        printf("1) Afficher le catalogue\n");
        printf("2) Ajouter un produit\n\n");
        printf("Choix : ");
        fflush(stdin);
        scanf("%i", &choix);
        switch (choix) {
            case 1:
                afficherCatalogue(IDPersonneConnecte);
                break;
            case 2:
                ajouterArticle(IDPersonneConnecte);
                break;
            default :
                printf("Erreur system");
        }
    }
}

void ajouterArticle(identifiant *IDPersonneConnecte)
{
    produit produit1;
    int confirmation;

    fflush(stdin);
    do {
        printf("Veuillez entrer le nom de l'article : ");
        scanf("%s", produit1.nom);
    }while (verification(produit1.nom)==1);
    fflush(stdin);
    do {
        printf("1) High-tech\n");
        printf("2) Sport\n");
        printf("3) Maison\n");
        printf("4) Jouet\n");
        printf("5) Auto\n");
        printf("Veuillez entrer la categorie de cette article : ");
        scanf("%i", &produit1.categorie);
    }while (produit1.categorie < 1 || produit1.categorie > 5);
    fflush(stdin);
    do {
        printf("Veuillez entrer le prix a l'unite de l'article (en euro) : ");
        scanf("%f", &produit1.prix);
    }while (produit1.prix <=0);
    fflush(stdin);
    do {
        printf("Veuillez entrer la quantite d'article a vendre : ");
        scanf("%i", &produit1.quantite);
    }while (produit1.quantite <= 0);
    strcpy(produit1.vendeur,IDPersonneConnecte->pseudo);
    fflush(stdin);
    do {
        printf("Voulez vous confirmer 1: oui 0: non ? \n");
        scanf("%i", &confirmation);
    }while (confirmation != 0 && confirmation != 1);

    if(confirmation == 1)
    {
        char refMax[MAX];
        rechercheChaine(refMax,"catalogue","#R");
        if (strlen(refMax) == 0)
            strcpy(refMax,"1");
        else{
            produit1.reference = charToInt(refMax);
        }
        FILE *fichier = NULL;
        fichier = fopen("catalogue", "a");
        if (fichier != NULL){
            fprintf(fichier,"#R%i\n#N%s\n#P%1.2f\n#C%i\n#Q%i\n#V%s\n\n",produit1.reference,produit1.nom,
                    produit1.prix,produit1.categorie,produit1.quantite,produit1.vendeur);
            fclose(fichier);
        }
    }
    clear_screen();
}

void afficherCatalogue(identifiant *IDPersonneConnecte)
{
    char recherche[50];
    int choixTri;
    printf("Que voulez vous rechercher ?\n");
    scanf("%s",recherche);
    do {
        printf("1) Tri par prix, ordre croissant\n");
        printf("2) Tri par prix, ordre decroissanr\n");
        printf("3) Tri par ordre alphabetique\n");
        printf("Choix : ");
        fflush(stdin);
        scanf("%i", choixTri);
        } while(choixTri<1 || choixTri>3);
}