#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structure.h"
#include "clear.h"
#include "conversion.h"

int rechercheCaractere(char chaineVerif[], char chemin[], char caractereRecherche);
int referencementArticle(produit tabRetourProduit[],char chemin[], int categorie,char caractereRecherche);
int rechercheArticle(char NOM[], produit tableau[], int tailleTab);