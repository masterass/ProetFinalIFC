#ifndef STRUCTURE
#define STRUCTURE

#define MAX 30

typedef struct identifiant
{
    char nom[MAX];
    char prenom[MAX];
    char MDP[MAX];
    int age;
    char pseudo[MAX];
} identifiant;

typedef struct produit
{
    float prix;
    char nom[MAX];
    int reference;
    int categorie;
    int quantite;
    char vendeur[MAX];
} produit;

#endif