/**
 * @file Ruta.h
 * @brief Fichero cabecera del TDA Ruta
 * @author Alberto Llamas, Elena Ortega
 *
 */
#ifndef __RUTA_H
#define __RUTA_H

#include <string>
#include "Punto.h"
#include <list>
#include <iostream>

using namespace std;
/**
 * @brief T.D.A. Ruta
 * 
 * Una instancia @e r del TDA ruta @c Ruta es un objeto que representa
 * una ruta donde cada elemento corresponde
 * a una ruta formada por una lista de puntos, su codigo, 
 * y un numero de puntos
 * 
 * 
 * @see Punto
 * 
 * @author Elena y Alberto
 * @date Enero 2021
 * 
 */
class Ruta
{

private:
	/**
    * @page repRuta Rep del TDA Ruta
    * 
    * @section invRuta Invariante de la representacion
    * El invariante es: 
    * @e rep.num_Puntos > 0
    * @e rep.code != ""
	* 
    * @section faRuta Funcion de abstraccion
    * 
    * Un objeto valido @e r del TDA Ruta representa a la ruta
    * @e r
    * 
    * (rep.puntos, rep.code, rep.num_Puntos)
    */
	list<Punto> puntos;
	string code;
	int num_Puntos;

public:
	// --------------- Constructores ---------------
	/**
	 	 * @brief Constructor por defecto. 
	 	 */
	Ruta() {}

	// --------------- Otras funciones ---------------
	/**
    	 * @brief Inserta un nuevo punto a la ruta
     	 * @param n punto a insertar
     	 */
	void Insertar(const Punto &n);

	/**
	     * @brief Borra un punto de la lista
     	 * @param n punto a eliminar
     	 */
	void Borrar(const Punto &n);

	/**
    	 * @brief Consultor code
     	 * @return Devuelve el codigo de ruta
     	 * @note La ruta no se modifica
     	 */
	string getCode() const { return code; }
	/**
    	 * @brief Consultor num_Puntos
     	 * @return Devuelve el numero de puntos de ruta
     	 * @note La ruta no se modifica
     	 */
	int getNumPuntos() const { return num_Puntos; }
	/**
     	 * @brief Modificador num_Puntos
     	 * @param numero numero de puntos de ruta a modificar
      	 * @note La ruta se modifica
     	 */
	void setNumPuntos(int numero) { num_Puntos = numero; }
	/**
     	 * @brief Modificador code
     	 * @param code codigo de ruta a modificar
      	 * @note La ruta se modifica
     	 */
	void setCode(const string &code) { this->code = code; }

	/**
     	 * @brief Operador de comparación de igualdad
     	 * @param R ruta con la que se compara
     	 * @return Devuelve true si las dos rutas son iguales
     	 */
	bool operator==(const Ruta &R) const;

	/**
     	 * @brief Compara si una ruta es menor que otra en base a su codigo
     	 * @param R ruta con la que se compara
     	 * @return Devuelve true si la ruta implícita es menor a @e R
     	 */
	bool operator<(const Ruta &R) const;

	// --------------- Iteradores ---------------
	/**
   		* @brief Sobrecarga iterator para TDA Ruta
     	* */
	class iterator
	{
	private:
		list<Punto>::iterator p;

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
		Punto &operator*()
		{
			return *p;
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
		/**
		 * @brief Comprueba si dos iterators son iguales
		 * @param i: Otro iterator del Almacen de Rutas
		 * @return True si apunta al mismo objeto, False en otro caso
		 * */
		bool operator==(const iterator &i) const
		{
			return p == i.p;
		}
		/**
		 * @brief Comprueba si dos iterators son diferentes
		 * @param i: Otro iterator del Almacen de Rutas
		 * @return True si apuntan a distintos objetos, False en otro caso
		 * */
		bool operator!=(const iterator &i) const
		{
			return p != i.p;
		}
		friend class Ruta;
	};
	/**
     * @brief Sobrecarga const_iterator para TDA Almacen Rutas
     * */
	class const_iterator
	{
	private:
		list<Punto>::const_iterator p;

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
		const Punto &operator*()
		{
			return *p;
		}
		/**
		 * @brief Comprueba si dos const_iterators son iguales
		 * @param i: Otro const_iterator del Almacen de Rutas
		 * @return True si apunta al mismo objeto, False en otro caso
		 * */
		bool operator==(const const_iterator &i) const
		{
			return p == i.p;
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
		/**
		 * @brief Comprueba si dos const_iterators son diferentes
		 * @param i: Otro const_iterator del Almacen de Rutas
		 * @return True si apuntan a distintos objetos, False en otro caso
		 * */
		bool operator!=(const const_iterator &i) const
		{
			return p != i.p;
		}
		friend class Ruta;
	};

