/**
 * @file : guiatlf.h
 * @brief: TDA guia de telefonos
 * */

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * @brief Sobrecarga del operador >>
 * @param is Flujo de entrada
 * @param d @e pair<string,string> a escribir
 * @post Se obtiene en \a is
 * */
istream &operator>>(istream &is, pair<string, string> &d)
{

	getline(is, d.first, '\t');
	getline(is, d.second);
	return is;
}


/**
 * @brief Sobrecarga del operador <<
 * @param os Flujo de salida
 * @param e @c Elemento a escribir
 * @post Se obtiene en \a os la cadena "( ele | maximo )" con \e ele,maximo los valores
 *   del elemento a almacenar y el máximo hasta el momento de \a e
 * */
ostream &operator<<(ostream &os, const pair<const string, string> &d)
{

	os << d.first << '\t' << d.second << endl;
	return os;
}

/**
  *  @brief T.D.A. Guia_Tlf
  *
  * Una instancia @e c del tipo de datos abstracto @c Guia_Tlf es un objeto
  * formado por una colección de pares {(e11,e21),(e12,e22),(e13,e23),...,(e1n-1,e2n-1)}
  * ordenados por la el primer elemento del par denominado clave o key. No existen
  * elementos repetidos.
  *
  *
  * Un ejemplo de su uso:
  *
  *
  * @author Rosa Rodríguez
  * @date Marzo 2012
  */

class Guia_Tlf
{
	/**
  * @page repGuia_Tlf Rep del TDA Guia_Tlf
  *
  * @section invGuia_Tlf Invariante de la representación
  *
  * El invariante es \e para todo \e i y \e j tal que i<j entonces \e e1i y e1j son distintos
  *
  * @section faGuia_Tlf Función de abstracción
  *
  * Un objeto válido @e rep del TDA Guia_Tlf representa al valor
  *
  * {(rep.begin().first,rep.begin().second),(rep.begin()+1.first,rep.begin()+1.second),....,(rep.begin()+n-1.first,rep.begin()+n-1.second)}
  *
  */
private:
	map<string, string> datos; //si admites que haya nombres repetidos tendrías que usar un
							   //multimap
							   //map<string, list<string>> datos;

public:
	/**
	* @brief Acceso a un elemento
	* @param nombre: nombre del elemento  elemento acceder
	* @return devuelve el valor asociado a un nombre, es decir el teléfono
	* */
	//si fuese un multimap no podriamos usar []. Ademas que deberiamos devolver p.e un vector con todos
	// los telefonos asociados a dicho nombre
	string &operator[](const string &nombre)
	{
		return datos[nombre];
	}

	string gettelefono(const string &nombre)
	{
		map<string, string>::iterator it = datos.find(nombre);
		if (it == datos.end())
			return string("");
		else
			return it->second; // it -> first es el nombre, it -> second es el tlf, (*it).first es el nombre. (*it).second es el tlf
	}

	/**
	 * @brief Insert un nuevo telefono
	 * @param nombre: nombre clave del nuevo telefono
	 * @param tlf: numero de telefono
	 * @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf
	 * o false en caso contrario
	 * */
	pair<map<string, string>::iterator, bool> insert(string nombre, string tlf)
	{
		pair<string, string> p(nombre, tlf);
		pair<map<string, string>::iterator, bool> ret;

		ret = datos.insert(p); //datos.insert(datos.begin(),p); tambien funcionaría
		return ret;
	}

	/**
	* @brief Insert un nuevo telefono
	* @param p: pair con el nombre y el telefono asociado
	* @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o
	* o false en caso contrario
	* */
	pair<map<string, string>::iterator, bool> insert(pair<string, string> p)
	{

		pair<map<string, string>::iterator, bool> ret;

		ret = datos.insert(p); //datos.insert(datos.begin(),p); tambien funcionaría
		return ret;
	}

	/**
	 * @brief Borrar un telefono
	 * @param nombre: nombre que se quiere borrar
	 * @note: en caso de que fuese un multimap borraria todos con ese nombre
	 * */
	void borrar(const string &nombre)
	{
		// map<string, string>::iterator itlow = datos.lower_bound(nombre);   //el primero que tiene dicho nombre
		// map<string, string>::iterator itupper = datos.upper_bound(nombre); //el primero que ya no tiene dicho nombre
		// if (itlow->first == nombre)
		// 	return;
		// datos.erase(itlow, itupper); //borramos todos aquellos que tiene dicho nombre
		// 							 //OTRA ALTERNATIVA
		pair<map<string, string>::iterator, map<string, string>::iterator> ret;
		ret = datos.equal_range(nombre);
		datos.erase(ret.first,ret.second);
	}

