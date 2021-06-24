/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * @file imagen.h
 * @brief Fichero cabecera del TDA Imagen
 * @author Elena Ortega, Alberto Llamas
 *
 */

#ifndef IMAGEN_H
#define IMAGEN_H

#include "imagenES.h"
#include <iostream>

/**
 * @brief T.D.A. Imagen
 *
 * Una instancia @e c del tipo de datos abstracto @c Imagen es un objeto que
 * que representa una matriz 2D donde cada elemento, img(filas,cols), corresponde 
 * al pixel de una imagen que representa un valor de luminosidad entre 0 y 255.
 * El tipo aociado a cada pixel en un objeto de tipo imagen será un byte,
 * de tipo usigned char.
 * 
 * 
 * img[filas][cols]
 * 
 * Un ejemplo de su uso:
 * @include usoimagen.cpp
 * 
 * @author Elena y Alberto
 * @date Octubre 2020
 * 
 */
typedef unsigned char byte;

class Imagen {
    
private:
 /**
  * @page repImagen Rep del TDA Imagen
  * 
  * @section invImagen Invariante de la representacion
  * El invariante es: 
  * - @c rep.filas>0
  * - @c rep.cols>0
  * - @c 255>=rep.img[filas][cols]>=0
  * 
  * @section faImagen Funcion de abstraccion
  * 
  * Un objeto válido @e del TDA Imagen representa a la matriz de dimensiones
  * @e filas x @e cols 
  * 
  * (rep.img[rep.filas][rep.cols])
  */

    int filas; /**< filas */
    int cols; /**< columnas */
    byte **img;
    
    /**
     * @brief Copia de una imagen en otra
     * @param I.filas número filas de la imagen a copiar
     * @param I.cols número de columnas de la imagen a copiar
     */
    void Copiar(const Imagen &I);
    
    /**
     * @brief Borra una imagen
     */
    void Borrar();
    
    /**
     * @brief Reserva de espacio de memoria dinámica 
     * @param filas número de filas a reservar de una imagen
     * @paran cols número de columnas a reservar de una imagen
     * @pre filas y cols deben ser mayores de 0
     */
    void Reservar(int filas, int cols);

    
public:
    // --------------- Constructores ---------------
    /**
     * @brief Constructor por defecto de la clase. Representa al pixel img[0][0]
     */
    Imagen();
    
    /**
     * @brief Constructor por parámetros de la clase imagen
     * @param nf número de filas de la imagen a construir
     * @param nc número de columnas de la imagen a construir
     * @pre filas y columnas deben ser mayores de 0
     */
    Imagen(int nf, int nc);
    
    /**
     * @brief Constructor de copia de la clase
     * @param I.filas número filas de la imagen a construir
     * @param I.cols número de columnas de la imagen a construir
     * @param I.img puntero que apunta a los elementos de la imagen a construir
     */
    Imagen(const Imagen &I);
    
    // --------------- Destructor ---------------
    /**
     * @brief Destructor de la clase
     */
    ~Imagen();
    
    // --------------- Otras funciones ---------------
    /**
     * @brief Asigna una imagen (sus elementos) a otra
     * @param I imagen a asignar al objeto implícito
     */
    Imagen & operator=(const Imagen &I);
    
    /**
     * @brief Filas
     * @return Devueleve el número de filas de la imagen
     * @note La imagen no se modifica 
     */
    int numfilas() const { return filas;};
    
    /**
     * @brief Columnas
     * @return Devuelve el número de columnas de la imagen
     * @note La imagen no se modifica 
     */
    int numcolumnas() const { return cols;};
    
    /**
     * @brief Asignación de un píxel
     * @param f fila del píxel al que asignamos el valor
     * @param c columna el pixel al que asignamos el valor
     * @param v valor del píxel a asignar
     * @pre valor debe estar entre 0 y 255, fila (f) debe ser mayor de 0 y menor
     *      que el numero de filas total, y columna (c) debe ser mayor de 0 y
     *      menor del numero de columnas total
     */
    void asigna_pixel(int f, int c, byte v);
    
    /**
     * @brief Devuelve el píxel en la fila f y columna c
     * @param f filas
     * @param c columnas
     * @pre fila (f) debe ser mayor de 0 y menor que el numero de filas total, 
     *      y columna (c) debe ser mayor de 0 y menor del numero de columnas total
     * @return Devuelve el valor de luminosidad de la fila y columna indicados
     */
    byte get_pixel(int f, int c) const;
    
    /**
     * @brief Acceso a un píxel (sobrecarga operator()) modificación y consulta
     * @param i fila del píxel al que se accede
     * @param j columna del píxel al que se accede
     * @pre fila (f) debe ser mayor de 0 y menor
     *      que el numero de filas total, y columna (c) debe ser mayor de 0 y
     *      menor del numero de columnas total
     */
    byte & operator()(int i, int j);
    
    /**
     * @brief Acceso a un píxel (sobrecarga operator())
     * @param i fila del píxel al que se accede
     * @param j columna del píxel al que se accede
     * @note versión const para acceso a un píxel
     */
    const byte &operator()(int i, int j) const;
    
    /**
     * @brief Carga en memoria un objeto imagen a partir de un fichero en disco
     * @param nombre nombre del fichero
     */
    bool CargarImagen(const char * nombre);
    
    /**
     * @brief Escribe en un fichero el contenido de la imagen
     * @param nombre nombre del fichero
     */
    bool SaveImagen(const char * nombre);
    
};

#endif /* IMAGEN_H */

