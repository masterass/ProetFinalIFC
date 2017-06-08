#include "catalogue.h"

void afficherMenuCatalogue(identifiant *IDPersonneConnecte)
{
    if(estConnecte(IDPersonneConnecte) == 0)
        printf("\t\tVeuillez d'abord vous connecter\n\n");
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
    clear_screen();
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
            produit1.reference = atoi(refMax);
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
    char recherche[MAX],refMaxC[MAX];
    rechercheCaractere(refMaxC,"catalogue",'#');
    int choixTri,choixCategorie, choixAchat, refMaxI=atoi(refMaxC);

    int i;
    do{
        clear_screen();
        printf("\nVeuillez choisir la categorie de l'article rechercher\n");
        printf("0) Rechercher dans toutes les categories\n");
        for(i=1;i<=5;i++) {
            char chaineCategorie[MAX]="";
            convCategorie(chaineCategorie,i);
            printf("%i) %s\n",i,chaineCategorie);
        }
        printf("Choix : ");
        fflush(stdin);
        scanf("%i",&choixCategorie);
    }while(choixCategorie<0 || choixCategorie>5);

    produit tabProduit[refMaxI];
    referencementArticle(tabProduit,choixCategorie);
    clear_screen();

    printf("Que voulez vous rechercher ? (afficher toute la categorie)\n");
    fflush(stdin);
    gets(recherche);
    if(strcmp(recherche,"") == 0) //si RECHERCHE est VIDE
    {
        do {
            printf("1) Tri par prix, ordre croissant\n");
            printf("2) Tri par date d'ajout\n");
            printf("Choix : ");
            fflush(stdin);
            scanf("%i", &choixTri);
        } while(choixTri<1 || choixTri>3);

        switch(choixTri)
        {
            case 1: triPrix(tabProduit,refMaxI,0);// fonction qui tri ordre croissant
                break;
            case 2 : ; // fonction qui tri ordre décroissant
                break;
            default: printf("Erreur system");
        }
        for(i=0;i<refMaxI;i++)
            printf("%i) %s\n",i+1,tabProduit[i].nom);
    }
    else
        rechercheArticle(recherche, tabProduit, refMaxI);

    do {
        fflush(stdin);
        printf("Choisissez votre produit (0 retour) : ");
        scanf("%i", &choixAchat);
    } while(choixAchat<0 || choixAchat > i+1);

    if(strcmp(IDPersonneConnecte->pseudo,tabProduit[i-1].vendeur))
        printf("Vous ne pouvez pas acheter un objet que vous possedez deja");
    else if(choixAchat!=0)
    {
        FILE *fichier;
        fichier = fopen("catalogue","r+");
        rewind(fichier);
        int ligne;
        char test[MAX];
        for(ligne=1;ligne<choixAchat;ligne++)
            fgets(test,MAX,fichier);

    }
    clear_screen();

    for(i=0;i<2;i++)
        printf("\n\n%s\n",tabProduit[i].nom);
}
