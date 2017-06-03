#include "connection.h"

void connection(identifiant *IDPersonneConnecte)
{
    strcpy(IDPersonneConnecte->pseudo,"");
    strcpy(IDPersonneConnecte->MDP, "");
    char chemin[50]="utilisateurs/";
    FILE* fichier = NULL;

        do
        {
            do
            {
                clean_stdin();
                printf("Veuilliez vous connecter\n\n");
                do
                {
                    printf("\nPseudo : ");
                    gets(IDPersonneConnecte->pseudo);
                }while(verificationPseudo(IDPersonneConnecte->pseudo)==1);

                printf("Mot de passe : ");
                gets(IDPersonneConnecte->MDP);
            }while (strcmp(IDPersonneConnecte->pseudo,"") == 0|| strcmp(IDPersonneConnecte->MDP, "") == 0);

            // concaténation afin d'obtenir le bon chemin relatif
            strcat(chemin,IDPersonneConnecte->pseudo);


            recherchemdp(IDPersonneConnecte->pseudo, chemin);

            //verification existence utilisateur/fichier
            fichier = fopen(chemin, "r");

            if(fichier != NULL)
            {
                printf("\nConnection reussie !!");
                //clear_screen();
            }
            else
            {
                //clear_screen();
                printf("Connection a echouee\n");
                clean_stdin();
                strcpy(IDPersonneConnecte->pseudo,"");
                strcpy(IDPersonneConnecte->MDP, "");
            }
        } while(fichier == NULL);
        fclose(fichier);



}

