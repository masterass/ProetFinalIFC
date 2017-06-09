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
    }
    clear_screen();
}

void afficherCatalogue(identifiant *IDPersonneConnecte)
{
    char recherche[MAX],refMaxC[MAX];
    int choixTri,choixCategorie, choixAchat, refMaxI=rechercheCaractere(refMaxC,"catalogue",'#'),i;

    produit tabProduit[refMaxI];

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

    refMaxI = referencementArticle(tabProduit,"catalogue",choixCategorie,'#') +1; //+1 car categorie commence a 1

    clear_screen();
    printf("Que voulez vous rechercher ? ('ENTRER' ne rien rechercher de particulier)\n");
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
            case 1: triPrix(tabProduit,refMaxI);// fonction qui tri ordre croissant
                break;
            case 2 : ; // fonction qui tri ordre date d'ajout
                break;
            default: printf("Erreur system");
        }
        for(i=0;i<refMaxI;i++)
            printf("%i) %s\t%1.2f euros\n",i+1,tabProduit[i].nom,tabProduit[i].prix);

        do { //choix prod
            fflush(stdin);
            printf("Choisissez votre produit (0 retour) : ");
            scanf("%i", &choixAchat);
        } while(choixAchat<0 || choixAchat > i+1);
        clear_screen();
        if(choixAchat!= 0) {
            procedureAchat(IDPersonneConnecte,tabProduit,choixAchat-1,refMaxI);
        }
    }
    else{
        int articleRecherche = rechercheArticle(recherche, tabProduit, refMaxI);
        if(articleRecherche != -1){
            do {
                printf("1) acheter l'article\n");
                printf("2) retour au menu\n");
                printf("Choix : ");
                fflush(stdin);
                scanf("%i", &choixAchat);
            } while (choixAchat != 1 && choixAchat != 2);
            if (choixAchat == 1) {
                procedureAchat(IDPersonneConnecte, tabProduit, articleRecherche, refMaxI);
            }
        }
    }
}

void procedureAchat(identifiant *IDPersonneConnecte,produit tabProduit[],int positionArticle, int refMax){
    int quantite;

    do {  // quantite produit
        fflush(stdin);
        printf("Combien voulez-vous en acheter? : ");
        scanf("%i", &quantite);
    } while (quantite < 1 || quantite > tabProduit[positionArticle].quantite);
    if(strcmp(IDPersonneConnecte->pseudo,tabProduit[positionArticle].vendeur) == 0) {
        clear_screen();
        printf("\t\tVous ne pouvez pas acheter un objet que vous possedez deja");
    }
    else{
        tabProduit[positionArticle].quantite = tabProduit[positionArticle].quantite - quantite;

        FILE *catalogue,*utilisateur;
        char chemin[MAX]="utilisateurs/";
        strcat(chemin,IDPersonneConnecte->pseudo);
        catalogue = fopen("catalogue", "w+");
        utilisateur = fopen(chemin,"a");
        if (catalogue != NULL && chemin != NULL) {
            clear_screen();
            printf("\t\tVous venez d'acheter %i %s",quantite,tabProduit[positionArticle].nom);
            int j;
            triRef(tabProduit,refMax);
            for(j=0;j<refMax;j++) {
                fprintf(catalogue, "#%i %s %1.2f %i %i %s\n", tabProduit[j].reference, tabProduit[j].nom,
                        tabProduit[j].prix, tabProduit[j].categorie, tabProduit[j].quantite, tabProduit[j].vendeur);
            }
            fprintf(utilisateur, "%%%i %s %1.2f %i %i %s\n", tabProduit[positionArticle].reference, tabProduit[positionArticle].nom,
                    tabProduit[positionArticle].prix, tabProduit[positionArticle].categorie, quantite, tabProduit[positionArticle].vendeur);
            fclose(catalogue);
            fclose(utilisateur);
        }
    }
}