#include "catalogue.h"

void afficherMenuCatalogue(identifiant *IDPersonneConnecte)
{
    int choix;
    printf("1) Afficher le catalogue\n");
    printf("2) Ajouter un produit\n\n");
    printf("Choix : ");
    fflush(stdin);
    scanf("%i",choix);
    switch (choix)
    {
        case 1: ;
            break;
        case 2: ;
            break;
        default : printf("Erreur system");
    }
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