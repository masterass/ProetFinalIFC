#include "connection.h"

void connection(identifiant *IDPersonneConnecte)
{
    int i = 0;
    if(estConnecte(IDPersonneConnecte) == 0)
    {
        strcpy(IDPersonneConnecte->pseudo, "");
        strcpy(IDPersonneConnecte->MDP, "");
        char verif[MAX];
        strcpy(verif, "");
        char chemin[50] = "utilisateurs/";

       do {
            strcpy(chemin, "utilisateurs/");// obiger car si on se tromper une fois le chemin prend le nom du pseudo qui est deja utiliser et celui qui l'est pas
            /*do {*/
                fflush(stdin);
                printf("\t\t\tVEUILLEZ VOUS CONNECTER\n\n");
                printf("\nPseudo : ");
                gets(IDPersonneConnecte->pseudo);
                printf("\nMot de passe : ");
                gets(IDPersonneConnecte->MDP);
            /*} while (strcmp(IDPersonneConnecte->pseudo, "") == 0 || strcmp(IDPersonneConnecte->MDP, "") == 0);*/

            strcat(chemin, IDPersonneConnecte->pseudo);// concaténation afin d'obtenir le bon chemin relatif
            rechercheCaractere(verif, chemin, '&');
            clear_screen();
            if (strcmp(verif, IDPersonneConnecte->MDP) == 0)
            {
                printf("\t\t\tConnexion reussie ! ");
            }
            else
           {
               printf("\t\t\tPseudo ou mot de passe incorrecte\n\n");
               do
               {
                   fflush(stdin);
                   printf("\t\tVoulez vous reessayer ? 1) Oui 2) Retour\n");
                   scanf("%i", &i);
                   if (i == 2)
                   {
                       strcpy(IDPersonneConnecte->pseudo, "");
                       strcpy(IDPersonneConnecte->MDP, "");
                   }

               }while(i != 1 && i !=2);
               clear_screen();
           }

       } while (strcmp(verif, IDPersonneConnecte->MDP) != 0 && i == 1);

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