	// --------------- Otras funciones ---------------
	/**
     * @brief Inicializa un iterator al comienzo del conjunto de rutas
     * @return Iterator que apunta al principio del conjunto
     * */
	iterator begin()
	{
		iterator i;
		i.p = puntos.begin();
		return i;
	}
	/**
     * @brief Inicializa un const_iterator al comienzo del conjunto de rutas
     * @return Const_iterator que apunta al principio del conjunto
     * */
	const_iterator begin() const
	{
		const_iterator i;
		i.p = puntos.begin();
		return i;
	}
	/**
     * @brief Inicializa un iterator al final del conjunto de rutas
     * @return iterator que apunta al final del conjunto
     * */
	iterator end()
	{
		iterator i;
		i.p = puntos.end();
		return i;
	}
	/**
     * @brief Inicializa un const_iterator al final del conjunto de rutas
     * @return Const_iterator que apunta al final del conjunto
     * */
	const_iterator end() const
	{
		const_iterator i;
		i.p = puntos.end();
		return i;
	}
	/**
     * @brief Obtiene el iterador que apunta al punto @e p asociado a un pais
     * @param p punto cuyo iterador se ha de obtener
	 * @return iterador que apunta al punto
     */
	iterator find(const Punto &p)
	{
		iterator it;
		list<Punto>::iterator i;
		for (i = puntos.begin(); i != puntos.end() && !((*i) == p); ++i);
		it.p = i;
		return it;
	}
	/**
     * @brief Obtiene el const_iterador que apunta al punto @e p asociado a un pais
     * @param p punto cuyo iterador se ha de obtener
	 * @return iterador que apunta al punto
     */
	const_iterator find(const Punto &p) const
	{
		const_iterator it;
		list<Punto>::const_iterator i;
		for (i = puntos.begin(); i != puntos.end() && !((*i) == p); ++i);
		it.p = i;
		return it;
	}

	/**
     	* @brief Operador de entrada. Lectura de la ruta
    	* @param is stream desde el que se lee
     	* @param R ruta en la que leer
     	* @return Devuelve una referencia al flujo de entrada is para permitir el 
     	* encadenamiento del operador
     	* @note Lee una ruta de is y lo almacena en R
     	*/
	friend istream &operator>>(istream &is, Ruta &R)
	{
		int num_puntos = 0;
		string codigo;
		Punto punto;

		is >> codigo;
		R.setCode(codigo);

		is >> num_puntos;
		R.setNumPuntos(num_puntos);
		if (num_puntos > 0)
		{
			for (int i = 0; i < R.getNumPuntos(); i++)
			{
				is >> punto;
				R.Insertar(punto);
			}
		}

		return is;
	}

	/**
     	* @brief Operador de salida. Escritura de la ruta
     	* @param os stream en el que se escribe
     	* @param R ruta que escribir
     	* @return Devuelve una referencia al flujo de salida os para permitir el 
     	* encadenamiento del operador
     	* @note Escribe una ruta en os
     	*/
	friend ostream &operator<<(ostream &os, const Ruta &R)
	{
		os << R.getCode() << " ";
		os << R.getNumPuntos() << " ";

		list<Punto>::const_iterator it = R.puntos.begin();
		for (; it != R.puntos.end(); ++it)
		{
			os << (*it) << " ";
		}

		return os;
	}
};
#endif