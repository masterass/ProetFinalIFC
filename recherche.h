#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structure.h"
#include "clear.h"
#include "conversion.h"

void rechercheCaractere(char chaineVerif[], char chemin[], char caractereRecherche);
void referencementArticle(produit tabRetourProduit[], int categorie);
produit recherchearticle(char NOM[], produit tableau[],int tailleTab);