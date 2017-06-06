#include "connection.h"

void connection(identifiant *IDPersonneConnecte)
{
    if(estConnecte(IDPersonneConnecte) == 0)
    {
        strcpy(IDPersonneConnecte->pseudo, "");
        strcpy(IDPersonneConnecte->MDP, "");
        char verif[MAX];
        strcpy(verif, "");
        char chemin[50] = "utilisateurs/";

        do {
            strcpy(chemin, "utilisateurs/");// obiger car si on se tromper une fois le chemin prend le nom du pseudo qui est deja utiliser et celui qui l'est pas
            do {
                printf("\t\t\tVEUILLEZ VOUS CONNECTER\n\n");
                printf("\nPseudo : ");
                gets(IDPersonneConnecte->pseudo);
                printf("\nMot de passe : ");
                gets(IDPersonneConnecte->MDP);
            } while (strcmp(IDPersonneConnecte->pseudo, "") == 0 || strcmp(IDPersonneConnecte->MDP, "") == 0);

            strcat(chemin, IDPersonneConnecte->pseudo);// concaténation afin d'obtenir le bon chemin relatif
            rechercheCaractere(verif, chemin, '&');
            clear_screen();
            if (strcmp(verif, IDPersonneConnecte->MDP) == 0)
                printf("\t\t\tConnexion reussie ! ");
            else
                printf("\t\t\tPseudo ou mot de passe incorrecte\n");
        } while (strcmp(verif, IDPersonneConnecte->MDP) != 0);
    }
    else
        printf("\t\t\tVous etes deja connecte");
    printf("\n\n");
}

void deconnection(identifiant *IDPersonneConnecte)
{
    strcpy(IDPersonneConnecte->nom,"");
    strcpy(IDPersonneConnecte->prenom,"");
    strcpy(IDPersonneConnecte->MDP,"");
    strcpy(IDPersonneConnecte->pseudo,"");
    IDPersonneConnecte->age = 0;
}

int estConnecte(identifiant *IDPersonneConnecte)
{
    if(strcmp(IDPersonneConnecte->pseudo, "") == 0 && strcmp(IDPersonneConnecte->MDP, "") == 0)
        return 0;
    else
        return 1;
}