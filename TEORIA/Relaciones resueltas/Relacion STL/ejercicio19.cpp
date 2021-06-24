#include <iostream>
#include <map>
#include <string>

using namespace std;

//a
int NumElemIntervalo(const string& clave1, const string& clave2, const map<string,int> &MP){
    map<string,int>::const_iterator it, itMin, itMax;
    int NumElem = 0;
    
    for(it = MP.begin(); it != MP.end(); ++it){
        if(clave1 == it->first)
            itMin = it;
        if(clave2 == it->first)
            itMax = it;
    }

    do{
        NumElem++;
        ++itMin;
    }while(itMin != itMax);

    return NumElem;
}

//b
int NumElemIntervalo(const int& clave1, const int& clave2, const map<string,int> &MP){
    map<string,int>::const_iterator it;
    int NumElem = 0;
    
    for(it = MP.begin(); it != MP.end(); ++it){
        if(it->second >= clave1 && it->second <= clave2){
            NumElem++;
        }
    }

    return NumElem;
}