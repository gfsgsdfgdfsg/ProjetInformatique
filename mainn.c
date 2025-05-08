int main(){

    int nbjoueurs, action, mode;
    Perso* attaquant;
    Perso* cible;
    Equipe ee1;
    Equipe ee2;
    attaquant = NULL;
    cible = NULL;

    printf("\nBienvenue dans KOMBAT MORTEL!!!\n\n");
    do{
            printf("Combien de joueurs(1 ou 2)?\n");
            scanf("%d", &nbjoueurs);
    } while(nbjoueurs!=1 && nbjoueurs!=2);
    initEquipes(&ee1, &ee2);


    if(nbjoueurs==2){
            affiche(ee1, ee2);
            attaquant = &(determinerAttaquant(ee1, ee2));
            afficheAction(attaquant);
            scanf("%d", &action);
            do{
                    printf("Veillez coisir votre action avec 1, 2 ou 3\n");
                    scanf("%d", &action);
            }while(action != (1 && 2 && 3));

            cible = &(quiAttaquer(ee1, ee2));

            if(action == 1){
                    cible->pv -= 30;
                    printf("%s attaque %s ce qui lui fait perdre 30 pv\n", attaquant->nom, cible->nom);
            }
            else if(action == 2){
        

         
            
            }
            else{

            }
    }

    else{
            do{
            printf("Dans quel mode voulez-vous jouer ?\n [1] Facil\n [2] Normal\n [3] Difficil\n");
            scanf("%d", &mode);
            }while(mode != (1 && 2 && 3));

            if (mode == 1){
                    modeFacil(ee1, ee2);
            }
            else if(mode == 2){
                    modeNormal(ee1, ee2);
            }
            else{
                    modeDifficil(ee1, ee2);
            }
    }

    return 0;
}