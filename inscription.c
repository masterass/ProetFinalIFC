#include "inscription.h"

void inscription(identifiant *IDPersonneConnecte)
{
    int i;
    FILE* fichier = NULL;
    char chemin[50] = "utilisateurs/", confMDP[MAX];
    fflush(stdin);
    // aquisition
    printf("\t\t Veuilliez vous inscrire\n\n");

    do // prenom
    {
        printf("Prenom : ");
        gets(IDPersonneConnecte->prenom);
    }while(verification(IDPersonneConnecte->prenom) == 1);

    do //nom
    {
        printf("\nNom : ");
        gets(IDPersonneConnecte->nom);
    }while(verification(IDPersonneConnecte->nom) == 1);

    do//pseudo
    {
        strcpy(chemin, "utilisateurs/"); // obiger car si on se tromper une fois le chemin prend le nom du pseudo qui est deja utiliser et celui qui l'est pas
        printf("\nPseudo : (3 caracteres minimums) ");
        gets(IDPersonneConnecte->pseudo);
        strcat(chemin, IDPersonneConnecte->pseudo );

    }while(verificationPseudo(IDPersonneConnecte->pseudo)==1 || verificationInscription(chemin) == 1);

    do// age
    {
        fflush(stdin);
        printf("\nEntrer votre age : ");
        scanf("%i", &IDPersonneConnecte->age);
    }while(verificationAge(IDPersonneConnecte->age) == 1);


    do//mdp
    {
        printf("\nMot de passe : (8 caracteres minimums) ");
        gets(IDPersonneConnecte->MDP);
    }while(verificationMDP(IDPersonneConnecte->MDP) == 1);

    printf("Confirmer votre mot de passe : ");
    gets(confMDP);
    while(strcmp(IDPersonneConnecte->MDP, confMDP) != 0) //verif confirmation mot de passe correcte
    {
        printf("\nErreur de confirmation mot de passe\n");
         do
        {
            printf("Mot de passe : (8 caracteres minimums) ");
            gets(IDPersonneConnecte->MDP);
        }while(verificationMDP(IDPersonneConnecte->MDP) == 1);
        printf("Confirmer votre mot de passe : ");
        gets(confMDP);
    }

    printf("Voulez vous confirmer 1: oui 0: non ? \n");
    scanf("%d", &i );


    if (i == 1)
    {
        fichier = fopen(chemin, "w");
        fprintf(fichier, "@%s", IDPersonneConnecte->prenom);
        fputs("\n", fichier);
        fprintf(fichier, "$%s", IDPersonneConnecte->nom);
        fputs("\n", fichier);
        fprintf(fichier, "&%s", IDPersonneConnecte->MDP);
        fputs("\n", fichier);
        fprintf(fichier,"%i", IDPersonneConnecte->age);
        fclose(fichier);
        printf("Bienvenue");

    }

        clear_screen();
        fflush(stdin);
}

