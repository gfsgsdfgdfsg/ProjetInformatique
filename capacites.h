#ifndef CAPACITES_H
#define CAPACITES_H

#include "structures.h"

// Capacités de Pikachu
void eclair_au_chocolat(Perso *p1, Perso *p2);
void pika_pika(Perso *p1, Perso *P2);

// Capacités du Four
void prechauffage(Perso *p1);
void tartechauffee(Perso *p1, Equipe* e1);

// Capacités de URSSAF
void saisi_de_bien(Perso *p1, Perso *p2);
void impots_surprises(Perso *p1, Equipe* e1);

// Capacités de Garen
void grosse_epee(Perso *p1, Perso *p2);
void bouclier(Perso *p1);

// Capacités de Serpent Malicieux
void morsure(Perso *p1, Perso *p2);
void vol_donnees(Perso *p1, Perso *p2);

// Capacités d'Ambulance
void sirene(Perso *p1, Equipe* e1);
void soin_urgence(Perso *p1, Perso *p2);

#endif // CAPACITES_H
