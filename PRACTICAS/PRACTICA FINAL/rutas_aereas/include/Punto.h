/**
 * @file Punto.h
 * @brief Fichero cabecera del TDA Punto
 * @author Alberto Llamas, Elena Ortega
 *
 */
#ifndef __PUNTO_H
#define __PUNTO_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief T.D.A. Punto
 * 
 * Una instancia @e c del TDA Punto @c Punto es un objeto que representa
 * un Punto donde cada elemento, punto.latitud, punto.longitud corresponde
 * a un punto formado por su latitud y su longitud
 * 
 * 
 * punto.latitud, punto.longitud
 * 
 * 
 * 
 * @author Elena y Alberto
 * @date Enero 2021
 * 
 */

class Punto{
    private:
    /**
    * @page repPunto Rep del TDA Punto
    * 
    * @section invPunto Invariante de la representacion
    * El invariante es: 
    * @e rep.latitud <= 90 || @e rep.latitud >= -90
    * @e rep.longitud <= 180 || @e rep.longitud >= -180
    * 
    * @section faPunto Funcion de abstraccion
    * 
    * Un objeto valido @e p del TDA Punto representa al punto
    * @e p
    * 
    * (rep.punto.latitud, rep.punto.longitud)
    */
        double latitud, longitud;
    
    public:
    // --------------- Constructores ---------------
    /**
     * @brief Constructor por defecto de la clase
     */
    Punto(){
        latitud = longitud = 0;
    }

    /**
     * @brief Constructor por parámetros de la clase imagen
     * @param l valor de latitud del punto a construir
     * @param L valor de longitud del punto a construir
     * @param d ???
     * @pre latitud debe oscilar entre -90 y 90 y longitud entre -180 y 180
     */
    Punto(double l, double L, const string &d) : latitud(l), longitud(L) {} //, const string &d (Tiene puesto este parametro pero no se para que sirve)
    /**
     * @brief Sobrecarga Operador de Asignacion
     * @param p otro punto a asignar
     * */
    Punto &operator= (const Punto &p);
    // --------------- Otras funciones ---------------
    /**
     * @brief Consultor latitud
     * @return Devuelve el valor de latitud del punto
     * @note El punto no se modifica 
     */
    double getLatitud() const;

    /**
     * @brief Consultor longitud
     * @return Devuelve el valor de longitud del punto
     * @note El punto no se modifica
     */
    double getLongitud() const;

    /**
     * @brief Modificador latitud
     * @param l valor de latitud a modificar
     * @note El punto se modifica
     */
    void setLatitud(double l);

    /**
     * @brief Modificador longitud
     * @param l valor de longitud a modificar
     * @note El punto se modifica
     */
    void setLongitud(double l);

    /**
     * @brief Compara si un punto es menor que otro en base a sus valores de 
     * latitud y longitud
     * @param p punto con el que se compara
     * @return Devuelve true si el punto implícito es menor a @e p
     * @note Si dos puntos tienen igual latitud se compara su longitud
     * @note Si dos puntos tienen igual longitud se compara su latitud
     */
    bool operator < (const Punto& p) const;

    /**
     * @brief Operador de comparación de igualdad
     * @param p punto con el que se compara
     * @return Devuelve true si los dos puntos tienen los mismos valores de
     * latitud y longitud
     */
    bool operator==(const Punto &p) const;

    /**
     * @brief Operador de entrada. Lectura del punto
     * @param is stream desde el que se lee
     * @param p punto en el que leer
     * @return Devuelve una referencia al flujo de entrada is para permitir el 
     * encadenamiento del operador
     * @note Lee un punto de is y lo almacena en p
     */
    friend istream& operator >> (istream &is, Punto &p);

    /**
     * @brief Operador de salida. Escritura del punto
     * @param os stream en el que se escribe
     * @param p punto que escribir
     * @return Devuelve una referencia al flujo de salida os para permitir el 
     * encadenamiento del operador
     * @note Escribe un punto en os
     */
    friend ostream& operator << (ostream &os, const Punto &p);
};
#endif