/**
 * @file Almacen_Rutas.h
 * @brief Fichero cabecera del TDA Almacen_Rutas
 * @author Alberto Llamas, Elena Ortega
 *
 */
#ifndef __ALMACEN_RUTAS_H
#define __ALMACEN_RUTAS_H
#include <iostream>
#include <map>
#include <string>
#include "Ruta.h"

using namespace std;

/**
 * @brief T.D.A. Almacen_Rutas
 * 
 * Una instancia @e AR del TDA Almacen_Rutas @c Almacen_Rutas es un objeto que representa
 * un conjunto de rutas donde cada elemento corresponde
 * a una ruta formada por una clave y su ruta 
 * 
 * 
 * @see Punto
 * @see Ruta
 * 
 * @author Elena y Alberto
 * @date Enero 2021
 * 
 */
class Almacen_Rutas
{
private:
    /**
    * @page repAR Rep del TDA Almacen_Rutas
    * 
    * @section invAR Invariante de la representacion
    * El invariante es: 
    * @e rep.it->first > 0
    * 
    * @section faAR Funcion de abstraccion
    * 
    * Un objeto valido @e ar del TDA Almacen_Rutas representa al conjunto
    * de rutas:
    * @e AR
    * 
    * (rep.it->first, rep.it->second)
    */
    map<string, Ruta> rutas;
    map<Punto, string> interes;
    int numInteres;

public:
    // --------------- Constructores ---------------
    /**
	 * @brief Constructor por defecto
	 */
    Almacen_Rutas() {}

    // --------------- Otras funciones ---------------
    /**
     * @brief Inserta una nueva ruta al almacén
     * @param R ruta a insertar
     */
    void Insertar(const Ruta &R);

    /**
	 * @brief Borra una ruta del almacén
     * @param R ruta a eliminar
     */
    void Borrar(const Ruta &R);

    /**
    	 * @brief Consultor ruta
         * @param a codigo de la ruta
         * @return Devuelve la ruta asociada al codigo @e a
     	 * @note La ruta no se modifica
     	 */
    Ruta GetRuta(const string &a);

    // --------------- Iteradores ---------------
    /**
     * @brief Sobrecarga iterator para TDA Almacen Rutas
     * */
    class iterator
    {
    private:
        map<string, Ruta>::iterator p;

    public:
        /**
		 * @brief Constructor por defecto
		 * */
        iterator() {}
        /**
		 * @brief Sobrecarga del operador ++ para iterators
		 * @return Iterator incrementado en 1 (++it)
		 * */
        iterator &operator++()
        {
            ++p;
            return *this;
        }
        /**
		 * @brief Sobrecarga del operador -- para iterators
		 * @return Iterator decrementado en 1 (--it)
		 * */
        iterator &operator--()
        {
            --p;
            return *this;
        }
        /**
		 * @brief Sobrecarga del operador * para iterators
		 * @return Un pair<string,Ruta> al que apunta iterator
		 * */
        pair<const string, Ruta> &operator*()
        {
            return *p;
        }
        /**
		 * @brief Comprueba si dos iterators son iguales
		 * @param i: Otro iterator del Almacen de Rutas
		 * @return True si apunta al mismo objeto, False en otro caso
		 * */
        bool operator==(const iterator &i)
        {
            return i.p == p;
        }
        /**
		 * @brief Comprueba si dos iterators son diferentes
		 * @param i: Otro iterator del Almacen de Rutas
		 * @return True si apuntan a distintos objetos, False en otro caso
		 * */
        bool operator!=(const iterator &i)
        {
            return i.p != p;
        }
        /**
		 * @brief Sobrecarga del operador de asignacion para iterators
		 * @param i: iterator del Almacen de Rutas
		 * @return iterator que apunta a donde apunta i
		 * */
        iterator &operator=(const iterator &i)
        {
            p = i.p;
            return *this;
        }

        friend class Almacen_Rutas;
    };
    /**
     * @brief Sobrecarga const_iterator para TDA Almacen Rutas
     * */
    class const_iterator
    {
    private:
        map<string, Ruta>::const_iterator p;

