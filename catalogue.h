#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"
#include "tri.h"
#include "connection.h"

#ifndef PROJET_CONNECTION_CATALOGUE_H
#define PROJET_CONNECTION_CATALOGUE_H

void afficherMenuCatalogue(identifiant *IDPersonneConnecte);
void ajouterArticle(identifiant *IDPersonneConnecte);
void afficherCatalogue(identifiant *IDPersonneConnecte);
char choixTri(void);

#endif //PROJET_CONNECTION_CATALOGUE_H
