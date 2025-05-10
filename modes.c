void modeFacil(Equipe eq1, Equipe eq2){

    int rdmcible, i, conf, action, defaite;
    Perso* attaquant;
    Perso* cible;
    attaquant = NULL;
    cible = NULL;

    do{
        affiche(eq1, eq2);
        attaquant = &(determinerAttaquant(eq1, eq2));

        if(attaquant->endormi == 1){
                printf("%s est endormi, il n'a pas pu attaquer\n", attaquant->nom);
                attaquant->endormi = 0;
                attaquant = &(determinerAttaquant(eq1, eq2));
        }

        if(attaquant->confus == 1){
                srand(time(NULL));
                conf = rand()%3;
                if(conf == 1){
                        printf("%s est confus, il se blesse tout seul et ne peut plus attaquer. %s perd 30 pv\n", attaquant->nom, attaquant->nom);
                        attaquant->pv -= 30;
                        attaquant->confus = 0;
                        attaquant = &(determinerAttaquant(eq1, eq2));
                }
                else{
                        printf("%s surmonte sa confusion!\n", attaquant->nom);
                        attaquant->confus = 0;
                }
        }

        if(attaquant->poison == 1){
                printf("% est empoisonné, il perd 20 pv\n", attaquant->nom);
                attaquant->pv -= 20;
        }

        if(attaquant->c1.cooldown > 0){
            attaquant->c1.cooldown -= 1;
        }
        if(attaquant->c2.cooldown > 0){
            attaquant->c2.cooldown -= 1;
        }

        if(attaquant->eqpId == 2){
            srand(time(NULL));
            rdmcible = rand()%3 + 1;
            for(i=0; i<3; i++){
                if(rdmcible == eq1.membres[i].id){
                    eq1.membres[i].pv -= 30;
                    printf("%s attaque %s ce qui lui fait perdre 30 pv\n", attaquant->nom, eq1.membres[i].nom);
                }
            }
        }
        else{
            afficheAction(attaquant);
            scanf("%d", &action);

            do{
                    printf("Veillez coisir votre action avec 1, 2 ou 3\n");
                    scanf("%d", &action);
            }while(action != (1 && 2 && 3));

            if(action == 2){
                    if(attaquant->c1.cooldown != 0){
                            do{
                                    printf("Cette action ne peut être utilisé que dans %d tour(s), choisissez une autre action\n", attaquant->c1.cooldown);
                                    scanf("%d", &action);
                            }while(action != 2); 
                    }
            }
            if(action == 3){
                    if(attaquant->c2.cooldown != 0){
                            do{
                                    printf("Cette action ne peut être utilisé que dans %d tour(s), choisissez une autre action\n", attaquant->c2.cooldown);
                                    scanf("%d", &action);
                            }while(action != 3); 
                    }
            }

            cible = &(quiAttaquer(eq1, eq2));

            if(action == 1){
                    cible->pv -= 30;
                    printf("%s attaque %s ce qui lui fait perdre 30 pv\n", attaquant->nom, cible->nom);
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

                            case 6 : sirene(attaquant, cible);
                            break;

                            default : printf("Erreur\n");
                    }
        }
            else{
                    switch(attaquant->c1.id){

                            case 1 :impots_surprises(attaquant, cible);
                            break;

                            case 2 : pika_pika(attaquant, cible);
                            break;

                            case 3 : bouclier(attaquant, cible);
                            break;

                            case 4 : vol_donnees(attaquant, cible);
                            break;

                            case 5 : tartechauffee(attaquant);
                            break;

                            case 6 : soin_urgence(attaquant, cible);
                            break;

                            default : printf("Erreur\n");  

                    }
            }
        }

        defaite = perdu(eq1, eq2);
    }while(defaite = 0);

    if(defaite = 1){
        printf("%s a perdu!\n", eq1.nom);
    }
    else{
        printf("%s a perdu!\n", eq2.nom);
    }
}

