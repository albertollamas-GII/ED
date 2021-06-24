/**
 * @file pila_max_vd.h
 * @brief Fichero cabecera del TDA Pila_max
 * @author Elena Ortega, Alberto Llamas
 *
 */

#ifndef _PILA_MAX_VD
#define _PILA_MAX_VD

#include <cassert>
#include <vector>
#include <iostream>
using namespace std;
/**
 * @brief struct Elemento
 * Una instancia @e p del tipo Elemento es un elemento formado por el valor asociado
 * a @c Elemento y el maximo de todos los Elementos almacenados
 *
 */
struct Elemento {
    /**
     * repConjunto Representacion del struct Elemento
     * 
     */
    int ele = 0; /**< valor del elemento a almacenar */
    int maximo = 0; /**< valor del máximo almacenado en la pila */
};

/**
 * @brief Sobrecarga del operador <<
 * @param os Flujo de salida
 * @param e @c Elemento a escribir
 * @post Se obtiene en \a os la cadena "( ele | maximo )" con \e ele,maximo los valores
 *   del elemento a almacenar y el máximo hasta el momento de \a e
 */
inline ostream & operator<<(ostream &os, const Elemento &e) {
    return os << "( " << e.ele << " | " << e.maximo << " )" << endl;
}

/**
 * @brief T.D.A. Pila_max
 *
 * Una instancia @e c del tipo de datos abstracto @c Pila_max es una lista de elementos que
 * que representa un conjunto de parejas de enteros que funciona siguiendo
 * la politica @e LIFO donde el primer elemento es un valor insertado y el 
 * segundo elemento es el máximo de los elementos en la pila. Esta secuencia de valores
 * esta diseñada para realizar inserciones y borrados por uno de sus extremos que se 
 * denomina @e tope. Una pila de longitud n se representa de la forma,
 * 
 * {a1,a2,a3,...an}
 * 
 * donde @e ai representa el @e Elemento de la posicion i-esima.
 * 
 * Un ejemplo de su uso:
 * @include usopilas_max.cpp
 * 
 * @author Elena Ortega y Alberto Llamas
 * @date Noviembre 2020
 * 
 * Para esta representacion de la Pila, se ha utilizado un vector de la clase <vector>
 * de la STL donde el @e tope se encuentra en la ultima posicion ocupada del vector
 * 
 */

class Pila_max {
private:
    /**
     * @page repConjunto Rep del TDA Pila_max basándopse en la clase <vector>
     * de la STL
     * 
     * @section invPila_max Invariante de la representacion
     * El invariante es:
     * - @c rep.datos.size() >= 0
     * 
     * @section faPila_max Funcion de abstraccion
     * 
     * Un objeto valido @e del TDA Pila_max representa una lista de elementos
     * formada por el maximo hasta el momento y el elemento de la pila en la posicion n
     * 
     * (rep.datos)
     */

    vector<Elemento> datos; /**< vector dinamico que representa la pila */
public:
    /**
     * @brief Devuelve el elemento del tope de la pila
     */
    Elemento& tope();

    /**
     * @brief Devuelve el elemento del tope de la pila (versión const)
     */
    const Elemento& tope() const;

    /**
     * @brief Elimina el elemento en el tope de la pila
     */
    void quitar();

    /**
     * @brief Pone un nuevo elemento en el tope de la pila
     * @param x elemento a insertar
     */
    void poner(int x);

    /**
     * @brief Comprobar si la pila está vacía
     */
    bool vacia()const;

    /**
     * @brief Devuelve el número de elementos que tiene la pila
     */
    int size() const;

};

#endif //_PILA_MAX_VD
