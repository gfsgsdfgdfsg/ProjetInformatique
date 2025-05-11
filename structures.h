#ifndef structure_H
#define structure_H

// Définition de la structure Comp
typedef struct {
    int id;
    char nom[32];
    float valeur;
    char description[256];
    char effet;
    char toureffet;
    char cooldown;
    char choix;
} Comp;

// Définition de la structure Perso
typedef struct {
    int id;
    int eqpId;
    char nom[32];
    int pvmax;
    int pv;
    int atck;
    int agi;
    int vitact;
    int vit;
    int def;
    Comp c1;
    Comp c2;
    int confus;
    int poison;
    int endormi;
    int chaud;
} Perso;

// Définition de la structure Equipe
typedef struct {
    char nom[12];
    Perso membres[3];
} Equipe;

#endif // PERSONNAGE_H