#include "fonctions.h"
#include <string.h>


void initEquipes(Equipe *e1, Equipe *e2) {
    int perso1, perso2, perso3, perso4, perso5, perso6, i;

    Comp co1 = {1, "Saisi de Bien", 1.3, "Vol le meuble préféré de l’adversaire (dégâts émotionnels)", 0, 0, 2, 0};
    Comp co2 = {1, "Impôts surprises", 0.0, "Applique une dette fiscale à toute l’équipe adverse", 4, 100, 4, 1};
    Comp co3 = {2, "Eclair au chocolat", 0.8, "Lance des éclairs sur le sol qui font glissés les adversaires et mets confusion", 3, 4, 3, 1};
    Comp co4 = {2, "Pika Pika", 0.0, "Répète Pika Pika ce qui endort l’adversaire", 6, 5, 4, 0};
    Comp co5 = {3, "Grosse épée", 1.5, "Attaque l’adversaire avec sa grosse épée", 0, 0, 2, 0};
    Comp co6 = {3, "Bouclier", 0.0, "Augmente la défense", 7, 5, 3, 2};
    Comp co7 = {4, "Morsure", 1.0, "Attaque l’adversaire et inflige du poison", 1, 4, 5, 0};
    Comp co8 = {4, "Vol de donné", 0.5, "Vol les données bancaires de l’adversaire pour des achats en ligne et applique une dette fiscale", 4, 100, 4, 0};
    Comp co9 = {5, "Préchauffage", 0.0, "Le four préchauffe (aucun effet et aucun dégâts)", 8, 12, 2, 2};
    Comp co10 = {5, "Tarte aux pommes", -1.2, "Si le four est chaud, rend des pv et motive oute l’équipe", 2, 7, 4, 1};
    Comp co11 = {6, "Syrène", 0.0, "Augmente la vitesse des alliés car ils sont désormais prioritaire", 9, 5, 4, 1};
    Comp co12 = {6, "Soin d’urgence", -2.3, "Soigne et rend confus à cause de la conduite catastrophique de l’ambulancier", 3, 8, 6, 0};

    Perso tab[6] = {
        {1, 0, "Urssaf", 200, 200, 25, 15, 0, 50, 8, co1, co2, 0, 0, 0, 0},
        {3, 0, "Pikachu", 140, 140, 30, 20, 0, 55, 5, co3, co4, 0, 0, 0, 0},
        {2, 0, "Garen", 200, 200, 25, 15, 0, 50, 8, co5, co6, 0, 0, 0, 0},
        {4, 0, "Serpent Malicieux", 140, 140, 30, 20, 0, 55, 5, co7, co8, 0, 0, 0, 0},
        {5, 0, "Four", 250, 250, 30, 10, 0, 40, 10, co9, co10, 0, 0, 0, 0},
        {6, 0, "Ambulance", 250, 250, 30, 10, 0, 40, 8, co11, co12, 0, 0, 0, 0}
    };

    printf("Entrez le nom de vos équipes\n");
    scanf("%s", e1->nom);
    scanf("%s", e2->nom);

    printf("\nQuels seront les membres des équipes ?\n\nChoisissez 3 personnages parmi les suivants en entrant le numéro associé :\n");
    for (i = 0; i < 6; i++) {
        printf("[%d] %s\n", i+1, tab[i].nom);
    }

    scanf("%d %d %d %d %d %d", &perso1, &perso2, &perso3, &perso4, &perso5, &perso6);

    while (perso1==perso2 || perso1==perso3 || perso2==perso3 || perso4==perso5 || perso4==perso6 || perso5==perso6
           || perso1<1 || perso1>6 || perso2<1 || perso2>6 || perso3<1 || perso3>6
           || perso4<1 || perso4>6 || perso5<1 || perso5>6 || perso6<1 || perso6>6) {
        printf("Veuillez choisir 3 personnages différents pour chaque équipe (entre 1 et 6).\n");
        scanf("%d %d %d %d %d %d", &perso1, &perso2, &perso3, &perso4, &perso5, &perso6);
    }

    int choix[6] = {perso1, perso2, perso3, perso4, perso5, perso6};
    for (i = 0; i < 6; i++) {
        int id = choix[i] - 1;
        if (i < 3) {
            e1->membres[i] = tab[id];
            e1->membres[i].id = i + 1;
            e1->membres[i].eqpId = 1;
        } else {
            e2->membres[i-3] = tab[id];
            e2->membres[i-3].id = i + 1;
            e2->membres[i-3].eqpId = 2;
        }
    }
}

