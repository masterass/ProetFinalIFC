#include "catalogue.h"

void afficherMenuCatalogue(identifiant *IDPersonneConnecte)
{
    int choix;
    printf("1) Afficher le catalogue\n");
    printf("2) Ajouter un produit\n\n");
    printf("Choix : ");
    fflush(stdin);
    scanf("%i",&choix);
    switch (choix)
    {
        case 1: ;
            break;
        case 2: ajouterArticle(IDPersonneConnecte);
            break;
        default : printf("Erreur system");
    }
}

void ajouterArticle(identifiant *IDPersonneConnecte)
{
    clear_screen();
    if(estConnecte(IDPersonneConnecte) == 0)
        printf("Veuillez d'abord vous connecter");
    else
    {
        produit produit1;
        fflush(stdin);
        do {
            printf("Veuillez entrer le nom de l'article : ");
            scanf("%s", produit1.nom);
        }while (verification(produit1.nom)==1);
        fflush(stdin);
        do {
            printf("Veuillez entrer la categorie de cette article : ");
            scanf("%s", produit1.categorie);
        }while (verification(produit1.categorie) == 1);
        fflush(stdin);
        do {
            printf("Veuillez entrer le prix a l'unite de l'article : ");
            scanf("%f", &produit1.prix);
        }while (produit1.prix <=0);
        fflush(stdin);
        do {
            printf("Veuillez entrer la quantite d'article a vendre : ");
            scanf("%i", &produit1.quantite);
        }while (produit1.quantite <= 0);
        strcpy(produit1.vendeur,IDPersonneConnecte->pseudo);
    }
    clear_screen();
    fflush(stdin);
}

void afficherCatalogue(identifiant *IDPersonneConnecte)
{
    char recherche[50];
    printf("Que voulez vous rechercher ?\n");
    gets(recherche);
    choixTri();
}

char choixTri()
{
    int choix;
    printf("1) Tri par prix, ordre croissant\n");
    printf("1) Tri par prix, ordre decroissanr\n");
    printf("2) Tri par ordre alphabetique\n");
    printf("Choix : ");
    fflush(stdin);
    scanf("%i",choix);
    switch (choix)
    {
        case 1: ;
            break;
        case 2: ;
            break;
        case 3: ;
            break;
        default: printf("Erreur system");
    }
}