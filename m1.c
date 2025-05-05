#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nom[32];
	float valeur; // valeur négative ou positive pour dégâts ou soins
	char description[256];
	char effet; //numéro de l'effet
	int toureffet; //nb de tours que dure l'effet
	int couldown; // nb de tours entre deux utilisation de la compétence spécial
	char choix; //numéro de comment la compétence cible
} Comp; //competence

typedef struct{
	int id;
	char nom[32];
	int pvmax;
	int pv;
	int atck;
	int agi;
	int vitact;
	int vit;
	int def;
	Comp c1; //les deux compétences
	Comp c2;
} Perso; //personnage

typedef struct{
	char nom[12];
	Perso membres[3]; //tableau avec les persos
} Equipe; //equipe

void initEquipes(Equipe *e1, Equipe *e2) {
	// Compétences
	Comp co1 = {"Saisi de Bien", 1.3, "Vol le meuble préféré de l’adversaire (dégâts émotionnels)", 0, 0, 4, 0};
	Comp co2 = {"Impôts surprises", 0.0, "Applique une dette fiscale à toute l’équipe adverse", 4, 100, 8, 1};
	Comp co3 = {"Eclair au chocolat", 0.8, "Lance des éclairs sur le sol qui font glissés les adversaires et mets confusion", 3, 4, 6, 1};
	Comp co4 = {"Pika Pika", 0.0, "Répète Pika Pika ce qui endort l’adversaire", 6, 5, 8, 0};
	Comp co5 = {"Grosse épée", 1.5, "Attaque l’adversaire avec sa grosse épée", 0, 0, 5, 0};
	Comp co6 = {"Bouclier", 0.0, "Augmente la défense", 7, 5, 6, 2};
	Comp co7 = {"Morsure", 1.0, "Attaque l’adversaire et inflige du poison", 1, 4, 5, 0};
	Comp co8 = {"Vol de donné", 0.5, "Vol les données bancaires de l’adversaire pour des achats en ligne et applique une dette fiscale", 4, 100, 8, 0};
	Comp co9 = {"Préchauffage", 0.0, "Le four préchauffe (aucun effet et aucun dégâts)", 8, 12, 4, 2};
	Comp co10 = {"Tarte aux pommes", -1.2, "Si le four est chaud, rend des pv et motive oute l’équipe", 2, 7, 8, 1};
	Comp co11 = {"Syrène", 0.0, "Augmente la vitesse des alliés car ils sont désormais prioritaire", 9, 5, 8, 1};
	Comp co12 = {"Soin d’urgence", -2.3, "Soigne et rend confus à cause de la conduite catastrophique de l’ambulancier", 3, 8, 12, 0};

	// Personnages
	Perso p1 = {1, "Urssaf", 200, 200, 25, 15, 0, 50, 30, co1, co2};
	Perso p2 = {3, "Pikachu", 140, 140, 30, 20, 0, 55, 25, co3, co4};
	Perso p3 = {2, "Garen", 200, 200, 25, 15, 0, 50, 30, co5, co6};
	Perso p4 = {4, "Serpent Malicieux", 140, 140, 30, 20, 0, 55, 25, co7, co8};
	Perso p5 = {5, "Four", 250, 250, 30, 0, 0, 40, 35, co9, co10};
	Perso p6 = {6, "Ambulance", 250, 250, 30, 10, 0, 40, 30, co11, co12};

	// Équipes
	*e1 = (Equipe){"Equipe A", {p1, p2, p3}};
	*e2 = (Equipe){"Equipe B", {p4, p5, p6}};
}

void affiche(Equipe e1, Equipe e2){
    int i;
    for(i = 0; i<100; i++){
        printf("-");
    }
    printf("\n");
    printf("Equipe 1");
    printf("\n");
    for(i = 0; i<3; i++){
        printf("%s   Vie : %d/%d   Vitesse : %d/%d", e1.membres[i].nom, e1.membres[i].pv, e1.membres[i].pvmax, e1.membres[i].vitact, 150);
        printf("\n");
    }
    printf("\n");
    printf("Equipe 2");
    printf("\n");
    for(i = 0; i<3; i++){
        printf("%s   Vie : %d/%d   Vitesse : %d/%d", e2.membres[i].nom, e2.membres[i].pv, e2.membres[i].pvmax, e2.membres[i].vitact, 150);
        printf("\n");
    }
    for(i = 0; i<100; i++){
        printf("-");
    }
}

void afficheAction(Perso p){
    printf("\n");
    printf("\n");
    printf("\nC'est le tour de %s", p.nom);
    printf("\n");
    printf("\n[1] Attaque Normal");
    printf("\n");
    printf("\n[2] %s\n%s", p.c1.nom, p.c1.description);
    printf("\n");
    printf("\n[3] %s\n%s", p.c2.nom, p.c2.description);
    printf("\n");
    printf("\n");
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

int peutJouer(Perso *p){
	p->vitact = p->vitact + p->vit;
	if(p->vitact>=150 && p->pv>0){
		p->vitact = p->vitact%150;
		return 1;
	}
	else{
		return 0;
	}
};

int* attaqueQui(Equipe e1, Equipe e2, int num, int choix){  //Pour num 1 = e1.membres[0], 2 = e1.membres[1], num 3 = e1.membres[2], 1 = e2.membres[0], num 2 = e2.membres[1], 3 = e2.membres[2]
    if(choix == 1){
        int rep;
        int* qui = malloc(3 * sizeof(int));
        printf("\n");
        printf("\n");
        printf("\nQuel équipe attaquer ?");
        printf("\n");
        printf("\n[1] Equipe 1");
        printf("\n");
        printf("\n[2] Equipe 2");
        printf("\n");
        printf("\n");
        scanf(" %d", &rep);
        if(rep == 1){
            *qui = 1;
            *(qui+1) = 2;
            *(qui+2) = 3;
        }
        else{
            *qui = 4;
            *(qui+1) = 5;
            *(qui+2) = 6;
        }
        return qui;
    }
    else if(choix == 2){
        int *qui = malloc(sizeof(int));
        *qui = num;
        return qui;
    }
    else{
        int *qui = malloc(sizeof(int));
        printf("\n");
        printf("\n");
        printf("\nQui attaquer ?");
        printf("\n");
        printf("\n[1] %s", e1.membres[0].nom);
        printf("\n");
        printf("\n[2] %s", e1.membres[1].nom);
        printf("\n");
        printf("\n[3] %s", e1.membres[2].nom);
        printf("\n");
        printf("\n[4] %s", e2.membres[0].nom);
        printf("\n");
        printf("\n[5] %s", e2.membres[1].nom);
        printf("\n");
        printf("\n[6] %s", e2.membres[2].nom);
        printf("\n");
        printf("\n");
        scanf(" %d", qui);
        return qui;
    }
}

int main(){
    Equipe ee1;
    Equipe ee2;
    initEquipes(&ee1, &ee2);
    affiche(ee1, ee2);
    printf("%d",*attaqueQui(ee1, ee2, 1, 1));
    return 0;
}
