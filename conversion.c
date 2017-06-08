#include "conversion.h"

void convCategorie (char chaine[], int IDCategorie)
{

    switch (IDCategorie)
    {
        case 1 : strcpy(chaine,"HighTech");
            break;
        case 2 : strcpy(chaine,"Sport");
            break;
        case 3 : strcpy(chaine,"Maison");
            break;
        case 4 : strcpy(chaine,"Jouet");
            break;
        case 5 : strcpy(chaine,"Automobile");
            break;
        default:;
    }
}
