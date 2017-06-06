#include <stdio.h>
#include <stdlib.h>

#include "structure.h"
#include "connection.h"
#include "inscription.h"
#include "catalogue.h"
#include "clear_screen.h"
#include "espaceperso.h"

#define MAX 30
#define calibrage "     "

int main()
{
    // déclaration variables
    int choix;
    identifiant IDPersonneConnecte = {"","","",0,""};
    do
    {
        choix = 0;
        color(7,0);
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
            printf("%s                        0000000000000000000000000000000000000000000\n\n");

            printf("\t\t%sBONJOUR ET BIENVENUE SUR UTzone ! \n\n Veuillez choisir un des quatre choix indique ci-dessous :\n\n",calibrage);
            printf("1) Acceder au catalogue\n");
            printf("2) Mon espace personnel\n");
            printf("3) S'identifier\n");
            printf("4) S'inscrire\n");
            printf("5) Se deconnecter\n");
            printf("6) Quitter\n");
            printf("\nChoix : ");
            scanf("%i",&choix);
            fflush(stdin);
            clear_screen();
        }

        // vider le buffer
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
            case 6 : ;
                break;
            default : printf("Erreur system");
        }

    }while(choix != 5);

    return 0;
}