	/**
	 * @brief Borrar un telefono
	 * @param nombre: nombre que se quiere borrar y telefono asociado
	 * @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
	 * */
	//con map siempre hay uno con multimap puede existir mas de uno
	void borrar(const string &nombre, const string &tlf)
	{
		map<string, string>::iterator itlow = datos.lower_bound(nombre);   //el primero que tiene dicho nombre
		map<string, string>::iterator itupper = datos.upper_bound(nombre); //el primero que ya no tiene dicho nombre
		map<string, string>::iterator it;
		// if (itlow->first == nombre)
		// 	return;
		bool salir = false;
		for (it = itlow; it != itupper && !salir; ++it)
		{
			if (it->second == tlf)
			{
				datos.erase(it);
				salir = true;
			}
		}
	}
	/**
	* @brief  Numero de telefonos
	* @return el numero de telefonos asociados
	* */
	int size() const
	{
		return datos.size();
	}
	/**
	* @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
	* @param nombre: nombre sobre el que queremos consultar
	* @return numero de telefonos asociados a un nombre
	* */
	//al ser un map debe de ser 0 o 1. Si fuese un multimap podríamos tener mas de uno
	unsigned int contabiliza(const string &nombre)
	{
		return datos.count(nombre);
	}

	/**
	* @brief Limpia la guia
	* */
	void clear()
	{
		datos.clear();
	}
	/**
	* @brief Union de guias de telefonos
	* @param g: guia que se une
	* @return: una nueva guia resultado de unir el objeto al que apunta this y g
	* */
	Guia_Tlf operator+(const Guia_Tlf &g)
	{
		Guia_Tlf aux(*this);
		map<string, string>::const_iterator it;
		for (it = g.datos.begin(); it != g.datos.end(); ++it)
		{
			aux.insert(it->first, it->second);
		}
		return aux;
	}

	/**
	* @brief Diferencia de guias de telefonos
	* @param g: guia a restar
	* @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
	* */
	Guia_Tlf operator-(const Guia_Tlf &g)
	{
		Guia_Tlf aux(*this);
		map<string, string>::const_iterator it;
		for (it = g.datos.begin(); it != g.datos.end(); ++it)
		{
			aux.borrar(it->first, it->second);
		}
		return aux;
	}


	/**
	*  @brief  Obtiene una guia con los nombre previos a uno dado
	*  @param nombre: nombre delimitador
	*  @param tlf: telefono asociado a nombre
	* @return nueva guia sin nombres mayores que \a  nombre
	* */
	Guia_Tlf previos(const string &nombre, const string &tlf)
	{
		map<string, string>::value_compare vc = datos.value_comp(); //map<string,string>::key_compare vc=datos.key_comp()
		Guia_Tlf aux;
		pair<string, string> p(nombre, tlf);
		map<string, string>::iterator it = datos.begin();
		while (vc(*it, p))
		{
			aux.insert(*it++);
		}
		return aux;
	}

	/**
	* @brief Escritura de la guia de telefonos
	* @param os: flujo de salida. Es MODIFICADO
	* @param g: guia de telefonos que se escribe
	* @return el flujo de salida
	*/

	friend ostream &operator<<(ostream &os, Guia_Tlf &g)
	{
		map<string, string>::iterator it;
		for (it = g.datos.begin(); it != g.datos.end(); ++it)
		{
			os << it->first << "\t" << it->second << endl;
		}
		return os;
	}

	/**
	*	@brief Lectura de  la guia de telefonos
	*	@param is: flujo de entrada. ES MODIFICADO
	*	@param g: guia de telefonos. ES MODIFICADO
	*	@return el flujo de entrada
	*/
	friend istream &operator>>(istream &is, Guia_Tlf &g)
	{
		pair<string, string> p;
		Guia_Tlf aux;

		while (is >> p)
		{
			aux.insert(p);
		}
		g = aux;
		return is;
	}
	// --------- Clases Iterator ---------
	/**
	 * @brief Sobrecarga iterator para TDA Guia_Tlf
	 * */
	class iterator
	{
	private:
		map<string, string>::iterator it, final, inicio;

