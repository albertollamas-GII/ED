/**
 * @file pila_max_cola.cpp
 * @brief implementacion del TDA Pila_max como una cola
 * @author Elena Ortega, Alberto Llamas
 *
 */

#include "pila_max_cola.h"
#include "cola.h"
#include <cassert>
#include <iostream>


/* _________________________________________________________________________ */

Pila_max& Pila_max::operator= (const Pila_max& otro){
    if (&otro != this) {
        datos = otro.datos;
    }

    return *this;
}
/* _________________________________________________________________________ */

const Elemento& Pila_max::tope() const {
    return datos.frente();
}
/* _________________________________________________________________________ */

 Elemento& Pila_max::tope() { //REVISAR
    return datos.frente();
}

/* _________________________________________________________________________ */

void Pila_max::quitar(){
    return datos.quitar();
}

/* _________________________________________________________________________ */

void Pila_max::poner(int x){
    int max, mayor;

    //Buscamos el maximo de la Cola actual, si la Cola esta vacia, le asignamos el valor minimo que hemos considerado que es 0
    if (datos.vacia())
        max = 0;
    else
        max = tope().maximo;
    
    //Si el valor a poner es mayor que el maximo al cual accedemos desde el tope, lo almacenamos en la variable "mayor"
    if (x > max)
        mayor = x;
    else
        mayor = max;

    //Creamos un nuevo elemento con el dato introducido y el maximo de la pila actualmente
    Elemento nuevo;
    nuevo.ele = x;
    nuevo.maximo = mayor;

    Pila_max aux(*this);    //Copiamos en una Pila nueva la pila actual y añadimos el nuevo Elemento
    datos.poner(nuevo);

    int tam = datos.num_elementos() - 1;

    for (int i = 0; i < tam; i++)   //Vaciamos la Pila actual para introducir la pila con el nuevo valor
        datos.quitar();
    
    for(int i = 0; i < tam; i++){
        datos.poner(aux.tope());
        aux.quitar();
    }
}

/* _________________________________________________________________________ */

bool Pila_max::vacia()const{
    return datos.vacia();
}

/* _________________________________________________________________________ */

int Pila_max::size()const{
    return datos.num_elementos();
}
