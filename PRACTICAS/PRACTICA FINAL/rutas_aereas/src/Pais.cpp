/**
 * @file Pais.cpp
 * @brief implementacion del TDA Pais
 * @author Alberto Llamas, Elena Ortega
 *
 */

#include "Pais.h"

 
Punto Pais::GetPunto() const{
    return p; 
}
/**********************************************/
 
string Pais::GetPais() const{
    return pais;
}
/**********************************************/
 
string Pais::GetBandera() const{
    return bandera;
}
/**********************************************/

bool Pais::operator<(const Pais &P) const{
    return (pais < P.pais);
}
/**********************************************/
 
 //revisar --> puede que haya que comparar cada dato miembro
bool Pais::operator==(const Pais &P) const{
    return pais == P.pais;
}
/**********************************************/
 
bool Pais::operator==(const Punto &P) const{
    if (P.getLatitud() == p.getLatitud() && P.getLongitud() == p.getLongitud())
        return true;
    return false;
}