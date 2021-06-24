/**
 * @file Imagen.h
 * @brief Fichero cabecera del TDA Imagen
 * @author Alberto Llamas, Elena Ortega
 *
 */
#ifndef __IMAGEN_H
#define __IMAGEN_H

#include <iostream>
#include "imagenES.h"

/**
 * @brief T.D.A. Imagen
 *
 * Una instancia @e c del tipo de datos abstracto @c Imagen es un objeto que
 * que representa una matriz 2D donde cada elemento, data(nf,nc), corresponde 
 * al pixel de una imagen que representa un valor de luminosidad entre 0 y 255 para
 * el rojo, otro para el color azul, y otro para el verde, además de un valor de 
 * transparencia que indica la relevancia de dicho pixel (si es 0 no es relevante).
 * 
 * 
 * data[nf][nc]
 * 
 * Un ejemplo de su uso:
 * @include pruebaimagen.cpp
 * 
 * @author Elena y Alberto
 * @date Enero 2021
 * 
 */
enum Tipo_Pegado
{
    OPACO,
    BLENDING
};
using namespace std;
struct Pixel
{
    unsigned char r, g, b;
    unsigned char transp; //0 no 255 si
};
class Imagen
{
private:
    /**
    * @page repImagen Rep del TDA Imagen
    * 
    * @section invImagen Invariante de la representacion
    * El invariante es: 
    * - @c rep.nf>0
    * - @c rep.nc>0
    * 
    * @section faImagen Funcion de abstraccion
    * 
    * Un objeto válido @e del TDA Imagen representa a la matriz de dimensiones
    * @e nf x @e nc 
    * 
    * (rep.data[rep.nf][rep.nc])
    */

    Pixel **data;
    int nf, nc;
    
    /**
     * @brief Borra una imagen
     */
    void Borrar();

    /**
     * @brief Copia de una imagen en otra
     * @param I imagen a copiar
     */
    void Copiar(const Imagen &I);

public:
    // --------------- Constructores ---------------
    /**
	 * @brief Constructor por defecto. Representa al pixel data[0][0]
	 */
    Imagen();

    /**
     * @brief Constructor por parámetros de la clase imagen
     * @param f número de filas de la imagen a construir
     * @param c número de columnas de la imagen a construir
     * @pre filas y columnas deben ser mayores de 0
     */
    Imagen(int f, int c);

    /**
     * @brief Constructor de copias de la clase
     * @param I imagen  a construir
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
     * @param I imagen a asignar al objeto implí­cito
     */
    Imagen &operator=(const Imagen &I);

    //set y get
    /**
     * @brief Acceso a un píxel (sobrecarga operator()) modificación y consulta
     * @param i fila del píxel al que se accede
     * @param j columna del píxel al que se accede
     * @pre fila (f) debe ser mayor de 0 y menor
     *      que el numero de filas total, y columna (c) debe ser mayor de 0 y
     *      menor del numero de columnas total
     */
    Pixel &operator()(int i, int j);

    /**
     * @brief Acceso a un píxel (sobrecarga operator())
     * @param i fila del píxel al que se accede
     * @param j columna del píxel al que se accede
     * @note versión const para acceso a un píxel
     */
    const Pixel &operator()(int i, int j) const;

    /**
     * @brief Escribe en un fichero en disco el contenido de la imagen
     * @param nombre nombre del fichero
     */
    void EscribirImagen(const char *nombre);

    /**
     * @brief Lee un objeto imagen a partir de un fichero en disco
     * @param nombre nombre del fichero de la imagen a color
     * @param nombremascara nombre de la imagen máscara, que define la transparencia
     * de la imagen a color (parámetro opcional)
     */
    void LeerImagen(const char *nombre, const string &nombremascara = "");

    /**
     * @brief Pone toda la transparencia a 0 (no relevante)
     */
    void LimpiarTransp();

    /**
     * @brief Filas
     * @return Devueleve el número de filas de la imagen
     * @note La imagen no se modifica 
     */
    int num_filas() const { return nf; }

    /**
     * @brief Columnas
     * @return Devuelve el número de columnas de la imagen
     * @note La imagen no se modifica 
     */
    int num_cols() const { return nc; }

    /**
     * @brief Pega una imagen sobre otra
     * @param posi Posición de fila a partir de la cual se va a hacer el pegado
     * @param posj Posición de columna a partir de la cual se va a hacer el pegado
     * @param I Imagen a pegar
     * @param tippegado si no se especifica, por defecto es pegado de tipo opaco
     */
    void PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tippegado = OPACO);
    
    /**
     * @brief Devuelve una subimagen a partir de una imagen
     * @param posi Posición de fila a partir de la cual se va a extraer la subimagen
     * @param posj Posición de columna a partir de la cual se va a extraer la subimagen
     * @param dimi Número de filas a extraer
     * @param dimj Número de columnas a extraer
     */
    Imagen ExtraeImagen(int posi, int posj, int dimi, int dimj);
};

#endif

/** Fin fichero: Imagen.h **/