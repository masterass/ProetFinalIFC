
#include "espaceperso.h"
#include "facture.h"

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
            printf("\t\t\tVeuillez vous connecter pour acceder a votre espace\n\n");
        }
        else
        {
            do
            {
                clear_screen();
                printf("\t\t\t MON ESPACE PERSONNEL");
                rechercheCaractere(verif, chemin, '@');
                printf("\nPrenom : %s  ", verif);
                rechercheCaractere(verif,chemin,'$');
                printf("Nom : %s", verif);

                printf(("\n\n 1) Consulter mes factures"));
                printf("\n 2) Gerer mes ventes");
                printf("\n 3) Retour a l'acceuil\n");
                printf("\n Choix : ");
                scanf("%i", &choix);
            }while(choix != 1 && choix!= 2 && choix != 3);



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

