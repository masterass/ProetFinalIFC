#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structure.h"
#include "clear.h"
#include "conversion.h"

void rechercheCaractere(char chaineVerif[], char chemin[], char caractereRecherche);
int referencementArticle(produit tabRetourProduit[], int categorie);
int rechercheArticle(char NOM[], produit tableau[], int tailleTab);
int rechercheLigneReference(char chemin[], int ref);