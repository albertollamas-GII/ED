#include "vector_dinamico.h"
#include <utility>
#ifndef COLA_MAX_VD_H
#define COLA_MAX_VD_H

using namespace std;


template <class T>
class Cola_max{
private:
    Vector_Dinamico<pair<T,T> > vector;
    pair<T,T>* principio;
    pair<T,T>* final;
public:
    /**
     * @brief Constructor sin parámetros
     */
    Cola_max();
    /**
     * @brief Inserta el dato al principio de la cola
     * @param dato
     */
    void poner(T dato);
    /**
     * Obtiene el máximo elemento de la cola
     * @return máximo
     */
    T maximo();
    /**
     * @brief Consulta el número de elementos de la cola
     * @return 
     */
    int num_elementos() const;
    /**
     * @brief Devuelve el frente de la cola
     * @return frente
     */
    T frente();
    /**
     * @brief Devuelve el último elemento de la cola
     * @return 
     */
    T detras();
    /**
     * @brief Elimina el elemento de delante de la cola
     */
    void quitar();
    /**
     * @brief Consulta si la cola está vacía
     * @return vacía o no vacía
     */
    bool vacia();
};

#include "Cola_max_vd.cpp"

#endif /* COLA_MAX_VD_H */

