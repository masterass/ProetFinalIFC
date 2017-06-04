#include "connection.h"

void connection(identifiant *IDPersonneConnecte)
{
    strcpy(IDPersonneConnecte->pseudo,"");
    strcpy(IDPersonneConnecte->MDP, "");
    char verif[MAX];
    strcpy(verif,"");
    char chemin[50]="utilisateurs/";

    do
    {
        strcpy(chemin, "utilisateurs/");// obiger car si on se tromper une fois le chemin prend le nom du pseudo qui est deja utiliser et celui qui l'est pas
        do
        {
            printf("\nVeuilliez vous connecter\n\n");
            printf("\nPseudo : ");
            gets(IDPersonneConnecte->pseudo);
            printf("\nMot de passe : ");
            gets(IDPersonneConnecte->MDP);
        }while (strcmp(IDPersonneConnecte->pseudo,"") == 0|| strcmp(IDPersonneConnecte->MDP, "") == 0);

        strcat(chemin,IDPersonneConnecte->pseudo);// concaténation afin d'obtenir le bon chemin relatif
        recherche(verif, chemin,'&');
        if (strcmp(verif,IDPersonneConnecte->MDP) == 0)
        {
            printf("Connexion reussi ! ");
        }
        else
            printf("Pseudo ou mot de passe incorrecte");
    }while(strcmp(verif,IDPersonneConnecte->MDP) == 1);
}

