#ifndef STRUCTURE
#define STRUCTURE

#define MAX 30

typedef struct identifiant
{
    char prenom[MAX];
    char nom[MAX];
    char MDP[MAX];
    int age;
    char pseudo[MAX];
} identifiant;

typedef struct produit
{
    int prix;
    char nom[MAX];
    char reference[MAX];
} produit;

#endif