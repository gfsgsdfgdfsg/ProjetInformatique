#include<stdio.h>
#include "structures.h"
#include "capacites.h"
#include "fonctions.h"
#include "modes.h"
#include<time.h>
#include <stdlib.h>

int main(){

    int nbjoueurs, action, mode, defaite, conf;
    Perso* attaquant;
    Perso* cible;
    Equipe* cibles;
    Equipe ee1;
    Equipe ee2;
    attaquant = NULL;
    cible = NULL;
    int g = 0;

    printf("\nBienvenue dans KOMBAT MORTEL!!!\n\n");
    do{
            printf("Combien de joueurs(1 ou 2)?\n");
            scanf("%d", &nbjoueurs);
    } while(nbjoueurs!=1 && nbjoueurs!=2);
    initEquipes(&ee1, &ee2);


    if(nbjoueurs==2){
            do{
                    attaquant = determinerAttaquant(&ee1, &ee2);
                    if(attaquant!=NULL){
                        affiche(ee1, ee2);
                        if(attaquant->endormi == 1){
                                printf("%s est endormi, il n'a pas pu attaquer\n", attaquant->nom);
                                attaquant->endormi = 0;
                                attaquant = determinerAttaquant(&ee1, &ee2);
                        }
    
                        if(attaquant->confus == 1){
                                srand(time(NULL));
                                conf = rand()%3;
                                if(conf == 1){
                                        printf("%s est confus, il se blesse tout seul et ne peut plus attaquer. %s perd 30 pv\n", attaquant->nom, attaquant->nom);
                                        attaquant->pv -= 30;
                                        attaquant->confus = 0;
                                        attaquant = determinerAttaquant(&ee1, &ee2);
                                }
                                else{
                                        printf("%s surmonte sa confusion!\n", attaquant->nom);
                                        attaquant->confus = 0;
                                }
                        }
    
                        if(attaquant->poison == 1){
                                printf("%s est empoisonné, il perd 20 pv\n", attaquant->nom);
                                attaquant->pv -= 20;
                        }
    
                        if(attaquant->c1.cooldown > 0){
                                attaquant->c1.cooldown -= 1;
                        }
                        if(attaquant->c2.cooldown > 0){
                                attaquant->c2.cooldown -= 1;
                        }
                        if(attaquant->eqpId == 2){
                            cibles = &ee1;
                        }
                        else{
                            cibles = &ee2;
                        }
                        afficheAction(attaquant);
                        g = 0;
                        do{
                                printf("Veuillez choisir votre action avec 1, 2 ou 3\n");
                                scanf("%d", &action);
                                g = 1;
                                if(action == 2){
                                    if(attaquant->c1.cooldown != 0){
                                        do{
                                            printf("Cette action ne peut être utilisé que dans %d tour(s), choisissez une autre action\n", attaquant->c1.cooldown);
                                            g = 0;
                                        }while(action != 2); 
                                    }
                                }
                                if(action == 3){
                                    if(attaquant->c2.cooldown != 0){
                                        do{
                                            printf("Cette action ne peut être utilisé que dans %d tour(s), choisissez une autre action\n", attaquant->c2.cooldown);
                                            g = 0;
                                        }while(action != 3); 
                                    }
                                }
                        }while(action != 1 && action != 2 && action != 3 || g == 0);
    
                        
    
                        cible = quiAttaquer(&ee1, &ee2);
    
                        if(action == 1){
                                cible->pv -= attaquant->atck;
                                cible->pv += cible->def;
                                printf("%s attaque %s ce qui lui fait perdre %d pv\n", attaquant->nom, cible->nom, attaquant->atck-cible->def);
                        }
                        else if(action == 2){
                                switch(attaquant->c1.id){
    
                                        case 1 : saisi_de_bien(attaquant, cible);
                                        break;
    
                                        case 2 : eclair_au_chocolat(attaquant, cible);
                                        break;
    
                                        case 3 : grosse_epee(attaquant, cible);
                                        break;
    
                                        case 4 : morsure(attaquant, cible);
                                        break;
    
                                        case 5 : prechauffage(attaquant);
                                        break;
    
                                        case 6 : if(attaquant->eqpId == 2){cibles = &ee2;}else{cibles = &ee1;} sirene(attaquant, cibles);
                                        break;
    
                                        default : printf("Erreur\n");
                                }
                    }
                        else{
                                switch(attaquant->c1.id){
    
                                        case 1 : impots_surprises(attaquant, cibles);
                                        break;
    
                                        case 2 : pika_pika(attaquant, cible);
                                        break;
    
                                        case 3 : bouclier(attaquant);
                                        break;
    
                                        case 4 : vol_donnees(attaquant, cible);
                                        break;
    
                                        case 5 : if(attaquant->eqpId == 2){cibles = &ee2;}else{cibles = &ee1;} tartechauffee(attaquant, cibles);
                                        break;
    
                                        case 6 : soin_urgence(attaquant, cible);
                                        break;
    
                                        default : printf("Erreur\n");  
                                }
                        }
                }
                    defaite = perdu(ee1, ee2);
            }while(defaite == 0);

            if(defaite == 1){
                    printf("%s a perdu!\n", ee1.nom);
            }
            else{
                    printf("%s a perdu!\n", ee2.nom);
            }
    }

    else{
            do{
            printf("Dans quel mode voulez-vous jouer ?\n [1] Facil\n [2] Normal\n [3] Difficil\n");
            scanf("%d", &mode);
            }while(mode != 1 && mode != 2 && mode != 3);

            if (mode == 1){
                    modeFacil(ee1, ee2);
            }
            else if(mode == 2){
                    modeNormal(ee1, ee2);
            }
            else{
                    modeDifficile(ee1, ee2);
            }
    }

    return 0;
}
