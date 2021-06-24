#include <iostream>
#include <climits>
#include <cassert>
#include "../include/pila_max_VD.h"

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
  return elementos.esta_vacio();
}

Elemento& PilaMax:: tope(){
  assert(!elementos.esta_vacio());
  return elementos[elementos.getUtilizados()-1];
}

const Elemento& PilaMax:: tope() const{
  return elementos[elementos.getUtilizados()-1];
}

void PilaMax:: poner(const int &n){

  int mayor = n > maximo()?n:maximo();

  Elemento p;
  p.valor = n;
  p.max = mayor;

  elementos.aniade(p);
}

void PilaMax:: quitar(){

  assert(!elementos.esta_vacio());
  elementos.elimina(elementos.getUtilizados()-1);
}

int PilaMax:: getNelementos() const{
  return elementos.getUtilizados();
}

int PilaMax:: maximo() const{

  if(elementos.esta_vacio()) return INT_MIN;
    return tope().max;
}
