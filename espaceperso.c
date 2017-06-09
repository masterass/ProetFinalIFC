#include "espaceperso.h"

void espaceperso(identifiant *IDPersonneConnecte) //affichage option espace personnel
{
    char verif[MAX];
    int choix = 0;
    FILE *fichier;

    char chemin[MAX] = "utilisateurs/";
    strcat(chemin, IDPersonneConnecte->pseudo);

    if (strcmp(IDPersonneConnecte->pseudo, "")==0)
    {
        clear_screen();
        printf("\t\t\tVeuillez vous connecter pour acceder a votre espace\n\n");
    }
    else
    {
        do {
            do {
                clear_screen();
                printf("\t\t\t MON ESPACE PERSONNEL");
                rechercheCaractere(verif, chemin, '@');
                printf("\nBonjour, %s  ", verif);
                rechercheCaractere(verif, chemin, '$');
                printf("%s", verif);

                printf(("\n\n 1) Consulter mes factures"));
                printf("\n 2) Retour a l'acceuil\n");
                printf(" Choix : ");
                scanf("%i", &choix);

            }while(choix<1 || choix>2);

            switch (choix) {
                case 1 : afficherProduitAchete(IDPersonneConnecte);//affichage des factures
                    // break;
                case 2 : ;// quitte la fonction
                    break;
                default:
                    printf("Erreur system");
            }
        }while(choix!=2);
    }
    clear_screen();
}

void afficherProduitAchete(identifiant *IDPersonneConnecte){
    char TEMP[MAX],chemin[MAX] = "utilisateurs/";
    strcat(chemin, IDPersonneConnecte->pseudo);
    int i,refMaxI=rechercheCaractere(TEMP,chemin,'%');
    clear_screen();
    printf("\t\tFACTURES\n\n");
    produit tabProduitAchete[refMaxI];
    referencementArticle(tabProduitAchete,chemin,0,'%');
    for(i=0;i<refMaxI;i++) // afficher tous les produit present dans le fichier utilisateur corespondant
        printf("%i) %s\t%1.2f euros\t%i achete\tsoit %1.2f euro au total\n ",i+1,tabProduitAchete[i].nom,tabProduitAchete[i].prix,tabProduitAchete[i].quantite,
               tabProduitAchete[i].quantite*tabProduitAchete[i].prix);
    fflush(stdin);
    printf("\nAppuyer sur entree pour continuer !");
    gets(TEMP);
}