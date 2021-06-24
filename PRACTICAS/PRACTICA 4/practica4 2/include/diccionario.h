/**
 * @file : diccionario.h
 * @brief: TDA diccionario
 * */

#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

/**
 * @brief Tipo data que define el diccionario.
 * Tipo elemento que define el diccionario. @a T es el tipo de dato asociado a una clave que
 * no se repite (DNI p.ej.) y @a list<U> es una lista de datos (string p.ej) asociados a la clave
 * de tipo @a T. El diccionario está ordenado de menor a mayor clave.
 *
 * @author Alberto Llamas Gonzalez
 * @date diciembre 2020
*/
template <class T, class U>
struct data
{
	T clave;
	list<U> info_asoci;
};

/**
 * @brief Sobrecarga del operador de comparacion
 *  Ordena 2 registros de acuerdo a la clave de tipo T. Puede usarse como un funtor.
 * @return La relacion de orden
 */
template <class T, class U>
bool operator<(const data<T, U> &d1, const data<T, U> &d2)
{
	if (d1.clave < d2.clave)
		return true;
	return false;
}

/*Un diccionario es una lista de datos de los definidos anteriormente. Cuidado porque se
manejan listas de listas. Se añaden 2 funciones privadas que hacen más facil la implementación
de algunos operadores o funciones de la parte pública. Copiar copia un diccioario en
otro y borrar elimina todos los elementos de un diccionario. La implementación de copiar
puede hacerse usando iteradores o directamente usando la función assign.
*/
/**
 * @brief T.D.A Diccionario
 *
 * Un diccionario es una lista de datos de los definidos anteriormente. Cuidado porque semanejan listas de listas.
 * Se añaden 2 funciones privadas que hacen más facil la implementación
 * de algunos operadores o funciones de la parte pública. Copiar copia un diccioario en
 * otro y borrar elimina todos los elementos de un diccionario. La implementación de copia
 * puede hacerse usando iteradores o directamente usando la función assign.
 *
 * Una instancia @e c del tipo de datos abstracto @c Diccionario es un objeto formado por una lista
 * del struct @c data {(e1,e2, ..., en)} ordenados.
 *
 * Un ejemplo de su uso:
 * usodiccionario.cpp
 *
 * @author Rosa Rodríguez (Métodos adicionales anadidos por Alberto Llamas)
 * @date Diciembre 2020
 * */
template <class T, class U>
class Diccionario
{
	/**
	 * @page repDiccionario Rep del TDA Diccionario
	 *
	 * @section invDiccionario Invariante de la representación
	 *
	 * El invariante es
	 *
	 * @section faDiccionario Función de abstraccion
	 *
	 * Un objeto válido @e rep del TDA Diccionario representa al valor
	 *
	 * {(rep.begin(), rep.begin()+1, ..., rep.begin()+n-1)}
	 *
	 * */
private:
	list<data<T, U>> datos;

	/**
	 * @brief Funcion auxiliar que copia un diccionario
	 * @param D: diccionario a copiar
	 * */
	void Copiar(const Diccionario<T, U> &D)
	{
		datos.assign(D.datos.begin(), D.datos.end());
	}

	/**
	 * @brief Funcion auxiliar que borra todos los elementos de un diccionario
	 * */
	void Borrar()
	{

		this->datos.erase(datos.begin(), datos.end());
	}

public:

	// --------- Constructores ---------
	/**
	 * @brief Constructor por defecto
	 * */
	Diccionario() : datos(list<data<T, U>>()) {}

	/**
	 * @brief Constructor de copias
	 * @param D: otro diccionario
	 * */
	Diccionario(const Diccionario &D)
	{
		Copiar(D);
	}

	// --------- Destructor ---------

	/**
	 * @brief Destructor de la clase
	 * */
	~Diccionario() {}


	// --------- Sobrecargas ---------
	/**
	 * @brief Sobrecarga del operador de asignación
	 * @param D: otro diccionario
	 * @return diccionario
	 * */
	Diccionario<T, U> &operator=(const Diccionario<T, U> &D)
	{
		if (this != &D)
		{
			Borrar();
			Copiar(D);
		}
		return *this;
	}
	/**
	 * @brief Sobrecarga del operador resta: diferencia de diccionarios
	 * @param d: diccionario a restar
	 * @return diccionario resultante de restar d con el propio diccionario
	 * */
	Diccionario operator-(const Diccionario &d)
	{
		Diccionario aux(*this);
		typename list<data<T,U>>::const_iterator it;
		for (it = d.datos.begin(); it != d.datos.end(); ++it)
		{
			aux.BorrarElemento(it->clave);
		}
		return aux;
	}

