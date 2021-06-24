/**
 * @file Paises.cpp
 * @brief implementacion del TDA Paises
 * @author Alberto Llamas, Elena Ortega
 *
 */

#include "Paises.h"
#include <set>

 
void Paises::Insertar(const Pais &P)
{
    datos.insert(P);
}

/**********************************************/
 
void Paises::Borrar(const Pais &P)
{
    datos.erase(P);
}