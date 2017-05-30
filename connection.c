#include "connection.h"
#include "structure.h"

void connection(identifiant *IDPersonneConnecte)
{
    // déclaration variables
    if(strcmp((*IDPersonneConnecte).nom, "") == 0)
    {

        char chemin[50]="utilisateurs/";
        FILE* fichier = NULL;
        while(fichier == NULL)
        {
            // aquisition
            while (strcmp(IDPersonneConnecte->prenom,"") == 0 || strcmp(IDPersonneConnecte->nom, "") == 0 || strcmp(IDPersonneConnecte->MDP, "") == 0)
            {
                printf("Veuilliez vous connecter\n\n");
                printf("Prenom : ");
                gets(IDPersonneConnecte->prenom);
                printf("Nom : ");
                gets(IDPersonneConnecte->nom);
                printf("Mot de passe : ");
                gets(IDPersonneConnecte->MDP);
            }

            // concaténation afin d'obtenir le bon chemin relatif
            strcat(chemin,IDPersonneConnecte->prenom);
            strcat(chemin, "_");
            strcat(chemin,IDPersonneConnecte->nom);

            //verification existence utilisateur/fichier
            fichier = fopen(chemin, "r");

            if(fichier != NULL)
                printf("\n\nConnection reussie !!");
            else
            {
                system("cls");
                printf("Connection a echouee\n");
                strcpy(IDPersonneConnecte->prenom,"");
                strcpy(IDPersonneConnecte->nom, "");
                strcpy(IDPersonneConnecte->MDP, "");
            }
        }
        fclose(fichier);
    }
    else
    {
        printf("Vous etes deja connecte");
    }
}

