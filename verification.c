#include "verification.h"
//verif mot de passe verif email verif pseudo
int verification(char chaineVerif[])
{
    int i;
    //strlwr(chaineVerif);
    mettreMinuscule(chaineVerif);

    if(strcmp(chaineVerif, "") == 0)
    {
        printf("Veuillez entrer des caractères ! \n");
        return 1;
    }
    else
    {
        for(i=0;i<strlen(chaineVerif);i++)
        {
            if(chaineVerif[i] < 'a' || chaineVerif[i]> 'z')
            {
                printf("/!\\Erreur le champ saisie comporte des caractères non autorise\n");
                return 1;
            }
        }
        return 0;
    }
}

int verificationMDP(char chaineVerif[])
{
    int i;

    if(strlen(chaineVerif) < 8)
    {
        printf("Veuillez entrer un mot de passe plus long\n");
        return 1;
    }
    else
    {
        for(i=0;i<strlen(chaineVerif);i++)
        {
            if(chaineVerif[i] < ' ' || chaineVerif[i]> '~')
            {
                printf("Erreur le champ saisie comporte des caractères non autorise\n");
                return 1;
            }
        }
        return 0;
    }
}
int verificationPseudo(char chaineVerif[])
{
       int i;

    if(strlen(chaineVerif) < 3)
    {
        printf("Veuillez rentrer un pseudo correct \n");
        return 1;
    }
    else
    {
        for(i=0;i<strlen(chaineVerif);i++)
        {
            if(chaineVerif[i] < ')' || chaineVerif[i] >= 'z')
            {
                printf("Erreur le champ saisie comporte des caractères non autorise\n");
                return 1;
            }
        }
        return 0;
    }
}
int verificationAge(int age) // si l'age est cohérent ou réglementaire
{
    if (age < 0 || age > 120)
    {
        printf("Valeur incorrecte !");
        return 1;
    }
    else if (age <16 )
    {
            printf("L'age recommande pour notre site est de minimum 16 ans ! \n");
            return 1;
    }
    else
    {
            return 0;
    }

}

int verificationInscription(char chemin[]) // si le pseudo est disponible ou non
{
    FILE *fichier;
    fichier = fopen(chemin, "r");

    if (fichier == NULL)
    {
        return 0;
    }
    else
    {
        printf(" Desole, ce pseudo deja utilise !");
        return 1;
    }



}

void mettreMinuscule(char chaine[])
{
    int i;
    for(i=0;i<strlen(chaine);i++)
        chaine[i]=tolower(chaine[i]);
}

