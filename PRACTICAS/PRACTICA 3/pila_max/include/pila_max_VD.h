/**
 * @file pila_max_VD.h
 * @brief Fichero cabecera del TDA Pila
 *
 * Gestiona una secuencia de elementos con facilidades para la inserción y
 * borrado de elementos en un extremo
 *
 */

#ifndef __PilaMax_VD__
#define __PilaMax_VD__

#include <cassert>
#include <iostream>
#include "VDG.h"

/**
 * @brief struct Elemento
 * Una instancia @e p del tipo Elemento es un elemento formado por el valor
 * asociado dicha @c Elemento y el máximo de los valores de todas las Elementos
 * almacenadas
 */
struct Elemento{
   /**
     * @page repConjunto Representativo del struct Elemento
     *
     */
  int valor = 0;   /**< valor del elemento */
  int max = 0;     /**< valor máximo almacenado en la pila */
 };

 /**
   * @brief Sobrecarga del operador <<
   * @param flujo Flujo de salida
   * @param p @c Elemento que se quiere escribir
   */
ostream& operator << (ostream &flujo, const Elemento &p);

/**
 *  @brief T.D.A. PilaMax
 *
 * Una instancia @e v del tipo de datos abstracto Pila sobre el tipo @c T es
 * una lista de elementos del mismo con un funcionamiento @e LIFO (Last In,
 * First Out). En una pila, las operaciones de inserción y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila de longitud
 * @e n la denotamos

 * - [a1,a2,a3,..,an>

 * donde @e ai es el elemento de la posición i-ésima.

 * En esta pila, tendremos acceso únicamente al elemento del @e Tope, es decir,
 * a @e an. El borrado o consulta de un elemento será sobre  @e an, y la
 * inserción de un nuevo elemento se hará sobre éste. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila está vacía.

 * El espacio requerido para el almacenamiento es O(n). Donde n es el número de
 * elementos de la Pila.
 *
 * Además, esta Pila almacena Elementos de @b valor @b | @b máximo, donde máximo
 * denota el valor máximo de los elementos inferiores en la Pila. Esto permite
 * conocer el máximo de los valores de la pila en todo momento.
 *
 * Para la implementación de la Pila, se ha usado una estructura VectorDinamico,
 * situando el @e tope de la Pila en la última posición ocupada del Vector.
 *
 * @author Francisco Rodriguez
 * @date Noviembre 2018
 */
class PilaMax{
 private:
   /**
     * @page repConjunto Representativo del TDA PilaMax
     *
     */
  VectorDinamico<Elemento> elementos; /**< VectorDinamico de elementos de la Pila */

 public:
  // ---------------  Constructores ----------------
  /**
   * @brief Constructor por defecto
   */
 PilaMax():elementos(){}
  /**
   * @brief Constructor de copias
   * @param otra La pila de la que se hará la copia.
   */
  PilaMax(const PilaMax & otra);

  // --------------- Otras funciones ---------------
  /**
   * @brief Sobrecarga del operador de asignación
   * @param otra La pila que se va a asignar.
   */
  PilaMax& operator= (const PilaMax& otra);

  /**
   * @brief Comprueba si la pila está vacía
   */
  bool esta_vacia() const;
  /**
   * @brief Devuelve el elemento del tope de la pila
   */
  Elemento& tope ();
  /**
   * @brief Devuelve el elemento del tope de una pila constante
   */
  const Elemento& tope () const;
  /**
   * @brief Añade un elemento "encima" del tope de la pila
   * @param n Elemento que se va a añadir.
   */
  void poner(const int &n);
  /**
   * @brief Quita el elemento del tope de la pila
   */
  void quitar();

  /**
   * @brief Devuelve el número de elementos de la pila
   */
  int getNelementos() const;

  /**
   * @brief Devuelve el valor máximo almacenado en la pila
   */
  int maximo() const;
};

#endif // __PilaMax_VD__
