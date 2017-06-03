#include "tri.h"

void triBulle(produitsATrier[])
{
    int passage = 0;
    int permutation = 1;
    int en_cours;

    while ( permutation)
    {
        permutation = 0;
        passage++;
        for (en_cours = 0; en_cours < 20 - passage; en_cours++) {
            if (produitATrier[en_cours] > produitATrier[en_cours + 1]) {
                permutation = 1;
                // on echange les deux elements
                int temp = produitATrier[en_cours];
                produitATrier[en_cours] = produitATrier[en_cours + 1];
                produitATrier[en_cours + 1] = temp;
            }
        }
    }
}