void modeNormal(Equipe eq1, Equipe eq2){

    int rdmcible, i, conf, action, defaite;
    Perso* attaquant;
    Perso* cible;
    attaquant = NULL;
    cible = NULL;

    do{
        affiche(eq1, eq2);
        attaquant = &(determinerAttaquant(eq1, eq2));

        if(attaquant->endormi == 1){
                printf("%s est endormi, il n'a pas pu attaquer\n", attaquant->nom);
                attaquant->endormi = 0;
                attaquant = &(determinerAttaquant(eq1, eq2));
        }

        if(attaquant->confus == 1){
                srand(time(NULL));
                conf = rand()%3;
                if(conf == 1){
                        printf("%s est confus, il se blesse tout seul et ne peut plus attaquer. %s perd 30 pv\n", attaquant->nom, attaquant->nom);
                        attaquant->pv -= 30;
                        attaquant->confus = 0;
                        attaquant = &(determinerAttaquant(eq1, eq2));
                }
                else{
                        printf("%s surmonte sa confusion!\n", attaquant->nom);
                        attaquant->confus = 0;
                }
        }

        if(attaquant->poison == 1){
                printf("% est empoisonné, il perd 20 pv\n", attaquant->nom);
                attaquant->pv -= 20;
        }

        if(attaquant->c1.cooldown > 0){
            attaquant->c1.cooldown -= 1;
        }
        if(attaquant->c2.cooldown > 0){
            attaquant->c2.cooldown -= 1;
        }

        if(attaquant->eqpId == 2){
            srand(time(NULL));
            rdmcible = rand()%3 + 1;
            for(i=0; i<3; i++){
                if(rdmcible == eq1.membres[i].id){
                    cible = &(eq1.membres[i]);
                    if(attaquant->c2.cooldown == 0 ){
                        switch(attaquant->c2.id){

                            case 1 :impots_surprises(attaquant, cible);
                            break;

                            case 2 : pika_pika(attaquant, cible);
                            break;

                            case 3 : bouclier(attaquant, cible);
                            break;

                            case 4 : vol_donnees(attaquant, cible);
                            break;

                            case 5 : tartechauffee(attaquant);
                            break;

                            case 6 : soin_urgence(attaquant, cible);
                            break;

                            default : printf("Erreur\n");  

                        }
                    }
                    else if(attaquant->c1.cooldown == 0){
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

                            case 6 : sirene(attaquant, cible);
                            break;

                            default : printf("Erreur\n");
                    }
                    }
                    else{
                        cible->pv -= 30;
                        printf("%s attaque %s ce qui lui fait perdre 30 pv\n", attaquant->nom, cible->nom);

                    }
                }
            }
        }
        else{
            afficheAction(attaquant);
            scanf("%d", &action);

            do{
                    printf("Veillez coisir votre action avec 1, 2 ou 3\n");
                    scanf("%d", &action);
            }while(action != (1 && 2 && 3));

            if(action == 2){
                    if(attaquant->c1.cooldown != 0){
                            do{
                                    printf("Cette action ne peut être utilisé que dans %d tour(s), choisissez une autre action\n", attaquant->c1.cooldown);
                                    scanf("%d", &action);
                            }while(action != 2); 
                    }
            }
            if(action == 3){
                    if(attaquant->c2.cooldown != 0){
                            do{
                                    printf("Cette action ne peut être utilisé que dans %d tour(s), choisissez une autre action\n", attaquant->c2.cooldown);
                                    scanf("%d", &action);
                            }while(action != 3); 
                    }
            }

            cible = &(quiAttaquer(eq1, eq2));

            if(action == 1){
                    cible->pv -= 30;
                    printf("%s attaque %s ce qui lui fait perdre 30 pv\n", attaquant->nom, cible->nom);
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

                            case 6 : sirene(attaquant, cible);
                            break;

                            default : printf("Erreur\n");
                    }
        }
            else{
                    switch(attaquant->c2.id){

                            case 1 :impots_surprises(attaquant, cible);
                            break;

                            case 2 : pika_pika(attaquant, cible);
                            break;

                            case 3 : bouclier(attaquant, cible);
                            break;

                            case 4 : vol_donnees(attaquant, cible);
                            break;

                            case 5 : tartechauffee(attaquant);
                            break;

                            case 6 : soin_urgence(attaquant, cible);
                            break;

                            default : printf("Erreur\n");  

                    }
            }
        }

        defaite = perdu(eq1, eq2);
    }while(defaite = 0);

    if(defaite = 1){
        printf("%s a perdu!\n", eq1.nom);
    }
    else{
        printf("%s a perdu!\n", eq2.nom);
    }
}

