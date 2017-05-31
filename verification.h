#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structure.h"
#include "clear_screen.h"

int verification(char chaineVerif[]);
int verificationMDP(char chaineVerif[]);
int verificationPseudo(char chaineVerif[]);
int verificationAge(int age);
int verificationInscription(char chaineVerif[]);
void mettreMajuscule(char chaine[]);
