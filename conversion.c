#include "conversion.h"

int charToInt(char chaine[]){
    int i, nombre=0;
    for(i=strlen(chaine)-1;i!=-1;i--) {
        int j=0;
        nombre = nombre + (chaine[i] - 48) * pow(10,j);
        j++;
    }
    return nombre;
}

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
