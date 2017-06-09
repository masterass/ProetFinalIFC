#include <stdio.h>

#include "structure.h"
#include "connection.h"
#include "inscription.h"
#include "catalogue.h"
#include "espaceperso.h"

#define MAX 60
#define calibrage "     "

int main()
{
    // déclaration variables
    int choix;
    identifiant IDPersonneConnecte = {"","","",0,""}; //initialisation structure identifiant
    do
    {
        choix = 0;
        while(choix < 1 || choix > 6)
        {
            printf("\n");
            printf("%s 000     00  000000000000000000000000000000000000000000000000000000\n",calibrage);
            printf("%s 000     00      00     0000000000000000000000000000000000000000000\n",calibrage);
            printf("%s 000     00      00     0000000000000000000000000000000000000000000\n",calibrage);
            printf("%s 000     00      00     0000000000000000000000000000000000000000000\n",calibrage);
            printf("%s 000     00      00     00       0000      000        00000      00\n",calibrage);
            printf("%s 000     00      00     00 000  0000 100000 0000 0000 0001 00000  0\n",calibrage);
            printf("%s 000     00      00     00000  00000 000000  000 0000 000         0\n",calibrage);
            printf("%s 000     00      00     000  0000000 000000  000 0000 000  00000000\n",calibrage);
            printf("%s   00   00       00     00  0000 000  0000  0000 0000 0000  0000  0\n",calibrage);
            printf("%s    00000        00     00       00000    00000   00   0000     000\n",calibrage);
            printf("%s                        0000000000000000000000000000000000000000000\n\n",calibrage);

            printf("\t\t%sBONJOUR ET BIENVENUE SUR UTzone ! \n\n Veuillez choisir un des quatre choix indique ci-dessous :\n\n",calibrage);
            printf("1) Acceder au catalogue\n");
            printf("2) Mon espace personnel\n");
            printf("3) S'identifier\n");
            printf("4) S'inscrire\n");
            printf("5) Se deconnecter\n");
            printf("6) Quitter\n");
            if(strcmp(IDPersonneConnecte.pseudo,"")!= 0)
                printf("\nVous etes connecte en tant que : %s\n", IDPersonneConnecte.pseudo);
            printf("\nChoix : ");
            fflush(stdin); // vider le buffer
            scanf("%i",&choix);

            clear_screen();
        }

        fflush(stdin);
        switch (choix)
        {
            case 1 : afficherMenuCatalogue(&IDPersonneConnecte);
                break;
            case 2 : espaceperso(&IDPersonneConnecte);
                break;
            case 3 : connection(&IDPersonneConnecte);
                break;
            case 4 : inscription(&IDPersonneConnecte);
                break;
            case 5 : deconnection(&IDPersonneConnecte);
                break;
            case 6 : ; //quiter le programme
                break;
            default : printf("Erreur system");
        }

    }while(choix != 6);

    return 0;
}