	public:
		/**
		 * @brief Constructor por defecto
		 * */
		iterator(){}
		/**
		 * @brief Sobrecarga del operador ++ para iterators
		 * @return Iterator incrementado en 1 (++it)
		 * */
		iterator &operator++()
		{
			++it;
			return *this;
		}
		/**
		 * @brief Sobrecarga del operador -- para iterators
		 * @return Iterator decrementado en 1 (--it)
		 * */
		iterator &operator--()
		{
			--it;
			return *this;
		}
		/**
		 * @brief Sobrecarga del operador * para iterators
		 * @return Un pair<string,string> al que apunta iterator
		 * */
		pair<const string, string> &operator*()
		{
			return *it;
		}
		/**
		 * @brief Comprueba si dos iterators son iguales
		 * @param i: Otro iterator de la guia
		 * @return True si apunta al mismo objeto, False en otro caso
		 * */
		bool operator==(const iterator &i)
		{
			return i.it == it;
		}
		/**
		 * @brief Comprueba si dos iterators son diferentes
		 * @param i: Otro iterator de la guia
		 * @return True si apuntan a distintos objetos, False en otro caso
		 * */
		bool operator!=(const iterator &i)
		{
			return i.it != it;
		}
		/**
		 * @brief Sobrecarga del operador de asignacion para iterators
		 * @param i: iterator de la guia
		 * @return iterator que apunta a donde apunta i
		 * */
		iterator& operator=(const iterator &i){
			it=i.it;
			return *this;
		}
		/**
		 * @brief Sobrecarga del operador + para iterators
		 * @param numero numero de posiciones que queremos avanzar
		 * @return iterador que apunta a posiciones mas adelante
		 * */
		iterator &operator+(int a)
		{
			for (int k = 0; k < a && it != final; k++)
				++it;
			return *this; //it+5
		}

		/**
		 * @brief Sobrecarga del operador - para iterators
		 * @param numero numero de posiciones que queremos retroceder
		 * @return iterador que apunta a posiciones detras
		 * */
		iterator &operator-(int a)
		{
			for (int k = a; k > 0 && it != inicio; k--)
				--it;
			return *this; //it+5
		}
		friend class Guia_Tlf;
	};
	/**
	 * @brief Sobrecarga const_iterator para TDA Guia_Tlf
	 * */
	class const_iterator
	{
	private:
		map<string, string>::const_iterator it, final, inicio;

	public:
		/**
		 * @brief Constructor por defecto
		 * */
		const_iterator(){}
		/**
		 * @brief Sobrecarga del operador ++ para const_iterators
		 * @return const_iterator incrementado en 1 (++it)
		 * */
		const_iterator &operator++()
		{
			++it;
			return *this;
		}
		/**
		 * @brief Sobrecarga del operador -- para const_iterators
		 * @return const_iterator decrementado en 1 (--it)
		 * */
		const_iterator &operator--()
		{
			--it;
			return *this;
		}
		/**
		 * @brief Sobrecarga del operador * para const_iterators
		 * @return Un pair<string,string> al que apunta const_iterator
		 * */
		const pair<const string, string> &operator*()
		{
			return *it;
		}
		/**
		 * @brief Comprueba si dos const_iterators son iguales
		 * @param i: Otro const_iterator de la guia
		 * @return True si apunta al mismo objeto, False en otro caso
		 * */
		bool operator==(const const_iterator &i)
		{
			return i.it == it;
		}
		/**
		 * @brief Comprueba si dos const_iterators son diferentes
		 * @param i: Otro const_iterator de la guia
		 * @return True si apuntan a distintos objetos, False en otro caso
		 * */
		bool operator!=(const const_iterator &i)
		{
			return i.it != it;
		}
		/**
		 * @brief Sobrecarga del operador de asignacion para const_iterators
		 * @param i: const_iterator de la guia
		 * @return const_iterator que apunta a donde apunta i
		 * */
		const_iterator& operator=(const const_iterator &i){
			it=i.it;
			return *this;
		}
		/**
		 * @brief Sobrecarga del operador + para const_iterators
		 * @param numero numero de posiciones que queremos avanzar
		 * @return const_iterador que apunta a posiciones mas adelante
		 * */
		const_iterator &operator+(int a)
		{
			for (int k = 0; k < a && it != final; k++)
				++it;
			return *this; //it+5
		}
		/**
		 * @brief Sobrecarga del operador - para const_iterators
		 * @param numero numero de posiciones que queremos retroceder
		 * @return const_iterador que apunta a posiciones detras
		 * */
		const_iterator &operator-(int a)
		{
			for (int k = a; k > 0 && it != inicio; k--)
				--it;
			return *this; //it-5
		}
		friend class Guia_Tlf;
	};

