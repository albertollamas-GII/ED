/**
 * @file Ruta.cpp
 * @brief implementacion del TDA Ruta
 * @author Alberto Llamas, Elena Ortega
 *
 */

#include "Ruta.h"


void Ruta::Insertar(const Punto& n)
{
    puntos.push_back(n);
}

/**********************************************/

void Ruta::Borrar(const Punto &n)
{   
    bool punto_borrado = false;
    list<Punto>::iterator it;
    it = puntos.begin();
    while(it != puntos.end() && !punto_borrado){
        if ((*it)==n){
            it = puntos.erase(it);
            punto_borrado = true;
        }
        else
            ++it;
    }
}


/**********************************************/

bool Ruta::operator==(const Ruta& R) const
{
    return (puntos == R.puntos && code == R.code);
}

/**********************************************/

bool Ruta::operator< (const Ruta &R) const
{
    return (code < R.code);
}

