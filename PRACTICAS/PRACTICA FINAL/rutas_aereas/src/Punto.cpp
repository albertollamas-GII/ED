/**
 * @file Punto.cpp
 * @brief implementacion del TDA Punto
 * @author Alberto Llamas, Elena Ortega
 *
 */

#include "Punto.h"
#include <iostream>
#include <cassert>

/**********************************************/

Punto& Punto::operator=(const Punto &p){
    latitud = p.latitud;
    longitud = p.longitud;

    return *this;
}


/**********************************************/

double Punto::getLatitud() const{
    assert(latitud <= 90 || latitud >= -90);
    return latitud;
}

/**********************************************/

double Punto::getLongitud() const{
    assert(longitud <= 180 || longitud >= -180);
    return longitud;
}

/**********************************************/

void Punto::setLatitud(double l){
    assert(l <= 90 || l >= -90);
    this->latitud = l;
}

/**********************************************/

void Punto::setLongitud(double l){
    assert(l <= 180 || l >= -180);
    this->longitud = l;
}

/**********************************************/

bool Punto::operator<(const Punto &p) const{
    if (latitud < p.latitud && longitud == p.longitud)
        return true;
    else if (latitud == p.latitud && longitud < p.longitud)
        return true;
    //else if (latitud < p.latitud && longitud < p.longitud)
    //    return true;
    else
        return false;
}

/**********************************************/

bool Punto::operator==(const Punto &p) const{
    if (latitud == p.latitud && longitud == p.longitud)
        return true;
    else
        return false;
}

/**********************************************/

istream &operator>>(istream &is, Punto &p){

    is.ignore(100,'(');
    is >> p.latitud;
    is.ignore(100,',');
    is >> p.longitud;
    is.ignore(100,')');

    return is;
}
//*/
/**********************************************/

ostream &operator<<(ostream &os, const Punto &p){
    os << "(" << p.latitud << "," << p.longitud << ")";
    return os;
}