void afficheAction(Perso* p) {
    printf("\n\n\nC'est le tour de %s\n", p->nom);
    printf("[1] Attaque Normale\n");
    printf("[2] %s\n    %s\n", p->c1.nom, p->c1.description);
    printf("[3] %s\n    %s\n", p->c2.nom, p->c2.description);
}

Perso* quiAttaquer(Equipe* e1, Equipe* e2) {
    int a;
    printf("\nQui voulez-vous cibler ?\n");
    for (int i = 0; i < 3; i++) {
        printf("[%d] %s\n", e1->membres[i].id, e1->membres[i].nom);
    }
    for (int i = 0; i < 3; i++) {
        printf("[%d] %s\n", e2->membres[i].id, e2->membres[i].nom);
    }
    scanf("%d", &a);
    for (int i = 0; i < 3; i++) {
        if (a == e1->membres[i].id) {return &(e1->membres[i]);}
        if (a == e2->membres[i].id) {return &(e2->membres[i]);}
    }
    return &(e1->membres[0]); // valeur par défaut
}

void affiche(Equipe e1, Equipe e2) {
    for (int i = 0; i < 100; i++) printf("-");
    printf("\n%s\n", e1.nom);
    for (int i = 0; i < 3; i++) {
        if(e1.membres[i].pv>0){
            printf("%s   Vie : %d/%d   Vitesse : %d/150\n", e1.membres[i].nom, e1.membres[i].pv, e1.membres[i].pvmax, e1.membres[i].vitact);
        }
    }
    printf("\n%s\n", e2.nom);
    for (int i = 0; i < 3; i++) {
        if(e2.membres[i].pv>0){
            printf("%s   Vie : %d/%d   Vitesse : %d/150\n", e2.membres[i].nom, e2.membres[i].pv, e2.membres[i].pvmax, e2.membres[i].vitact);
        }
    }
    for (int i = 0; i < 100; i++) printf("-");
    printf("\n");
}

Perso* determinerAttaquant(Equipe* e1, Equipe* e2) {
    Perso* p = NULL;
    int vmax;

    for (int i = 0; i < 3; i++) {
        if(p==NULL){vmax=0;}
        else{vmax=p->vitact;}
        if (e1->membres[i].vitact >= 150 && e1->membres[i].vitact > vmax && e1->membres[i].pv > 0) {p = &(e1->membres[i]);}
        if(p==NULL){vmax=0;}
        else{vmax=p->vitact;}
        if (e2->membres[i].vitact >= 150 && e2->membres[i].vitact > vmax && e2->membres[i].pv > 0) {p = &(e2->membres[i]);}
    }
    
    for (int i = 0; i < 3; i++) {
        e1->membres[i].vitact = (e1->membres[i].vitact + e1->membres[i].vit);
        e2->membres[i].vitact = (e2->membres[i].vitact + e2->membres[i].vit);
    }
    if(p!=NULL){
        p->vitact = p->vitact%150;
    }
    return p;
}


int perdu(Equipe e1, Equipe e2) {
    int morts1 = 0, morts2 = 0;
    for (int i = 0; i < 3; i++) {
        if (e1.membres[i].pv <= 0) {morts1++;}
        if (e2.membres[i].pv <= 0) {morts2++;}
    }
    if (morts1 == 3) {return 1;}
    if (morts2 == 3) {return 2;}
    return 0;
}
