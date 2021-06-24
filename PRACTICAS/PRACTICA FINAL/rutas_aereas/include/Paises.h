/**
 * @file Paises.h
 * @brief Fichero cabecera del TDA Paises
 * @author Alberto Llamas, Elena Ortega
 *
 */
#ifndef __PAISES_H
#define __PAISES_h

#include "Pais.h"
#include <set>

using namespace std;

/**
 * @brief T.D.A. Paises
 * 
 * Una instancia @e c del TDA Pais @c Paises es un objeto que representa
 * un conjunto de paises donde cada elemento, corresponde
 * a un pais
 * 
 * 
 * datos[pais]
 * 
 * @see Punto
 * @see Pais
 * 
 * 
 * @author Elena y Alberto
 * @date Enero 2021
 * 
 */
class Paises{
private:
    /**
    * @page repPaises Rep del TDA Paises
    * 
    * @section invPaises Invariante de la representacion
    * El invariante es: 
    * - @c datos.size() > 0
    * 
    * @section faPaises Funcion de abstraccion
    * 
    * Un objeto valido @e ps del TDA Paises representa al conjunto de paises
    * @e p
    * 
    * (rep.datos)
    */
    set<Pais> datos;
    
public:
    // --------------- Constructores ---------------
    /**
	 * @brief Constructor por defecto. 
	 */
    Paises() {}

    // --------------- Otras funciones ---------------
    /**
     * @brief Inserta un nuevo pais
     * @param P pais a insertar
     */
    void Insertar(const Pais &P);

    /**
     * @brief Borra un pais
     * @param P pais a eliminar
     */
    void Borrar(const Pais &P);

    // --------------- Iteradores ---------------
    class const_iterator;
    /**
     * @brief Sobrecarga iterator para TDA Paises
     * */
    class iterator
    {
    private:
        set<Pais>::iterator p;

    public:
        /**
		 * @brief Constructor por defecto
		 * */
        iterator(){}
        /**
		 * @brief Sobrecarga del operador ++ para iterators
		 * @return Iterator incrementado en 1 (++it)
		 * */
        iterator & operator++()
        {
			++p;
			return *this;
			//this es un puntero a iterator
			//*this es un objeto de tipo iterator
			//this->it es un objeto de tipo set<Pais>::iterator
		}
        /**
		 * @brief Sobrecarga del operador -- para iterators
		 * @return Iterator decrementado en 1 (--it)
		 * */
        iterator & operator--()
        {
			--p;
			return *this;
		}
        /**
		 * @brief Sobrecarga del operador * para iterators
		 * @return Un pais al que apunta iterator
		 * */
        const Pais& operator*() const
        {
			return *p;  
		}
        /**
		 * @brief Comprueba si dos iterators son iguales
		 * @param i: Otro iterator de Paises
		 * @return True si apunta al mismo objeto, False en otro caso
		 * */
        bool operator==(const iterator & i)const
        {
			return p==i.p;
		}
        /**
		 * @brief Comprueba si dos iterators son diferentes
		 * @param i: Otro iterator de Paises
		 * @return True si apuntan a distintos objetos, False en otro caso
		 * */
        bool operator!=(const iterator & i)const
        {
			return p!=i.p;
		}
        /**
		 * @brief Sobrecarga del operador de asignacion para iterators
		 * @param i: iterator de Paises
		 * @return iterator que apunta a donde apunta i
		 * */
        iterator &operator=(const iterator &i)
        {
            p = i.p;
            return *this;
        }

        friend class Paises;
        friend class const_iterator;
    };
    /**
     * @brief Sobrecarga const_iterator para TDA Paises
     * */
    class const_iterator
    {
    private:
        set<Pais>::const_iterator p;

