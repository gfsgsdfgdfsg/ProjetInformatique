#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include "structures.h"

// Fonctions
void initEquipes(Equipe *e1, Equipe *e2);
void afficheAction(Perso* p);
Perso* quiAttaquer(Equipe* e1, Equipe* e2);
void affiche(Equipe e1, Equipe e2);
Perso* determinerAttaquant(Equipe *e1, Equipe *e2);
int perdu(Equipe e1, Equipe e2);

#endif
