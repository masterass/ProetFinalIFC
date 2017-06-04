#include "connection.h"

void connection(identifiant *IDPersonneConnecte)
{
    strcpy(IDPersonneConnecte->pseudo,"");
    strcpy(IDPersonneConnecte->MDP, "");
    int i; // verification à modifier
    char verif[] = "&";
    char chemin[50]="utilisateurs/";

    do
    {
        do
        {
            printf("\nVeuilliez vous connecter\n\n");
            do
            {
                printf("\nPseudo : ");
                gets(IDPersonneConnecte->pseudo);

            }while(verificationPseudo(IDPersonneConnecte->pseudo)==1);

            printf("\nMot de passe : ");
            gets(IDPersonneConnecte->MDP);
        }while (strcmp(IDPersonneConnecte->pseudo,"") == 0|| strcmp(IDPersonneConnecte->MDP, "") == 0);

        // concaténation afin d'obtenir le bon chemin relatif
        strcat(chemin,IDPersonneConnecte->pseudo);
        strcat(verif,IDPersonneConnecte->MDP);
        i = recherchemdp(verif, chemin);
        if (i == 0)
        {
            printf("Connexion reussi ! ");
        }
        else
            printf("Pseudo ou mot de passe incorrecte");
    }while(i == 1);

}

