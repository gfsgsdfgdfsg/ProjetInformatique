void eclair_au_chocolat(Personnage *attaquant, Personnage *cible) {
    cible->confus = 1;
    printf("%s utilise Éclair au chocolat ! %s est confus !\n", attaquant->nom, cible->nom);
}

void pika_pika(Personnage *attaquant, Personnage *cible) {
    cible->endormi = 1;
    printf("%s crie Pika Pika et ennuie son adversaire ! %s s'endort...\n", attaquant->nom, cible->nom);
}
Capacités du four
void prechauffage(Personnage *four) {
    four->chaud = 1;
    printf("%s commence à préchauffer. Il sera prêt pour la tarte !\n", four->nom);
}
Deuxieme capacité a rajouter (jsp comment faire)
Capacités de l’URSSAF
void saisi_de_bien(Personnage *attaquant, Personnage *cible) {
    cible->confus = 1;
    printf("%s vole le meuble préféré de %s ! Crise émotionnelle, confusion !\n", attaquant->nom, cible->nom);
}

void impots_surprises(Personnage *attaquant, Personnage *equipe) {
    for (int i = 0; i < 3; i++) {
        equipe[i].dette_fiscale = 1;
        printf("%s déclenche un contrôle fiscal ! %s a maintenant une dette !\n", a->nom, equipe[i].nom);
    }
}
Capacités  de Garen
void grosse_epee(Personnage *attaquant, Personnage *cible) {
    int degats =  100;
    cible->pv -= degats;
    printf("%s frappe %s avec sa grosse épée et ignore la défense, infligeant %d dégâts bruts !\n", attaquant->nom, cible->nom, degats);
}

void bouclier(Personnage *attaquant) {
    attaquant->def += 10;
    printf("%s lève son bouclier. Défense augmentée !\n", attaquant->nom);
}

Capacités de Serpent Malicieux
void morsure(Personnage *attaquant, Personnage *cible) {
    int degats = 10;
    cible->pv -= degats;
    cible->poison = 1;
    printf("%s mord %s, inflige %d dégâts et empoisonne !\n", attaquant->nom, cible->nom, degats);
}

void vol_donnees(Personnage *attaquant, Personnage *cible) {
    cible->dette_fiscale = 1;
    printf("%s vole les données de %s ! Dette fiscale activée !\n", attaquant->nom, cible->nom);
}
Capacités de ambulance
void sirene(Personnage *attaquant, Personnage *equipe) {
    for (int i = 0; i < 3; i++) {
        equipe[i].vit += 10;
        printf("%s déclenche sa sirène : %s devient prioritaire (vit +10) !\n", attaquant->nom, equipe[i].nom);
    }
}

void soin_urgence(Personnage *attaquant,Personnage*cible) {
    cible->pv += 40;
    cible->confus = 1;
    printf("%s soigne %s (PV +40) mais le rend confus à cause de la conduite !\n",attaquant ->nom,cible->nom);
}
