Perso determinerAttaquant(Equipe e1, Equipe e2){
    Perso P;
    int i;
    P.vitact = 0;
    for(i=0; i<6; i++){
            e1.membres[i].vitact = (e1.membres[i].vitact + e1.membres[i].vit)%150;
    }
    for(i=0; i<6; i++){
            e2.membres[i].vitact = (e1.membres[i].vitact + e1.membres[i].vit)%150;
    }
    for(i=0; i<3; i++){
            if(e1.membres[i].vitact > P.vitact){
                    P = (e1.membres[i]);
            }
    }
    for(i=0; i<3; i++){
            if(e2.membres[i].vitact > P.vitact){
                    P = (e1.membres[i]);
            }
    }
    return P;
}