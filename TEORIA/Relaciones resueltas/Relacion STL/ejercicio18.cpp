#include <iostream>
#include <map>

using namespace std;

map<string,int> si(const map<string,int> &M1, const map<string,int> &M2){
    map<string,int> salida(M1);
    map<string,int>::const_iterator it;
    
    for(it = M2.begin(); it != M2.end();++it){
        if(M1.find(it->first) == M1.end()){
            pair<string,int> p(it->first,it->second);
            salida.insert(p);
        } else {
            map<string,int>::const_iterator its;
            its = salida.find(it->first);
            int suma = it->second + its->second;
            pair<string,int> p(it->first, suma);
            salida.insert(p);
        }
    }

    return salida;
}