#include <iostream>
#include <stack>
#include <utility>
#include "Pila_maximo.h"

using namespace std;


#ifndef COLA_MAX_PIL_H
#define COLA_MAX_PIL_H

template <typename T>
class Cola_max{
    private:
        Pila_maximo<T> pila1;
        Pila_maximo<T> pila2;
    public:
        /**
         * @brief Inserta el dato dado como parámetro
         * @param dato
         */
        void poner(T dato);
        /**
         * @brief Obtiene el máximo de los elementos de la cola
         * @return máximo 
         */
        T maximo();
        /**
         * @brief Obtiene el número de elementos de la cola
         * @return número de elementos
         */
        int num_elementos() const;
        /**
         * @brief Consulta el frente de la cola
         * @return frente
         */
        T frente();
        /**
         * @brief Elimina un elemento de la cola por delante
         */
        void quitar();
        /**
         * @brief Consulta si la cola está vacía
         * @return vacía o no vacía
         */
        bool vacia();
            
};

#include "Cola_max_pil.cpp"


#endif /* COLA_MAX_PIL_H */

