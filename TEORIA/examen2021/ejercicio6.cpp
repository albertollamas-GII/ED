void contar(const vector<set<int>> &V, map<int,int> &veces){
    vector<set<int>>::const_iterator itV;
    set<int>::const_iterator itS;
    map<int,int>::iterator itM;
    veces.clear();

    for (itV = V.cbegin(); itV != V.cend(); ++itV){
        for (itS = (*itV).cbegin(); itS != (*itV).cend(); ++itS){
            itM = veces.find(*itS);
            if (itM == veces.end()){
                pair<int,int> inserta;
                inserta.first = *itS;
                inserta.second = 1;
                veces.insert(inserta);
            } else{
                veces[*itS]++;
            }
        }

    }

}