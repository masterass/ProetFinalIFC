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