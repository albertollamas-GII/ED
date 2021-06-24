#include <iostream>
#include <stack>
#include "Cola_max_pil.h"
using namespace std;

template <class T>
void Cola_max<T>::poner(T dato){
    pila1.Push(dato);
}

template <class T>
int Cola_max<T>::num_elementos() const{
    int numero;
    if(pila1.Empty())
        numero=pila2.Size();
    else
        numero=pila1.Size();
    return numero;
}

template <class T>
T Cola_max<T>::frente(){
    if(pila2.Empty()){
        while(!pila1.Empty()){
            pila2.Push(pila1.Top());
            pila1.Pop();
        }
    }
    return pila2.Top();
            
}


template <class T>
bool Cola_max<T>::vacia(){
    return pila1.Empty() && pila2.Empty();
}

template <class T>
void Cola_max<T>::quitar(){
    if(pila2.Empty()){
        while(!pila1.Empty()){
            pila2.Push(pila1.Top());
            pila1.Pop();
        }
    }
    pila2.Pop();
}

template <class T>
T Cola_max<T>::maximo(){
    T maximo=0;
    if(pila1.maximo()>pila2.maximo())
        maximo=pila1.maximo();
    else
        maximo=pila2.maximo();
    return maximo;
}

