#include "connection.h"
#include "structure.h"

void connection(identifiant *IDPersonneConnecte)
{
    // déclaration variables
    /*if(strcmp((*IDPersonneConnecte).nom, "") == 0)
    {*/
        char chemin[50]="utilisateurs/";
        FILE* fichier = NULL;
        while(fichier == NULL)
        {
            // aquisition
            while (strcmp(IDPersonneConnecte->pseudo,"") == 0|| strcmp(IDPersonneConnecte->MDP, "") == 0)
            {
                clean_stdin();
                printf("Veuilliez vous connecter\n\n");
                printf("Pseudo: ");
                gets(IDPersonneConnecte->pseudo);
                printf("Mot de passe : ");
                gets(IDPersonneConnecte->MDP);
            }
            // concaténation afin d'obtenir le bon chemin relatif
            strcat(chemin,IDPersonneConnecte->pseudo);

            //verification existence utilisateur/fichier
            fichier = fopen(chemin, "r");

            if(fichier != NULL)
                printf("\n\nConnection reussie !!");
            else
            {
                clear_screen();
                printf("Connection a echouee\n");
                strcpy(IDPersonneConnecte->pseudo,"");
                strcpy(IDPersonneConnecte->MDP, "");
            }
        }
        fclose(fichier);
    //3}
    /*else
    {
        printf("Vous etes deja connecte");
    }*/
}

