void initEquipes(Equipe *e1, Equipe *e2) {

	int perso1, perso2, perso3, perso4, perso5, perso6, i;
	
	// Compétences
	Comp co1 = {1, "Saisi de Bien", 1.3, "Vol le meuble préféré de l’adversaire (dégâts émotionnels)", 0, 0, 4, 0};
	Comp co2 = {1, "Impôts surprises", 0.0, "Applique une dette fiscale à toute l’équipe adverse", 4, 100, 8, 1};
	Comp co3 = {2, "Eclair au chocolat", 0.8, "Lance des éclairs sur le sol qui font glissés les adversaires et mets confusion", 3, 4, 6, 1};
	Comp co4 = {2, "Pika Pika", 0.0, "Répète Pika Pika ce qui endort l’adversaire", 6, 5, 8, 0};
	Comp co5 = {3, "Grosse épée", 1.5, "Attaque l’adversaire avec sa grosse épée", 0, 0, 5, 0};
	Comp co6 = {3, "Bouclier", 0.0, "Augmente la défense", 7, 5, 6, 2};
	Comp co7 = {4, "Morsure", 1.0, "Attaque l’adversaire et inflige du poison", 1, 4, 5, 0};
	Comp co8 = {4, "Vol de donné", 0.5, "Vol les données bancaires de l’adversaire pour des achats en ligne et applique une dette fiscale", 4, 100, 8, 0};
	Comp co9 = {5, "Préchauffage", 0.0, "Le four préchauffe (aucun effet et aucun dégâts)", 8, 12, 4, 2};
	Comp co10 = {5, "Tarte aux pommes", -1.2, "Si le four est chaud, rend des pv et motive oute l’équipe", 2, 7, 8, 1};
	Comp co11 = {6, "Syrène", 0.0, "Augmente la vitesse des alliés car ils sont désormais prioritaire", 9, 5, 8, 1};
	Comp co12 = {6, "Soin d’urgence", -2.3, "Soigne et rend confus à cause de la conduite catastrophique de l’ambulancier", 3, 8, 12, 0};

	// Personnages
	Perso p1 = {1, 0, "Urssaf", 200, 200, 25, 15, 0, 50, 30, co1, co2, 0, 0, 0, 0};
	Perso p2 = {3, 0, "Pikachu", 140, 140, 30, 20, 0, 55, 25, co3, co4, 0, 0, 0, 0};
	Perso p3 = {2, 0, "Garen", 200, 200, 25, 15, 0, 50, 30, co5, co6, 0, 0, 0, 0};
	Perso p4 = {4, 0, "Serpent Malicieux", 140, 140, 30, 20, 0, 55, 25, co7, co8, 0, 0, 0, 0};
	Perso p5 = {5, 0, "Four", 250, 250, 30, 10, 0, 40, 35, co9, co10, 0, 0, 0, 0};
	Perso p6 = {6, 0, "Ambulance", 250, 250, 30, 10, 0, 40, 30, co11, co1, 0, 0, 0, 0};

        Perso tab[6] = {p1, p2, p3, p4, p5, p6};

        printf("Entrez le nom de vos équipes\n");
        scanf("%s", &e1->nom);
        scanf("%s", &e2->nom);
        printf("\nQuels seront les membres des équipes ?\n\n Choisissez 3 personnages parmis les suivants en entrant le numéro associé (les trois premiers personnages seront dans l'équipe 1 et les trois autres dans l'équipe 2):\n\n [1] Urssaf : un guerrier roublard et sournois\n [2] Garen : un chevalier classique équipé d'une épée et d'un bouclier\n [3] Pikachu : une éspiègle souris jaune\n [4] Serpent Malicieux : un serpent...malicieux\n [5] Four : un outil de cuisine indispenssable\n [6] Ambulance : Citroën jumper L3H2 prête à secourir\n", e1->nom);
        
        scanf("%d %d %d %d %d %d", &perso1, &perso2, &perso3, &perso4, &perso5, &perso6);
        while(perso1==perso2 || perso1==perso3 || perso2==perso3 || perso1 < 1 || perso1 > 6 || perso2 < 1 || perso2 > 6 || perso3 < 1 || perso3 > 6 || perso1==perso4 || perso1==perso5 || perso1==perso6 || perso2==perso4 || perso2==perso5 || perso2==perso6 ||perso3==perso4 || perso3==perso5 || perso3==perso6 || perso4==perso5 || perso4==perso6 || perso5==perso6 || perso4 < 1 || perso4 > 6 || perso5 < 1 || perso5 > 6 || perso6 < 1 || perso6 > 6 ){
                printf("Veuillez choisir 3 personnages différents avec des chiffres entre 1 et 6.\n");
                scanf("%d %d %d %d %d %d", &perso1, &perso2, &perso3, &perso4, &perso5, &perso6);
        }
        
        for(i=0; i<6; i++){
                if(perso1==tab[i].id){
                        e1->membres[0] = tab[i];
                        e1->membres[0].id = 1;
                        e1->membres[0].eqpId = 1;
                }
        }
        for(i=0; i<6; i++){
                if(perso2==tab[i].id){
                        e1->membres[1] = tab[i];
                        e1->membres[1].id = 2;
                        e1->membres[1].eqpId = 1;
                }
        }
        for(i=0; i<6; i++){
                if(perso3==tab[i].id){
                        e1->membres[2] = tab[i];
                        e1->membres[2].id = 3;
                        e1->membres[2].eqpId = 1;
                }
        }

	for(i=0; i<6; i++){
                if(perso4==tab[i].id){
                        e2->membres[0] = tab[i];
                        e2->membres[0].id = 4;
                        e2->membres[0].eqpId = 2;
                }
        }
        for(i=0; i<6; i++){
                if(perso5==tab[i].id){
                        e2->membres[1] = tab[i];
                        e2->membres[1].id = 5;
                        e2->membres[1].eqpId = 2;
                }
        }
        for(i=0; i<6; i++){
                if(perso6==tab[i].id){
                        e2->membres[2] = tab[i];
                        e2->membres[2].id = 6;
                        e2->membres[2].eqpId = 2;
                }
        }
}
                
       

