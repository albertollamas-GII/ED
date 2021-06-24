/** 
 * @file   usoimagen.cpp
 * @brief  Main en el que se muestra el uso de la clase Imagen
 * @author Elena Ortega, Alberto Llamas
 *
 * 
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cassert>
#include "imagen.h"
#include <string>

using namespace std;

/**
 * @brief Crea una imagen de tamaño muy reducido a partir de una imagen original
 * @param fich_orig nombre del fichero que contiene la imagen original
 * @param fich_rdo nombre del fichero donde se guardará el icono
 * @param nf número de filas del icono resultante
 * @param nc número de columnas del icono resultante
 * @pre fila (f) debe ser mayor de 0 y menor que el numero de filas de la imagen
 *      del fichero origen, y columna (c) debe ser mayor de 0 y menor del numero
 *      de columnas del fichero origen.
 */
void ObtenerIcono(const char * fich_orig, const char * fich_rdo, int nf, int nc);

/**
 * @brief Genera a partir de una imagen original otra imagen que sigue un criterio definido
 * @param fichE imagen que queremos umbralizar
 * @param fichS fichero de salida donde se guardara la imagen umbralizada
 * @param T1 valor del primer umbral
 * @param T2 valor del segundo umbral
 */

void umbralizar(const char* fichE, const char* fichS, byte T1, byte T2);

/**
 * @brief Transicion de una imagen a otra creando la ilusion de una transformacion
 * @param fich_orig nombre del fichero de la imagen inicial de la que partimos
 * @param fich_rdo nombre del fichero que contiene la imagen a la que pretendemos llegar
 * @param pasosInterm numero de pasos intermedios entre la imagen inicial y final
 * @pre pasosInterm > 0 
 * @pre ambas imagenes deben tener el mismo tamaño
 */

void morphing(const char* fich_orig, const char* fich_rdo, int pasosInterm);

/**
 * @brief Main en el que se aplican las funciones de @c usoimagen.cpp
 * @param argc numero de argumentos del main
 * @param argv argumentos pasados al main
 * @return 0
 */
int main(int argc, char* argv[]) {
    char *origen;
    char *destino;

    string tipoFuncion = argv[1];

    //Comprobamos la validez de la llamada
    if (argc != 4) {
        cerr << "\nError: Numero incorrecto de parametros." << endl;
        cerr << "Uso: umbralizar/icono/morphing <FicheroImagenOrigen> <FicheroImagenSalida>" << endl;
        exit(1);
    }

    origen = argv[2];
    destino = argv[3];

    //Vemos que funcion quiere utilizar el usuario
    
    if (tipoFuncion == "umbralizar") {
        
        cout << "\nAplicando funcion umbralizar. " << endl;
        umbralizar(origen, destino, 10, 210);
        
    } else if (tipoFuncion == "icono") {

        int nfilas = 0, ncolumnas = 0;
        cout << "\nIntroduzca el valor del icono a formar de la forma (filas, columnas): ";
        cin >> nfilas >> ncolumnas;
        ObtenerIcono(origen, destino, nfilas, ncolumnas);

    } else if (tipoFuncion == "morphing") {
        
        int intermedios = 0;
        cout << "\nIntroduzca el numero de pasos intermedios en el morphing: ";
        cin >> intermedios;
	cout << "\nAplicando morphing." << endl;
        morphing(origen, destino, intermedios);
        
    } else {
        cerr << "\nUtilice la palabra clave <umbralizar>, <icono> o <morphing>" << endl;
        exit(1);
    }

    return 0;
}

void umbralizar(const char* fichE, const char* fichS, byte T1, byte T2) {
    Imagen orig;
    if (orig.CargarImagen(fichE)) {
        Imagen nueva(orig);

        for (int i = 0; i < orig.numfilas(); i++) {
            for (int j = 0; j < orig.numcolumnas(); j++) {
                //Comprobamos que no se sale de los umbrales establecidos
                if (orig.get_pixel(i, j) <= T1 || orig.get_pixel(i, j) >= T2)
                    //Asignamos el valor correspondiente en dicha posicion
                    nueva.asigna_pixel(i, j, 255);
            }
        }

        nueva.SaveImagen(fichS);
    }

}

void ObtenerIcono(const char * fich_orig, const char * fich_rdo, int nf, int nc) {

    Imagen orig;
    Imagen rdo(nf, nc);

    if(orig.CargarImagen(fich_orig)){
        //Determinamos el tamaño de filas y columnas de la submatriz
        int tam_saltos_filas = (orig.numfilas() + nf - 1) / nf;
        int tam_saltos_cols = (orig.numcolumnas() + nc - 1) / nc;
        
        int inicio_filas = 0;
        int inicio_filas_sub = 0;
        int inicio_cols = 0;
        int inicio_cols_sub = 0;
        int tope_filas_sub=0;
        int tope_cols_sub=0;
        double suma = 0;
        int media;
        
        for (int i = 0; i < nf; i++) {
            inicio_filas_sub = i*tam_saltos_filas;
            for (int j = 0; j < nc; j++) {
                inicio_cols_sub = j*tam_saltos_cols;
                //El tope de filas y columnas controla los valores cuando estos 
                // no lleguen a completar una submatriz entera
                tope_filas_sub=inicio_filas_sub + tam_saltos_filas;
                if(tope_filas_sub > orig.numfilas())
                    tope_filas_sub=orig.numfilas();
                for (int k = inicio_filas_sub; k < tope_filas_sub; k++) {
                    tope_cols_sub=inicio_cols_sub + tam_saltos_cols;
                    if(tope_cols_sub > orig.numcolumnas())
                        tope_cols_sub=orig.numcolumnas();                    
                    for (int l = inicio_cols_sub; l < tope_cols_sub; l++) {                   
                            suma += orig(k, l);                            
                    }
                }
                media = round(suma / (tam_saltos_filas * tam_saltos_cols));
                rdo.asigna_pixel(i, j, media);
                suma = 0;
            }
        }
        rdo.SaveImagen(fich_rdo);    
    }
}

void morphing(const char* fich_orig, const char* fich_rdo, int pasosInterm) {

    Imagen orig, res;
    if (orig.CargarImagen(fich_orig) && res.CargarImagen(fich_rdo)) {
        //Compruebo que ambas imagenes son del mismo tamaño
        assert(orig.numcolumnas() == res.numcolumnas() && orig.numfilas() == res.numfilas());
        // Creamos una imagen auxiliar del mismo tamaño que ambas
        Imagen aux(orig.numcolumnas(), orig.numfilas());

        for (int i = 0; i < pasosInterm; i++) {
            //Parametro para los pasos intermedios
            double puntos_intermedios = 1 - (i * 1.0 / (pasosInterm - 1));
            for (int j = 0; j < orig.numfilas(); j++) {
                for (int k = 0; k < orig.numcolumnas(); k++)
                    //Asignamos valores a imagenes intermedias mediante media ponderada
                    aux.asigna_pixel(j, k, round(puntos_intermedios * orig.get_pixel(j, k) +
                        (1 - puntos_intermedios) * res.get_pixel(j, k)));
            }

            //Imprimimos las imagenes intermedias en la carpeta correspondiente
	    //OJO: "../imagenes/intermedio ... debe cambiarse si se almacena en otro directorio
            string fich_intermedio = "imagenes/intermedio" + to_string(i + 1) + ".pgm";
            aux.SaveImagen(fich_intermedio.c_str()); // pasamos el string a cString para evitar problemas con el compilador
        }

    }
}



