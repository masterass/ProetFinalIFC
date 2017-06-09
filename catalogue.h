#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"
#include "tri.h"
#include "connection.h"
#include "conversion.h"
#include "recherche.h"

#ifndef PROJET_CONNECTION_CATALOGUE_H
#define PROJET_CONNECTION_CATALOGUE_H

void afficherMenuCatalogue(identifiant *IDPersonneConnecte);
void ajouterArticle(identifiant *IDPersonneConnecte);
void afficherCatalogue(identifiant *IDPersonneConnecte);
void procedureAchat(identifiant *IDPersonneConnecte,produit tabProduit[],int positionArticle,int refMax);

#endif //PROJET_CONNECTION_CATALOGUE_H

/** Catégorie
 * 1 high-tech
 * 2 sport
 * 3 maison
 * 4 jouet
 * 5 auto
 */