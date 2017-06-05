#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"
#include "verification.h"
#include "clear_screen.h"
#include "recherche.h"

void connection(identifiant *IDPersonneConnecte);
void deconnection(identifiant *IDPersonneConnecte);
int estConnecte(identifiant *IDPersonneConnecte);