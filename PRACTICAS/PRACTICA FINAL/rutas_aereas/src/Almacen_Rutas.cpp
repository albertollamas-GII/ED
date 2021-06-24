/**
 * @file Almacen_Rutas.cpp
 * @brief implementacion del TDA Almacen_Rutas
 * @author Alberto Llamas, Elena Ortega
 *
 */

#include "Almacen_Rutas.h"

Ruta Almacen_Rutas::GetRuta(const string &a){
    map<string,Ruta>::const_iterator it = rutas.find(a);
    if (it == rutas.end())
        return Ruta();
    else
    {
        return it->second;
    }
}

/**********************************************/

void Almacen_Rutas::Insertar(const Ruta& R){
    pair<string,Ruta> p(R.getCode(),R);
    rutas.insert(p);

}

/**********************************************/

void Almacen_Rutas::Borrar(const Ruta &R){
    map<string,Ruta>::const_iterator it;
    it = rutas.find(R.getCode());
    if(it != rutas.end())
        rutas.erase(it);
}





