#include "catalogue.h"

void afficherMenuCatalogue(identifiant *IDPersonneConnecte)
{
    if(estConnecte(IDPersonneConnecte) == 0)
        printf("Veuillez d'abord vous connecter");
    else {
        int choix;
        printf("\t\t\t CATALOGUE \n");
        printf("1) Afficher le catalogue\n");
        printf("2) Ajouter un produit\n\n");
        printf("Choix : ");
        fflush(stdin);
        scanf("%i", &choix);
        switch (choix) {
            case 1: afficherCatalogue(IDPersonneConnecte);
                break;
            case 2: ajouterArticle(IDPersonneConnecte);
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
        int i=0;
        rechercheCaractere(refMax, "catalogue", '#');
        if (strlen(refMax) == 0)
            produit1.reference =1;
        else{
            for(i=0;refMax[i]!=' ';i++){}
            refMax[i] = '\0';
            produit1.reference = charToInt(refMax);
            produit1.reference++;
        }
        FILE *fichier = NULL;
        fichier = fopen("catalogue", "a");
        if (fichier != NULL){
            fprintf(fichier,"#%i %s %1.2f %i %i %s\n",produit1.reference,produit1.nom,
                    produit1.prix,produit1.categorie,produit1.quantite,produit1.vendeur);
            fclose(fichier);
        }

        FILE *fichier1 = NULL;
        char chemin[MAX] = "utilisateurs/";
        strcat(chemin, IDPersonneConnecte->pseudo);
        fichier1 = fopen(chemin, "a");
        if (fichier1 != NULL){
            fprintf(fichier1,"#%i %s %1.2f %i %i %s\n",produit1.reference,produit1.nom,
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
        scanf("%i", &choixTri);
        } while(choixTri<1 || choixTri>3);

    switch(choixTri)
    {
        case 1: //triPrix(..., 0)// fonction qui tri ordre croissant
            break;
        case 2 : // fonction qui tri ordre décroissant
            break;
        case 3 : // fonction qui tri ordre alphabétique
            break;
        default: ;
    }
}