	/**
	 * @brief Inicializa un iterator al comienzo de la guia
	 * @return Iterator begin
	 * */
	iterator begin()
	{
		iterator i;
		i.it = datos.begin();
		i.final = datos.end();
		i.inicio = datos.begin();
		return i;
	}
	/**
	* @brief Inicializa un iterator al final de la guia
	* @return Iterator end
	* */
	iterator end()
	{
		iterator i;
		i.it = datos.end();
		i.final = datos.end();
		i.inicio = datos.begin();
		return i;
	}

	/**
	 * @brief Inicializa un const_iterator al comienzo de la guia
	 * @return Iterator begin constante
	 * */
	const_iterator begin() const
	{
		const_iterator i;
		i.it = datos.cbegin();
		i.final = datos.cend();
		i.inicio = datos.cbegin();
		return i;
	}
	/**
	* @brief Inicializa un const_iterator al final de la guia
	* @return Iterator end constante
	* */
	const_iterator end() const
	{
		const_iterator i;
		i.it = datos.cend();
		i.final = datos.cend();
		i.inicio = datos.cbegin();
		return i;
	}

	/**
	* @brief Interseccion de guias de telefonos
	* @param g: guia a interseccionar
	* @return: una nueva guia resultado de la interseccion del objeto al que apunta this y g
	* */
	Guia_Tlf operator*(const Guia_Tlf &g)
	{
		Guia_Tlf aux;
		map<string, string>::const_iterator it;
		for (it = g.datos.begin(); it != g.datos.end(); ++it)
		{
			if (datos.find(it->first) != datos.end())
				aux.insert(*it);
		}

		return aux;
	}
	/**
	 * @brief Devolver los telefonos de aquellos nombres que comiencen por una letra determinada
	 * @param letra letra a buscar en la guia
	 * @return Devuelve una guia con nombres que empiecen por la letra
	 * */
	Guia_Tlf buscarPorLetraInicial(char letra){
		Guia_Tlf aux;
		char letraAux=toupper(letra);
		map<string,string>::const_iterator it;

		for (it=datos.begin(); it != datos.end(); ++it){
			string nombre = it->first;
			char inicial = toupper(nombre[0]);

			if (inicial == letraAux)
				aux.insert(*it);
		}
		return aux;
	}
	/**
	 * @brief Devolver los telefonos de aquellos que empiecen por un cierto numero
	 * @param numero numero a buscar en la guia
	 * @return Nueva Guia con telefonos que empiezan por esos numeros
	 * */

	Guia_Tlf buscarPorPrimerNumero(int numero){
		Guia_Tlf aux;
		map<string,string>::const_iterator it;

		for (it=datos.begin(); it != datos.end(); ++it){
			string numeroTLF = it->second;
			char inicial = numeroTLF[0];

			if (inicial - '0' == numero)
				aux.insert(*it);
		}
		return aux;
	}
	/**
	 * @brief Devolver los telefonos cuyos nombres asociados estan dentro de un rango
	 * @param nombre1 Minimo del intervalo
	 * @param nombre2 Maximo del intervalo
	 * @return Guia con datos del rango
	 * */
	Guia_Tlf IntervaloNombre(const string& nombre1, const string& nombre2){
		map<string,string>::const_iterator it, itMin, itMax;
		Guia_Tlf aux;
		for (it=datos.begin(); it != datos.end(); ++it){
			if (nombre1 == it->first)
				itMin=it;
			if (nombre2 == it->first)
				itMax=it;
		}

		do{
			aux.insert(*itMin);
			++itMin;
		}while(itMin != itMax);

		aux.insert(*itMin);
		return aux;
	}

};
#endif