    public:
        /**
		 * @brief Constructor por defecto
		 * */
        const_iterator() {}
        /**
		 * @brief Sobrecarga del operador ++ para const_iterators
		 * @return const_iterator incrementado en 1 (++it)
		 * */
        const_iterator &operator++()
        {
            ++p;
            return *this;
        }
        /**
		 * @brief Sobrecarga del operador -- para const_iterators
		 * @return const_iterator decrementado en 1 (--it)
		 * */
        const_iterator &operator--()
        {
            --p;
            return *this;
        }
        /**
		 * @brief Sobrecarga del operador * para const_iterators
		 * @return Un pair<string,Ruta> al que apunta const_iterator
		 * */
        const pair<const string, Ruta> &operator*()
        {
            return *p;
        }
        /**
		 * @brief Comprueba si dos const_iterators son iguales
		 * @param i: Otro const_iterator del Almacen de Rutas
		 * @return True si apunta al mismo objeto, False en otro caso
		 * */
        bool operator==(const const_iterator &i)
        {
            return i.p == p;
        }
        /**
		 * @brief Comprueba si dos const_iterators son diferentes
		 * @param i: Otro const_iterator del Almacen de Rutas
		 * @return True si apuntan a distintos objetos, False en otro caso
		 * */
        bool operator!=(const const_iterator &i)
        {
            return i.p != p;
        }
        /**
		 * @brief Sobrecarga del operador de asignacion para const_iterators
		 * @param i: const_iterator del Almacen de Rutas
		 * @return const_iterator que apunta a donde apunta i
		 * */
        const_iterator &operator=(const const_iterator &i)
        {
            p = i.p;
            return *this;
        }
        friend class Almacen_Rutas;
    };

    // --------------- Otras funciones ---------------
    /**
     * @brief Inicializa un iterator al comienzo del conjunto de rutas
     * @return Iterator que apunta al principio del conjunto
     * */
    iterator begin()
    {
        iterator i;
        i.p = rutas.begin();
        return i;
    }
    /**
     * @brief Inicializa un const_iterator al comienzo del conjunto de rutas
     * @return Const_iterator que apunta al principio del conjunto
     * */
    const_iterator begin() const
    {
        const_iterator i;
        i.p = rutas.cbegin();
        return i;
    }
    /**
     * @brief Inicializa un iterator al final del conjunto de rutas
     * @return iterator que apunta al final del conjunto
     * */
    iterator end()
    {
        iterator i;
        i.p = rutas.end();
        return i;
    }
    /**
     * @brief Inicializa un const_iterator al final del conjunto de rutas
     * @return Const_iterator que apunta al final del conjunto
     * */
    const_iterator end() const
    {
        const_iterator i;
        i.p = rutas.cend();
        return i;
    }

    /**
     	* @brief Operador de entrada. Lectura del almacen de rutas
    	* @param is stream desde el que se lee
     	* @param AR almacen de rutas en la que leer
     	* @return Devuelve una referencia al flujo de entrada is para permitir el 
     	* encadenamiento del operador
     	* @note Lee un conjunto de rutas de is y lo almacena en AR
     	*/
    friend istream &operator>>(istream &is, Almacen_Rutas &AR)
    {
        string palabra_magica;
        is >> palabra_magica;

        if (palabra_magica != "#Rutas")
        {
            cerr << "\nError leyendo fichero Rutas";
            exit(-1);
        }

        while (!is.eof() && is.peek() != '#')
        {
            Ruta miruta;
            is >> miruta;
            AR.Insertar(miruta);
            is.ignore(1000, '\n');
        }

        if (is.peek() == '#')
        {
            string a;
            getline(is, a);
            while (!is.eof())
            {
                AR.numInteres++;
                pair<Punto, string> p;
                is >> p.first;
                getline(is, p.second);
                AR.interes.insert(p);
            }
        }

        return is;
    }
    /**
    * @brief Operador de salida. Escritura del almacen de rutas
    * @param os stream en el que se escribe
    * @param AR almacen que escribir
    * @return Devuelve una referencia al flujo de salida os para permitir el 
    * encadenamiento del operador
    * @note Escribe un almacen de rutas en os
    * */

    friend ostream &operator<<(ostream &os, const Almacen_Rutas &AR)
    {
        os << "#Rutas" << endl;

        map<string, Ruta>::const_iterator it = AR.rutas.begin();

        for (; it != AR.rutas.end(); ++it)
        {
            os << (*it).second << endl;
        }
        if (AR.numInteres > 0)
        {
            os << "#Puntos de interes" << endl;

            map<Punto, string>::const_iterator i = AR.interes.begin();
            for (; i != AR.interes.end(); ++i)
            {
                os << (*i).first << " " << (*i).second << endl;
            }
        }
        return os;
    }
};
#endif