void modeDifficile(Equipe eq1, Equipe eq2){

    int rdmcible, i, conf, action, defaite, hp;
    Perso* attaquant;
    Perso* cible;
    attaquant = NULL;
    cible = NULL;

    do{
        affiche(eq1, eq2);
        attaquant = &(determinerAttaquant(eq1, eq2));

        if(attaquant->endormi == 1){
                printf("%s est endormi, il n'a pas pu attaquer\n", attaquant->nom);
                attaquant->endormi = 0;
                attaquant = &(determinerAttaquant(eq1, eq2));
        }

        if(attaquant->confus == 1){
                srand(time(NULL));
                conf = rand()%3;
                if(conf == 1){
                        printf("%s est confus, il se blesse tout seul et ne peut plus attaquer. %s perd 30 pv\n", attaquant->nom, attaquant->nom);
                        attaquant->pv -= 30;
                        attaquant->confus = 0;
                        attaquant = &(determinerAttaquant(eq1, eq2));
                }
                else{
                        printf("%s surmonte sa confusion!\n", attaquant->nom);
                        attaquant->confus = 0;
                }
        }

        if(attaquant->poison == 1){
                printf("% est empoisonné, il perd 20 pv\n", attaquant->nom);
                attaquant->pv -= 20;
        }

        if(attaquant->c1.cooldown > 0){
            attaquant->c1.cooldown -= 1;
        }
        if(attaquant->c2.cooldown > 0){
            attaquant->c2.cooldown -= 1;
        }

        if(attaquant->eqpId == 2){
            hp = 1000;
            for(i=0; i<3; i++){
                if(eq1.membres[i].pv < hp){
                    cible = &(eq1.membres[i]);
                    hp = eq1.membres[i].pv;
                }
            }

        
            if(attaquant->c2.cooldown == 0 ){
                        switch(attaquant->c2.id){

                            case 1 :impots_surprises(attaquant, cible);
                            break;

                            case 2 : pika_pika(attaquant, cible);
                            break;

                            case 3 : bouclier(attaquant, cible);
                            break;

                            case 4 : vol_donnees(attaquant, cible);
                            break;

                            case 5 : tartechauffee(attaquant);
                            break;

                            case 6 : soin_urgence(attaquant, cible);
                            break;

                            default : printf("Erreur\n");  

                        }
                    }
                    else if(attaquant->c1.cooldown == 0){
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

                            case 6 : sirene(attaquant, cible);
                            break;

                            default : printf("Erreur\n");
                    }
                    }
                    else{
                        cible->pv -= 30;
                        printf("%s attaque %s ce qui lui fait perdre 30 pv\n", attaquant->nom, cible->nom);

                    }
        }
            
        
        else{
            afficheAction(attaquant);
            scanf("%d", &action);

            do{
                    printf("Veillez coisir votre action avec 1, 2 ou 3\n");
                    scanf("%d", &action);
            }while(action != (1 && 2 && 3));

            if(action == 2){
                    if(attaquant->c1.cooldown != 0){
                            do{
                                    printf("Cette action ne peut être utilisé que dans %d tour(s), choisissez une autre action\n", attaquant->c1.cooldown);
                                    scanf("%d", &action);
                            }while(action != 2); 
                    }
            }
            if(action == 3){
                    if(attaquant->c2.cooldown != 0){
                            do{
                                    printf("Cette action ne peut être utilisé que dans %d tour(s), choisissez une autre action\n", attaquant->c2.cooldown);
                                    scanf("%d", &action);
                            }while(action != 3); 
                    }
            }

            cible = &(quiAttaquer(eq1, eq2));

            if(action == 1){
                    cible->pv -= 30;
                    printf("%s attaque %s ce qui lui fait perdre 30 pv\n", attaquant->nom, cible->nom);
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

                            case 6 : sirene(attaquant, cible);
                            break;

                            default : printf("Erreur\n");
                    }
        }
            else{
                    switch(attaquant->c2.id){

                            case 1 :impots_surprises(attaquant, cible);
                            break;

                            case 2 : pika_pika(attaquant, cible);
                            break;

                            case 3 : bouclier(attaquant, cible);
                            break;

                            case 4 : vol_donnees(attaquant, cible);
                            break;

                            case 5 : tartechauffee(attaquant);
                            break;

                            case 6 : soin_urgence(attaquant, cible);
                            break;

                            default : printf("Erreur\n");  

                    }
            }
        }

        defaite = perdu(eq1, eq2);
    }while(defaite = 0);

    if(defaite = 1){
        printf("%s a perdu!\n", eq1.nom);
    }
    else{
        printf("%s a perdu!\n", eq2.nom);
    }
}