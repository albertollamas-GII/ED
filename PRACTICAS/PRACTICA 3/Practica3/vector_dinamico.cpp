/**
  * @file vector_dinamico.cpp
  * @brief Implementación del TDA VectorDinámico
  *
  */
#include <cassert>
#include <vector_dinamico.h>

/* _________________________________________________________________________ */

Vector_Dinamico::Vector_Dinamico(int n) 
{
  assert(n>=0);
  if (n>0)
    datos= new float[n];
  nelementos= n;
}
/* _________________________________________________________________________ */

Vector_Dinamico::Vector_Dinamico(const Vector_Dinamico& original) 
{
  nelementos= original.nelementos;
  if (nelementos>0) {
    datos= new float[nelementos];
    for (int i=0; i<nelementos;++i)
      datos[i]= original.datos[i];
  }
  else datos=0;
}
/* _________________________________________________________________________ */

Vector_Dinamico::~Vector_Dinamico() 
{
  if (nelementos>0) delete[] datos;
}
/* _________________________________________________________________________ */

int Vector_Dinamico::size() const 
{ 
  return nelementos; 
}
/* _________________________________________________________________________ */

float& Vector_Dinamico::operator[] (int i) {
  
  assert (0<=i && i<nelementos);
  return datos[i];
}
/* _________________________________________________________________________ */

const float& Vector_Dinamico::operator[] (int i) const 
{
  assert (0<=i && i<nelementos);
  return datos[i];
}
/* _________________________________________________________________________ */

void Vector_Dinamico::resize(int n) 
{
  assert (n>=0);
  if (n!=nelementos) {
    if (n!=0) {
      float * nuevos_datos;
      nuevos_datos= new float[n];
      if (nelementos>0) {
	int minimo;
	minimo= nelementos<n?nelementos:n;
	for (int i= 0; i<minimo;++i)
	  nuevos_datos[i]= datos[i];
	delete[] datos;
      }
      nelementos= n;
      datos= nuevos_datos;
    }
    else {
      if (nelementos>0)
	delete[] datos;
      datos= 0;
      nelementos= 0;
    }
  }
}
/* _________________________________________________________________________ */

Vector_Dinamico& Vector_Dinamico::operator= (const Vector_Dinamico& original) 
{
  if (this!= &original) {
    if (nelementos>0) delete[] datos;
    nelementos= original.nelementos;
    datos= new float[nelementos];
    for (int i=0; i<nelementos;++i)
      datos[i]= original.datos[i];
  }
  return *this;
}
/* _________________________________________________________________________ */

void Vector_Dinamico::poner(float valor)
{
  nelementos++;
  resize(nelementos);
  datos[size()-1] = valor;

}
/* _________________________________________________________________________ */

void Vector_Dinamico::borrar (int pos){

  assert (pos >= 0 && pos < size());

  for (int i = pos; i < nelementos-1; i++)
    datos[i] = datos[i+1];

  resize(nelementos-1);    

}

float & Vector_Dinamico::tope(){
  assert(size()>0);
  return datos[0];
}

bool Vector_Dinamico::vacia(){
  return (size() == 0);
}
