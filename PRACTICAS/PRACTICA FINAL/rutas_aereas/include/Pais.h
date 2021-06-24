/**
 * @file Pais.h
 * @brief Fichero cabecera del TDA Pais
 * @author Alberto Llamas, Elena Ortega
 *
 */
#ifndef __PAIS_H
#define __PAIS_H
#include "Punto.h"
#include <string>

/**
 * @brief T.D.A. Pais
 * 
 * Una instancia @e c del TDA Pais @c Pais es un objeto que representa
 * un Pais donde cada elemento, pais(punto,pais,bandera) corresponde
 * a un pais formado por su punto en el mapa, su nombre y su bandera
 * 
 * 
 * p(punto,pais,bandera)
 * 
 * @see Punto
 * 
 * 
 * @author Elena y Alberto
 * @date Enero 2021
 * 
 */

class Pais{
private:
    /**
    * @page repPais Rep del TDA Pais
    * 
    * @section invPais Invariante de la representacion
    * El invariante es: 
    * - @c p.bandera != ""
    * - @c p.pais != ""
    * 
    * @section faPais Funcion de abstraccion
    * 
    * Un objeto valido @e p del TDA Pais representa al pais
    * @e p @e pais @e bandera
    * 
    * (rep.punto, rep.pais, rep.bandera)
    */
    Punto p;
    string pais;
    string bandera;

public:
    // --------------- Constructores ---------------
    /**
     * @brief Constructor por defecto de la clase
     */
    Pais() {}
    
    // --------------- Otras funciones ---------------
    /**
     * @brief Consultor punto
     * @return Devuelve el punto del pais (valores de latitud y longitud)
     * @note El pais no se modifica
     */
    Punto GetPunto() const;

    /**
     * @brief Consultor pais
     * @return Devuelve el nombre del pais
     * @note El pais no se modifica
     */ 
    string GetPais() const;

    /**
     * @brief Consultor bandera
     * @return Devuelve el nombre del fichero donde se almacena la bandera del pais
     * @note El pais no se modifica
     */
    string GetBandera() const;

    /**
     * @brief Compara si un pais es menor que otro en base a su nombre
     * @param P pais con el que se compara
     * @return Devuelve true si el pais implícito es menor a @e P
     */
    bool operator<(const Pais &P) const;

    /**
     * @brief Operador de comparación de igualdad
     * @param P pais con el que se compara
     * @return Devuelve true si los dos paises son iguales
     */
    bool operator==(const Pais &P) const;

    /**
     * @brief Operador de comparación de igualdad del punto de un pais
     * @param P punto con el que se compara
     * @return Devuelve true si el punto del pais implícito es igual al punto @e P
     */
    bool operator==(const Punto &P) const;

    /**
     * @brief Operador de entrada. Lectura del pais
     * @param is stream desde el que se lee
     * @param P pais en el que leer
     * @return Devuelve una referencia al flujo de entrada is para permitir el 
     * encadenamiento del operador
     * @note Lee un pais de is y lo almacena en P
     */
    friend istream &operator>>(istream &is, Pais &P)
    {
        double lat, lng;
        string pais, bandera;
        is >> lat >> lng >> pais >> bandera;

        P.p = Punto(lat, lng, "");
        P.pais = pais;
        P.bandera = bandera;
        return is;
    }

    /**
     * @brief Operador de salida. Escritura del pais
     * @param os stream en el que se escribe
     * @param P pais que escribir
     * @return Devuelve una referencia al flujo de salida os para permitir el 
     * encadenamiento del operador
     * @note Escribe un pais en os
     */
    friend ostream &operator<<(ostream &os, const Pais &P)
    {
        os << P.p << " " << P.pais << " " << P.bandera << endl;
        return os;
    }
};
#endif