	/**
	 * @brief Sobrecarga del operador suma: union de diccionarios
	 * @param d: diccionario a unir
	 * @return diccionario resultante de unir d con el propio diccionario
	 * */
	Diccionario operator+(const Diccionario &d)
	{
		Diccionario aux(*this);
		typename list<data<T,U>>::const_iterator it;
		for (it = d.datos.begin(); it != d.datos.end(); ++it)
		{
			aux.Insertar((*it).clave, (*it).info_asoci);
		}
		return aux;
	}

	/**
	 * @brief Comprueba que la clave este en el diccionario
	 * @note Si esta, devuelve un iterador apuntando a donde está la clave. Si no está, devuelve
	 * @a end() y deja el iterador de salida apuntando al sitio donde debería estar la clave
	 * @param p: clave del diccionario
	 * @param it_out: iterador con la posicion de la clave en el diccionario
	 * @return True o False dependiendo si se ha encontrado o no la clave
	 * */
	bool Esta_Clave(const T &p, typename list<data<T, U>>::iterator &it_out)
	{

		if (datos.size() > 0)
		{

			typename list<data<T, U>>::iterator it;

			for (it = datos.begin(); it != datos.end(); ++it)
			{
				if ((*it).clave == p)
				{
					it_out = it;
					return true;
				}
				else if ((*it).clave > p)
				{
					it_out = it;
					return false;
				}
			}

			it_out = it;
			return false;
		}
		else
		{
			it_out = datos.end();
			return false;
		}
	}
	// --------- Modificadores ---------
	/**
	 * @brief Inserta un nuevo registro en el diccionario
	 * @note Lo hace a través de la clave @a clave e inserta la lista con toda la información asociada a esa clave. Si el
	 * diccionario no estuviera ordenado habría que usar la función sort()
	 * @param clave: clave a insertar
	 * @param info: lista con toda la informacion asociada a esa clave
	 * */
	void Insertar(const T &clave, const list<U> &info)
	{

		typename list<data<T, U>>::iterator it;

		if (!Esta_Clave(clave, it))
		{
			data<T, U> p;
			p.clave = clave;
			p.info_asoci = info;

			datos.insert(it, p);
		}
	}

	/**
	 * @brief Añade nueva informacion asociada a una clave del diccionario
	 * @param s: palabra a la que se le va a añadir el significado
	 * @param p: informacion asociada
	 * */
	void AddSignificado_Palabra(const U &s, const T &p)
	{
		typename list<data<T, U>>::iterator it;

		if (!Esta_Clave(p, it))
		{
			datos.insert(it, p);
		}

		//Insertamos el siginificado al final
		(*it).info_asoci.insert((*it).info_asoci.end(), s);
	}

	/**
	 * @brief Informacion asociada a una clave
	 * @param p: clave de tipo T
	 * @return Devuelve una lista de <U> con la informacion de la clave
	 * */
	list<U> getInfo_Asoc(const T &p)
	{
		typename list<data<T, U>>::iterator it;

		if (!Esta_Clave(p, it))
		{
			return list<U>();
		}
		else
		{
			return (*it).info_asoci;
		}
	}

	/**
	 * @brief Devuelve el tamaño del diccionario
	 * @return Tamaño del diccionario
	 * */
	int size() const
	{
		return datos.size();
	}

	// --------- Clases Iterator ---------

	/**
	 * @brief Sobrecarga iterator para TDA Diccionario
	 * */
	class iterator
	{
	private:
		typename list<data<T, U>>::iterator it;

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
			++it;
			return *this; //this es un puntero a iterator, *this es un puntero de tipo iterator, this->it es un objeto de tipo list<data<T,U>> :: iterator
		}
		/**
		 * @brief Sobrecarga del operador -- para iterators
		 * @return Iterator decrementado en 1 (--it)
		 * */
		iterator &operator--()
		{
			--it;
			return *this; //this es un puntero a iterator, *this es un puntero de tipo iterator, this->it es un objeto de tipo list<data<T,U>> :: iterator
		}
		/**
		 * @brief Sobrecarga del operador * para iterators
		 * @return Un data<T,U> al que apunta iterator
		 * */
		data<const T, U> &operator*()
		{ //Nos interesa que no modifique la clave por lo que ponemos const en T
			return *it;
		}
		/**
		 * @brief Comprueba si dos iterators son iguales
		 * @param i: Otro iterator de diccionario
		 * @return True si apunta al mismo objeto, False en otro caso
		 * */
		bool operator==(const iterator &i) const
		{
			return it == i.it;
		}
		/**
		 * @brief Comprueba si dos iterators son diferentes
		 * @param i: Otro iterator de diccionario
		 * @return True si apuntan a distintos objetos, False en otro caso
		 * */
		bool operator!=(const iterator &i) const
		{
			return it != i.it;
		}

