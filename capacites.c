//Capacités de pikachu
void eclair_au_chocolat(Perso *P1, Perso *P2) {
    P2->confus = 1;
    printf("%s utilise Éclair au chocolat ! %s est confus !\n", P1->nom, P2->nom);
}

void pika_pika(Perso *P1, Perso *P2) {
    P2->endormi = 1;
    printf("%s crie Pika Pika et ennuie son adversaire ! %s s'endort...\n", P1->nom, P2->nom);
}

//Capacités du four
void prechauffage(Perso *P1) {
    P1->chaud = 1;
    printf("%s commence à préchauffer. Il sera prêt pour la tarte !\n", P1->nom);
}

void tartechauffee(Perso *P1, Perso equipe[3]) {
    if (P1->chaud == 1) {
        printf("%s est bien chaud ! Il prépare une tarte aux pommes !\n", P1->nom);
        for (int i = 0; i < 3; i++) {
            equipe[i].pv += 30;
            printf("%s est motivé et soigné grâce à la tarte ! (PV +30)\n", equipe[i].nom);
        }
        P1->chaud = 0;
    } else {
        printf("%s n'est pas chaud ! Il faut préchauffer avant de cuire la tarte.\n", P1->nom);
    }
}

//Capacités de URSSAF
void saisi_de_bien(Perso *P1, Perso *P2) {
    P2->confus = 1;
    printf("%s vole le meuble préféré de %s ! Crise émotionnelle, confusion !\n", P1->nom, P2->nom);
}

void impots_surprises(Perso *P1, Perso equipe[3]) {
    for (int i = 0; i < 3; i++) {
        equipe[i].dette_fiscale = 1;
        printf("%s déclenche un contrôle fiscal ! %s a maintenant une dette !\n", P1->nom, equipe[i].nom);
    }
}

//Capacités  de Garen
void grosse_epee(Perso *P1, Perso *P2) {
    int degats = 100;
    P2->pv -= degats;
    printf("%s frappe %s avec sa grosse épée et ignore la défense, infligeant %d dégâts bruts !\n", P1->nom, P2->nom, degats);
}

void bouclier(Perso *P1) {
    P1->def += 10;
    printf("%s lève son bouclier. Défense augmentée !\n", P1->nom);
}

//Capacités de Serpent Malicieux
void morsure(Perso *P1, Perso *P2) {
    int degats = 10;
    P2->pv -= degats;
    P2->poison = 1;
    printf("%s mord %s, inflige %d dégâts et empoisonne !\n", P1->nom, P2->nom, degats);
}

void vol_donnees(Perso *P1, Perso *P2) {
    P2->dette_fiscale = 1;
    printf("%s vole les données de %s ! Dette fiscale activée !\n", P1->nom, P2->nom);
}

//Capacités de ambulance
void sirene(Perso *P1, Perso equipe[3]) {
    for (int i = 0; i < 3; i++) {
        equipe[i].vit += 10;
        printf("%s déclenche sa sirène : %s devient prioritaire (vit +10) !\n", P1->nom, equipe[i].nom);
    }
}

void soin_urgence(Perso *P1, Perso *P2) {
    P2->pv += 40;
    P2->confus = 1;
    printf("%s soigne %s (PV +40) mais le rend confus à cause de la conduite !\n", P1->nom, P2->nom);
}
//Reste a definir poison et dette fiscale
