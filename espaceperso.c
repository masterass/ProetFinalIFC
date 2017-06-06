//
// Created by antoi on 05/06/2017.
//

#include "espaceperso.h"

void espaceperso(identifiant *IDPersonneConnecte)
{
    char verif[MAX];

    char chemin[50] = "utilisateurs/";
    strcat(chemin, IDPersonneConnecte->pseudo);
    FILE *fichier;
    fichier = fopen(chemin, "r");
if (strcmp(IDPersonneConnecte->pseudo, "")==0)
{
    printf("\t\t\tVeuillez vous connecter pour acceder a votre espace\n\n");
}
else
{
    printf("\t\t\t MON ESPACE PERSONNEL");
    recherche(verif, chemin, '@');
    printf("\nPrenom : ");
    printf("%s", verif);
    printf("    Nom : ");
    recherche(verif,chemin,'$');
    printf("%s", verif);
}

}

