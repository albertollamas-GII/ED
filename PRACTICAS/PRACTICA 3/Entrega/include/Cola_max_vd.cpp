#include "vector_dinamico.h"
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include "Cola_max.h"


using namespace std;


template <class T>
Cola_max<T>::Cola_max(){
    vector=0;
    principio=NULL;
    final=NULL;
}

template <class T>
int Cola_max<T>::num_elementos() const{
    return vector.size();
}

template <class T>
bool Cola_max<T>::vacia(){
    return vector.size()==0;
}

template <class T>
void Cola_max<T>::poner(T dato){
    vector.resize(vector.size()+1);
    //cout << "voy a meter " << dato << endl;
    
    if(vector.size()==1){
        vector[vector.size()-1].first=dato;
        vector[vector.size()-1].second=dato;
    }
    else{
        for(int i=0; i<vector.size(); i++){
            //cout << "FORmaximo: " << maximo() << endl;
            if(maximo()>dato){
                vector[vector.size()-1].first=dato;
                vector[vector.size()-1].second=maximo();
               // cout << "maximo: " << maximo() << endl;
            }
            else{
                vector[vector.size()-1].first=dato;
                for(int i=0; i<vector.size(); i++){
                    //cout << "reubicando";
                    vector[i].second=dato;
                }
            }
        }
    }
    //Ajusto los punteros
    principio=&vector[0];
    final=&vector[vector.size()-1];
}

template <class T>
T Cola_max<T>::maximo(){
//    cout << "entro en maximo" << endl;
    T maximo=vector[0].first;
    for(int i=0; i<vector.size(); i++){
        if(vector[i].first>maximo) //cambio second por first
            maximo=vector[i].first;
    }
    return maximo;
}

template <class T>
T Cola_max<T>::frente(){
//    cout << "me meto en frente" << endl;
    assert(vector.size()!=0); //Comprobamos con un assert que hay elementos a comprobar
    return principio->first;
}

template <class T>
T Cola_max<T>::detras(){
    assert(vector.size()!=0); //Comprobamos con un assert que hay elementos a comprobar
    return final->first;
}

template <class T>
void Cola_max<T>::quitar(){
//    cout << "Me meto en quitar " << endl;
    if(vector.size()==1){
        vector=0;
    }
    else{
        for(int i=0; i<vector.size()-1; i++){
            vector[i].first=vector[i+1].first;
            vector[i].second=vector[i+1].second;
        }
        vector.resize(vector.size()-1);
         //Ajusto los punteros
        principio=&vector[0];
        final=&vector[vector.size()-1];
    }
    
}