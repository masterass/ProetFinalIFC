#include "tri.h"

void triPrix(produit tableauProduit[],int taille)
{
    int passage = 0;
    int permutation = 1;
    int en_cours;

    while (permutation)
    {
        permutation = 0;
        passage++;
        for (en_cours = 0; en_cours < taille - passage; en_cours++) {
            if (tableauProduit[en_cours].prix > tableauProduit[en_cours + 1].prix) {
                permutation = 1;
                // on echange les deux elements
                produit temp = tableauProduit[en_cours];
                tableauProduit[en_cours] = tableauProduit[en_cours + 1];
                tableauProduit[en_cours + 1]= temp;
            }
        }
    }
}

void triRef(produit tableauProduit[],int taille)
{
    int passage = 0;
    int permutation = 1;
    int en_cours;

    while (permutation)
    {
        permutation = 0;
        passage++;
        for (en_cours = 0; en_cours < taille - passage; en_cours++) {
            if (tableauProduit[en_cours].reference > tableauProduit[en_cours + 1].reference) {
                permutation = 1;
                // on echange les deux elements
                produit temp = tableauProduit[en_cours];
                tableauProduit[en_cours] = tableauProduit[en_cours + 1];
                tableauProduit[en_cours + 1]= temp;
            }
        }
    }
}