		friend class Diccionario;
	};
	/**
	 * @brief Sobrecarga const_iterator para TDA Diccionario
	 * */
	class const_iterator
	{
	private:
		typename list<data<T, U>>::const_iterator it;

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
			++it;
			return *this; //this es un puntero a iterator, *this es un puntero de tipo iterator, this->it es un objeto de tipo list<data<T,U>> :: iterator
		}
		/**
		 * @brief Sobrecarga del operador -- para const_iterators
		 * @return const_iterator decrementado en 1 (--it)
		 * */
		const_iterator &operator--()
		{
			--it;
			return *this; //this es un puntero a iterator, *this es un puntero de tipo iterator, this->it es un objeto de tipo list<data<T,U>> :: iterator
		}
		/**
		 * @brief Sobrecarga del operador * para const_iterators
		 * @return Un data<T,U> al que apunta const_iterator
		 * */
		const data<T, U> &operator*()
		{ //Ahora no se modifica nada
			return *it;
		}
		/**
		 * @brief Comprueba si dos const_iterators son iguales
		 * @param i: Otro const_iterator de diccionario
		 * @return True si apunta al mismo objeto, False en otro caso
		 * */
		bool operator==(const const_iterator &i) const
		{
			return it == i.it;
		}
		/**
		 * @brief Comprueba si dos const_iterators son diferentes
		 * @param i: Otro const_iterator de diccionario
		 * @return True si apuntan a distintos objetos, False en otro caso
		 * */
		bool operator!=(const const_iterator &i) const
		{
			return it != i.it;
		}

		friend class Diccionario;
	};

	// --------- Iteradores ---------
	/**
	 * @brief Iterador begin
	 * @return Iterador begin
	 * */
	iterator begin()
	{
		iterator i;
		i.it = datos.begin();
		return i;
	}

	/**
	 * @brief Iterador end
	 * @return Iterador end
	 * */
	iterator end()
	{
		iterator i;
		i.it = datos.end();
		return i;
	}

	/**
	 * @brief Iterador begin constante
	 * @return Iterador begin constante
	 * */
	const_iterator begin() const
	{
		const_iterator i;
		i.it = datos.cbegin();
		return i;
	}

	/**
	 * @brief Iterador end constante
	 * @return Iterador end constante
	 * */
	const_iterator end() const
	{
		const_iterator i;
		i.it = datos.cend();
		return i;
	}

	/**
	 * @brief Borra un elemento por su clave
	 * @param clave a borrar
	 * */
	void BorrarElemento(const T& clave)
	{
		typename list<data<T,U>>::iterator it;

		if (Esta_Clave(clave, it))
			datos.erase(it);
	}
	/**
	 * @brief Invierte los elementos de un diccionario
	 * */
	void invierte_Diccionario() {
		datos.reverse();
	}
	/**
	 * @brief Recorre la lista de información asociada a una clave y la imprime
	 * @param l informacion asociada a una clave
	 * */
	void EscribeSignificado(const list<U> &l)
	{
		typename list<U>::const_iterator it_s;

		for (it_s = l.begin(); it_s != l.end(); ++it_s)
		{
			cout << *it_s << endl;
		}
	}
	/**
	 * @brief Devuelve los elementos dentro de un rango de claves
	 * @param clave1: clave en la que empieza el intervalo
	 * @param clave2: clave en la que termina el intervalo
	 * */
	void IntervaloPalabras(const T& clave1, const T& clave2){
		typename list<data<T,U>>::const_iterator it, itMin, itMax;

		for (it=datos.begin(); it != datos.end(); ++it){
			if (clave1 == (*it).clave)
				itMin=it;
			if (clave2 == (*it).clave)
				itMax=it;
		}

		do{
			cout << "\n" << (*itMin).clave << endl;
			list<U>aux;
			aux=getInfo_Asoc((*itMin).clave);
			if (aux.size() > 0) {
				cout << "Informacion asociada: " << endl;
				EscribeSignificado(aux);
			}
			cout << "**************************************" << endl;

			++itMin;
		}while(itMin != itMax);

		//Tenemos que mostrar tambien el ultimo elemento
		cout << "\n" << (*itMin).clave << endl;
		list<U>aux;
		aux=getInfo_Asoc((*itMin).clave);
		if (aux.size() > 0) {
			cout << "Informacion asociada: " << endl;
			EscribeSignificado(aux);
		}
		cout << "**************************************" << endl;
	}

};

#endif
