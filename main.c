#include <stdio.h>
#include <stdlib.h>

#include "structure.h"
#include "connection.h"
#include "inscription.h"
#include "clear_screen.h"

#define MAX 30
#define calibrage "     "

int main()
{
    // déclaration variables
    int choix;
    identifiant IDPersonneConnecte = {"","",""};
    do
    {
        choix = 0;

        while(choix < 1 || choix > 4)
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
            printf("2) S'identifier\n");
            printf("3) S'inscrire\n");
            printf("4) Quitter\n");
            printf("\nChoix : ");
            scanf("%i",&choix);
            clean_stdin();
            clear_screen();
        }

        switch (choix)
        {
            case 1 : ;
                break;
            case 2 : connection(&IDPersonneConnecte);
                break;
            case 3 : inscription(&IDPersonneConnecte);
                break;
            case 4 : ;
                break;
            default : printf("Erreur system");
        }

    }while(choix != 4);

    return 0;
}