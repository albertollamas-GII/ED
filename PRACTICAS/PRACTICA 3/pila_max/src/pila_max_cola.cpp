#include <iostream>
#include <cassert>
#include <climits>
#include "../include/pila_max_cola.h"

using namespace std;

ostream& operator <<(ostream &flujo, const Elemento &p){
  flujo << "(" << p.valor << " | " << p.max << ")" << "\n";
  return flujo;
}

PilaMax::PilaMax(const PilaMax &otra):elementos(otra.elementos){}

PilaMax& PilaMax::operator= (const PilaMax& otra){
  if(&otra != this)
    elementos=otra.elementos;
  return *this;
}

bool PilaMax::esta_vacia() const{
  return elementos.esta_vacia();
}

Elemento& PilaMax:: tope(){
  return elementos.frente();
}

const Elemento& PilaMax:: tope() const{
  return elementos.frente();
}

void PilaMax:: poner(const int &n){

  int mayor = n > maximo()?n:maximo();

  Elemento p;
  p.valor = n;
  p.max = mayor;

  PilaMax aux(*this);
  elementos.poner(p);

  int num=elementos.num_elementos()-1;

  for(int i=0; i<num; i++){
    elementos.quitar();
  }

  for(int i=0; i<num; i++){
    elementos.poner(aux.tope());
    aux.quitar();
  }
}

void PilaMax:: quitar(){
  elementos.quitar();
}

int PilaMax:: getNelementos() const{
  return elementos.num_elementos();
}

int PilaMax:: maximo() const{

  if(elementos.esta_vacia()) return INT_MIN;
    return tope().max;
}
