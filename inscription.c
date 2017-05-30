#include "inscription.h"
#include "structure.h"


void inscription(identifiant *IDPersonneConnecte)
{
    //identifiant personne1;
    int i;
    char chemin[50] = "utilisateurs/", confMDP[MAX];

    // aquisition
    printf("\t\t Veuilliez vous inscrire\n\n");

    do // prenom
    {
        fflush(stdin);
        printf("Prenom : ");
        gets(IDPersonneConnecte->prenom);
    }while(verification(IDPersonneConnecte->prenom) == 1);

    do //nom
    {
        fflush(stdin);
        printf("Nom : ");
        gets(IDPersonneConnecte->nom);
    }while(verification(IDPersonneConnecte->nom) == 1);


    do //age
    {
        fflush(stdin);
        printf("\nEntrer votre age : ");
        scanf("%i", &IDPersonneConnecte->age);
    }while(verificationAge(IDPersonneConnecte->age) == 1);

    do//mdp
    {
        fflush(stdin);
        printf("Mot de passe : (8 caracteres minimums) ");
        gets(IDPersonneConnecte->MDP);
    }while(verificationMDP(IDPersonneConnecte->MDP) == 1);
    printf("Confirmer votre mot de passe : ");
    gets(confMDP);
    while(strcmp(IDPersonneConnecte->MDP, confMDP) != 0)
    {
        printf("\nErreur de confirmation mot de passe\n");
         do
        {
            fflush(stdin);
            printf("Mot de passe : (8 caractères minimums) ");
            gets(IDPersonneConnecte->MDP);
        }while(verificationMDP(IDPersonneConnecte->MDP) == 1);
        printf("Confirmer votre mot de passe : ");
        gets(confMDP);
    }

   do
   {
        fflush(stdin);
        printf("Pseudo : (3 caracteres minimums) ");
        gets(IDPersonneConnecte->pseudo);
        strcat(chemin, IDPersonneConnecte->pseudo );
        if (verificationInscription(chemin)== 1)
            printf("Pseudo deja utilise \n");
   }while(verificationPseudo(IDPersonneConnecte->pseudo)==1 || verificationInscription(chemin) == 1);

    printf("Voulez vous confirmer 1: oui 0: non ? \n");
    scanf("%d", &i );

    if (i == 1)
    {
        FILE* fichier = NULL;
        fichier = fopen(chemin, "w");
        fputs(IDPersonneConnecte->prenom , fichier);
        fputs("\n", fichier);
        fputs(IDPersonneConnecte->nom, fichier);
        fputs("\n", fichier);
        fprintf(fichier,"%i", IDPersonneConnecte->age);
        fclose(fichier);

        printf("Bienvenue");
    }

        system("cls");
    //fflush(stdin);
}

