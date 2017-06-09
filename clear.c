#include "clear.h"

void clear_screen() //effacer tous ce qu'il y a afficher suivant l'os utilisé
{
    #ifdef __WIN32__
        system("cls");

    #else
        #ifdef __WIN64__
            system("cls");
        #else
        system("clear");
        #endif
    #endif
}

void clear_produit(produit *produit1)  //vider produit
{
    int i;
    for(i=0;i<MAX;i++) {
        produit1->nom[i] = '\0';
        produit1->vendeur[i] = '\0';
    }
    produit1->categorie=-1;
    produit1->quantite=-1;
    produit1->reference=-1;
    produit1->prix=-1;
}