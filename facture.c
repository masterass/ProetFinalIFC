#include "facture.h"
#define tab "   "

void ecrireFacture (identifiant *IDPersonneConnecte,produit produit1)
{
    char chemin[MAX] = "utilisateurs/";
    FILE *fichier = NULL;
    strcat(chemin, IDPersonneConnecte->pseudo);
    fichier = fopen(chemin, "a");
    if (fichier != NULL){
        fprintf(fichier,"$%i %s %1.2f %i %i %s\n",produit1.reference,produit1.nom,
                produit1.prix,produit1.categorie,produit1.quantite,produit1.vendeur);
        fclose(fichier);
    }
}
void convCategorie (char chaine[], int IDCategorie)
{

    switch (IDCategorie)
    {
        case 1 : strcpy(chaine,"HighTech");
            break;
        case 2 : strcpy(chaine,"Sport");
            break;
        case 3 : strcpy(chaine,"Maison");
            break;
        case 4 : strcpy(chaine,"Jouet");
            break;
        case 5 : strcpy(chaine,"Automobile");
            break;
        default:;
    }
}

void afficherFacture (produit produit1)
{
    char categorie[15]="";
    printf("%s VOTRE FACTURE\n\n",tab);
    convCategorie(categorie, produit1.categorie);
    printf(">>%s\n",categorie);
    printf("%s\t%1.2f\n",produit1.nom,produit1.prix);
    printf("\tVendu par : %s\n\n",produit1.vendeur);
    printf("UTzone vous remercie et espere vous revoire au plus vite !");
}
