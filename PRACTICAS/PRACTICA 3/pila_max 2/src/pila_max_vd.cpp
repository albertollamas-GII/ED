/**
 * @file pila_max_vd.cpp
 * @brief implementacion del TDA Pila_max como un vector de la STL
 * @author Elena Ortega, Alberto Llamas
 *
 */

#include "pila_max_vd.h"
#include <cassert>
#include <iostream>
#include <vector>


/* _________________________________________________________________________ */

const Elemento& Pila_max::tope() const{
    
    return datos[datos.size()-1];
}
/* _________________________________________________________________________ */

Elemento& Pila_max::tope(){
    
    return datos[datos.size()-1];
}

/* _________________________________________________________________________ */

void Pila_max::quitar(){
    datos.pop_back();
}

/* _________________________________________________________________________ */

void Pila_max::poner(int x){
    Elemento a;
    a.ele=x;
    Elemento b;
    if (datos.size() == 0){
        b.ele = 0;
        b.maximo = 0;
    } else {
        b=tope();
    }
    
    if(b.maximo<x)
        a.maximo=x;
    else
        a.maximo=b.maximo;
    datos.push_back(a);
}

/* _________________________________________________________________________ */

bool Pila_max::vacia()const{
    return datos.empty();
}

/* _________________________________________________________________________ */

int Pila_max::size()const{
    return datos.size();
}
