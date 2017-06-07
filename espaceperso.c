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
    int choix = 0;
    int i = 0;
    FILE *fichier;

    char chemin[50] = "utilisateurs/";
    strcat(chemin, IDPersonneConnecte->pseudo);

    do
    {
        clear_screen();
        if (strcmp(IDPersonneConnecte->pseudo, "")==0)
        {
            color(4,7);
            printf("\t\t\tVeuillez vous connecter pour acceder a votre espace\n\n");
        }
        else
        {
            printf("\t\t\t MON ESPACE PERSONNEL");
            rechercheCaractere(verif, chemin, '@');
            printf("\nPrenom : %s  ", verif);
            rechercheCaractere(verif,chemin,'$');
            printf("Nom : %s", verif);

            printf(("\n\n 1) Consulter mes factures"));
            printf("\n 2) Gerer mes ventes");
            printf("\n 3) Retour a l'acceuil\n");
            scanf("%i", &choix);


            switch(choix)
            {
                case 1 : fichier = fopen(chemin, "r");//affichage des factures

                    break;

                case 2 : // gestion des achats
                    break;
                case 3 : i = 0;// quitte la fonction
                    break;
                default: printf("Erreur system");

            }
        }
    }while ( i == 1);

    clear_screen();
}

