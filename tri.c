#include "tri.h"

void triPrix(produit tableauProduit[])
{
    int passage = 0;
    int permutation = 1;
    int en_cours;

    while ( permutation)
    {
        permutation = 0;
        passage++;
        for (en_cours = 0; en_cours < 20 - passage; en_cours++) {
            if (tableauProduit[en_cours].prix > tableauProduit[en_cours + 1].prix) {
                permutation = 1;
                // on echange les deux elements
                int temp = tableauProduit[en_cours].prix;
                tableauProduit[en_cours].prix = tableauProduit[en_cours + 1].prix;
                tableauProduit[en_cours + 1].prix = temp;
            }
        }
    }
}

void triAlphabetique(produit tableauPoduit[])
{

}