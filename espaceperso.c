//
// Created by antoi on 05/06/2017.
//

#include "espaceperso.h"
#include "facture.h"

void color(int t, int f)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, f*16+t);
}


void espaceperso(identifiant *IDPersonneConnecte)
{
    char verif[MAX];

    char chemin[50] = "utilisateurs/";
    strcat(chemin, IDPersonneConnecte->pseudo);
    FILE *fichier;
    fichier = fopen(chemin, "r");


if (strcmp(IDPersonneConnecte->pseudo, "")==0)
{
    color(1,0);
    printf("\t\t\tVeuillez vous connecter pour acceder a votre espace\n\n");
}
else
{
    printf("\t\t\t MON ESPACE PERSONNEL");
    rechercheCaractere(verif, chemin, '@');
    printf("\nPrenom : ");
    printf("%s", verif);
    printf("    Nom : ");
    rechercheCaractere(verif,chemin,'$');
    printf("%s", verif);
}

}