void afficheAction(Perso* p){
        printf("\n");
        printf("\n");
        printf("\nC'est le tour de %s", p->nom);
        printf("\n");
        printf("\n[1] Attaque Normal");
        printf("\n");
        printf("\n[2] %s\n%s", p->c1.nom, p->c1.description);
        printf("\n");
        printf("\n[3] %s\n%s", p->c2.nom, p->c2.description);
        printf("\n");
        printf("\n");
    }


Perso quiAttaquer(Equipe e1, Equipe e2){
        int a;
        printf("\nQui voulez-vous cibler ?\n");
        printf("\n[1] %s\n", e1.membres[0].nom);
        printf("\n[2] %s\n", e1.membres[1].nom);
        printf("\n[3] %s\n", e1.membres[2].nom);
        printf("\n[4] %s\n", e2.membres[0].nom);
        printf("\n[5] %s\n", e2.membres[1].nom);
        printf("\n[6] %s\n", e2.membres[2].nom);
        scanf("%d", &a);
        for(int i=0; i<3; i++){
                if(a == e1.membres[i].id ){
                        return e1.membres[i];
                }
                else if(a == e2.membres[i].id ){
                        return e2.membres[i];
                }
        }
}

void affiche(Equipe e1, Equipe e2){
    int i;
    for(i = 0; i<100; i++){
        printf("-");
    }
    printf("\n");
    printf("%s", e1.nom);
    printf("\n");
    for(i = 0; i<3; i++){
        printf("%s   Vie : %d/%d   Vitesse : %d/150", e1.membres[i].nom, e1.membres[i].pv, e1.membres[i].pvmax, e1.membres[i].vitact);
        printf("\n");
    }
    printf("\n");
    printf("%s", e2.nom);
    printf("\n");
    for(i = 0; i<3; i++){
        printf("%s   Vie : %d/%d   Vitesse : %d/150", e2.membres[i].nom, e2.membres[i].pv, e2.membres[i].pvmax, e2.membres[i].vitact);
        printf("\n");
    }
    for(i = 0; i<100; i++){
        printf("-");
    }
}


Perso determinerAttaquant(Equipe e1, Equipe e2){
        Perso p;
        int i;
        p.vitact = 0;
        for(i=0; i<6; i++){
                e1.membres[i].vitact = (e1.membres[i].vitact + e1.membres[i].vit)%150;
        }
        for(i=0; i<6; i++){
                e2.membres[i].vitact = (e1.membres[i].vitact + e1.membres[i].vit)%150;
        }
        for(i=0; i<3; i++){
                if(e1.membres[i].vitact > p.vitact){
                        p = (e1.membres[i]);
                }
        }
        for(i=0; i<3; i++){
                if(e2.membres[i].vitact > p.vitact){
                        p = (e1.membres[i]);
                }
        }
        return p;
}

int perdu(Equipe e1, Equipe e2){
        if(e1.membres[0].pv <= 0 && e1.membres[1].pv <= 0 && e1.membres[2].pv <= 0){
            return 1;
        }
        else if(e2.membres[0].pv <= 0 && e2.membres[1].pv <= 0 && e2.membres[2].pv <= 0){
            return 2;
        }
        else{
            return 0;
        }
    }
