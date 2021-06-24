/**
 * @file pila_max.h
 * @brief Fichero para compilar usopilas_max.cpp basándose en colas o vectores
 * @author Elena Ortega, Alberto Llamas
 *
 */

#define CUAL_COMPILA 2
#if CUAL_COMPILA==1
#include "pila_max_vd.h"
#elif CUAL_COMPILA==2
#include "pila_max_cola.h"
#endif


