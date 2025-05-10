//Capacités de pikachu
void eclair_au_chocolat(Perso *p1, Perso *p2) {
    p2->confus = 1;
    printf("%s utilise Éclair au chocolat ! %s est confus !\n", p1->nom, p2->nom);
    p1->c1.cooldown = 2;
}

void pika_pika(Perso *p1, Perso *P2) {
    P2->endormi = 1;
    printf("%s crie Pika Pika et ennuie son adversaire ! %s s'endort...\n", p1->nom, P2->nom);
    p1->c2.cooldown = 3;
}

//Capacités du four
void prechauffage(Perso *p1) {
    p1->chaud = 1;
    printf("%s commence à préchauffer. Il sera prêt pour la tarte !\n", p1->nom);
    p1->c1.cooldown = 2;
}

void tartechauffee(Perso *p1, Perso equipe[3]) {
    if (p1->chaud == 1) {
        printf("%s est bien chaud ! Il prépare une tarte aux pommes !\n", p1->nom);
        for (int i = 0; i < 3; i++) {
            equipe[i].pv += 30;
            printf("%s est motivé et soigné grâce à la tarte ! (PV +30)\n", equipe[i].nom);
        }
        p1->chaud = 0;
    } else {
        printf("%s n'est pas chaud ! Il faut préchauffer avant de cuire la tarte.\n", p1->nom);
    }
}

//Capacités de URSSAF
void saisi_de_bien(Perso *p1, Perso *p2) {
    p2->confus = 1;
    printf("%s vole le meuble préféré de %s ! Crise émotionnelle, confusion !\n", p1->nom, p2->nom);
    p1->c1.cooldown = 2;
}
void impots_surprises(Perso *p1, Equipe e1) {
    for (int i = 0; i < 3; i++) {
        if (e1.membres[i].atck > 0) {
            e1.membres[i].atck /= 2;
        }
        printf("%s déclenche un contrôle fiscal ! Les membres de l'équipe adverse voient leur attaque divisée par 2 !\n", p1->nom);
    }
    p1->c2.cooldown = 3;
}

//Capacités  de Garen
void grosse_epee(Perso *p1, Perso *p2) {
    int degats = 100;
    p2->pv -= degats;
    printf("%s frappe %s avec sa grosse épée et ignore la défense, infligeant %d dégâts bruts !\n",p1->nom, p2->nom, degats);
    p1->c1.cooldown = 2;
}

void bouclier(Perso *p1) {
    p1->def += 10;
    printf("%s lève son bouclier. Défense augmentée !\n", p1->nom);
    p1->c2.cooldown = 3;
}

//Capacités de Serpent Malicieux
void morsure(Perso *p1, Perso *p2) {
    int degats = 10;
    p2->pv -= degats;
    p2->poison = 1;
    printf("%s mord %s, inflige %d dégâts et empoisonne !\n", p1->nom, p2->nom, degats);
    p1->c1.cooldown = 2;
}
void vol_donnees(Perso *p1, Perso *p2) {
    if (p2->atck > 0) {
        p2->atck /= 2;
    }
    printf("%s vole les données de %s ! Dette fiscale infligée : Attaque divisée par 2 !\n", p1->nom, p2->nom);
    p1->c2.cooldown = 3;
}

//Capacités de ambulance
void sirene(Perso *p1, Equipe e1) {
    for (int i = 0; i < 3; i++) {
        e1.membres[i].vitact += 20;
    }
    printf("%s déclenche sa sirène : son équipe est prioritaire (vit +20) !\n", p1->nom);
    p1->c1.cooldown = 2;
}

void soin_urgence(Perso *p1, Perso *p2) {
    p2->pv += 40;
    p2->confus = 1;
    printf("%s soigne %s (PV +40) mais le rend confus à cause de la conduite !\n", p1->nom, p2->nom);
    p1->c2.cooldown = 3;
}