    public:
        /**
		 * @brief Constructor por defecto
		 * */
        const_iterator(){}
        /**
		 * @brief Sobrecarga del operador ++ para const_iterators
		 * @return const_iterator incrementado en 1 (++it)
		 * */
        const_iterator & operator++()
        {
			++p;
			return *this;
			//this es un puntero a iterator
			//*this es un objeto de tipo iterator
			//this->it es un objeto de tipo set<Pais>::iterator
		}
        /**
		 * @brief Sobrecarga del operador -- para const_iterators
		 * @return const_iterator decrementado en 1 (--it)
		 * */
        const_iterator & operator--()
        {
			--p;
			return *this;
		}
        /**
		 * @brief Sobrecarga del operador * para const_iterators
		 * @return Un Pais al que apunta const_iterator
		 * */
        const Pais& operator*() const
        {
			return *p;  
		}
        /**
		 * @brief Comprueba si dos const_iterators son iguales
		 * @param i: Otro const_iterator de Paises
		 * @return True si apunta al mismo objeto, False en otro caso
		 * */
        bool operator==(const const_iterator & i)const
        {
			return p==i.p;
		}
        /**
		 * @brief Comprueba si dos const_iterators son diferentes
		 * @param i: Otro const_iterator de Paises
		 * @return True si apuntan a distintos objetos, False en otro caso
		 * */
        bool operator!=(const const_iterator & i)const
        {
			return p!=i.p;
		}
        /**
		 * @brief Sobrecarga del operador de asignacion para const_iterators
		 * @param it: const_iterator de Paises
		 * @return const_iterator que apunta a donde apunta i
		 * */
        const_iterator& operator=(const const_iterator& it){
            p=it.p;
            return *this;
        }
        

        friend class Paises;
    };

    // --------------- Otras funciones ---------------
    /**
     * @brief inicializa un iterator al comienzo del set de Paises
     * @return iterator begin
     * */
    iterator begin()
    {
        iterator it;
        it.p = datos.begin();
        return it;
    }
    /**
     * @brief inicializa un const_iterator al comienzo del set de Paises
     * @return const_iterator begin
     * */
    const_iterator begin() const {
        const_iterator it;
        it.p = datos.begin();
        return it;
    }
    /**
     * @brief inicializa un iterator al final del set de Paises
     * @return iterator end
     * */
    iterator end()
    {
        iterator it;
        it.p = datos.end();
        return it;
    }
    /**
     * @brief inicializa un const_iterator al final del set de Paises
     * @return const_iterator end
     * */
    const_iterator end() const {
        const_iterator it;
        it.p = datos.end();
        return it;
    } 
    
    /**
     * @brief Obtiene el iterador que apunta al pais @e p
     * @param p pais cuyo iterador se ha de obtener
     */
    iterator find(const Pais &p)
    {
        iterator it;
        set<Pais>::iterator i;
        for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i);
        it.p = i;
        return it;
    }

    /**
     * @brief Obtiene el iterador que apunta al punto @e p asociado a un pais
     * @param p punto cuyo iterador se ha de obtener
     */
    iterator find(const Punto &p)
    {
        iterator it;
        set<Pais>::iterator i;
        for (i=datos.begin(); i != datos.end() && !((*i)== p);++i);
        it.p = i;
        return it;
    }

    /**
     * @brief Operador de entrada. Lectura de los paises
     * @param is stream desde el que se lee
     * @param R paises en los que leer
     * @return Devuelve una referencia al flujo de entrada is para permitir el 
     * encadenamiento del operador
     * @note Lee paises de is y lo almacena en R
     */
    friend istream &operator>>(istream &is, Paises &R)
    {
        Paises rlocal;
        //leemos el comentario
        if (is.peek() == '#')
        {
            string a;
            getline(is, a);
        }

        Pais P;
        while (is >> P)
        {
            rlocal.Insertar(P);
        }
        R = rlocal;
        return is;
    }

    /**
     * @brief Operador de salida. Escritura de los paises
     * @param os stream en el que se escribe
     * @param R paises que escribir
     * @return Devuelve una referencia al flujo de salida os para permitir el 
     * encadenamiento del operador
     * @note Escribe paises en os
     */
    friend ostream &operator<<(ostream &os, const Paises &R)
    {

        Paises::const_iterator it;
        for (it = R.begin(); it != R.end(); ++it)
        {
            os << *it << "\t";
        }
        return os;
    }
};

#endif
