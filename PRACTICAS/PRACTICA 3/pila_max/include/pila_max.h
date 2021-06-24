/**
  * @file pila_max.h
  * @brief Fichero para compilar usopilas_max con VD o con cola.
  *
  */

  /**
    * @author Francisco Rodriguez Jimenez
    * @date Noviembre 2018
    */

#define CUAL_COMPILA 2
#if CUAL_COMPILA == 1
#include "pila_max_VD.h"
#else
#include "pila_max_cola.h"
#endif
