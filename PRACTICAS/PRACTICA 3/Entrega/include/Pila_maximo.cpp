#include <utility>
#include <stack>

#include "Pila_maximo.h"
using namespace std;

template<class T>
bool Pila_maximo<T>::Empty()const{
    return pilamax.empty();
}

template<class T>
int Pila_maximo<T>::Size() const{
    return pilamax.size();
}

template<class T>
T Pila_maximo<T>::Top(){
    return pilamax.top().first;
}

template<class T>
T Pila_maximo<T>::maximo(){
    T maximo=0;
    if(!pilamax.empty())
        maximo=pilamax.top().second;
    return maximo;
}

template<class T>
void Pila_maximo<T>::Push(T elemento){
    pair<T,T> aux;
    aux.first=elemento;
    if(pilamax.empty()){
        aux.second=elemento;
        pilamax.push(aux);
    }
    else{
        pair <T,T> par;
        par=pilamax.top();
        if(par.second>elemento)
            aux.second=par.second;
        else
            aux.second=elemento;
        pilamax.push(aux);
    }
}

template<class T>
void Pila_maximo<T>::Pop(){
    pilamax.pop();
}