#include <iostream>
#include <fstream>
#include "diccionario.h"

/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre
listas de listas y otro sobre listas
*/
ostream &operator<<(ostream &os, const Diccionario<string, string> &D)
{

	Diccionario<string, string>::const_iterator it;

	for (it = D.begin(); it != D.end(); ++it)
	{

		list<string>::const_iterator it_s;

		os << endl
		   << (*it).clave << endl
		   << "Informacion asociada:" << endl;
		for (it_s = (*it).info_asoci.begin(); it_s != (*it).info_asoci.end(); ++it_s)
		{
			os << (*it_s) << endl;
		}
		os << "**************************************" << endl;
	}

	return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asociadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/

istream &operator>>(istream &is, Diccionario<string, string> &D)
{
	int np;
	is >> np;
	is.ignore(); //quitamos \n
	Diccionario<string, string> Daux;
	for (int i = 0; i < np; i++)
	{
		string clave;

		getline(is, clave);

		int ns;
		is >> ns;
		is.ignore(); //quitamos \n
		list<string> laux;
		for (int j = 0; j < ns; j++)
		{
			string s;
			getline(is, s);

			// cout<<"Significado leido "<<s<<endl;
			laux.insert(laux.end(), s);
		}
		Daux.Insertar(clave, laux);
	}
	D = Daux;
	return is;
}

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string> &l)
{
	list<string>::const_iterator it_s;

	for (it_s = l.begin(); it_s != l.end(); ++it_s)
	{
		cout << *it_s << endl;
	}
}

void ImprimirAlReves(const Diccionario<string, string> &D)
{
	if (D.size() == 0)
		return;
	Diccionario<string, string>::const_iterator it = D.end();
	do
	{
		--it;
		list<string>::const_iterator it_s;

		cout << endl
		   << (*it).clave << endl
		   << "Informacion asociada:" << endl;
		for (it_s = (*it).info_asoci.begin(); it_s != (*it).info_asoci.end(); ++it_s)
		{
			cout << (*it_s) << endl;
		}
		cout << "**************************************" << endl;
	} while (it != D.begin());
}

/*Lee un diccioario e imprime datos asociados a una clave.
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe:
                  ./usodiccionario < data.txt
*/
int main(int argc, char* argv[])
{
	if (argc != 2){
		cout << "\nPor favor, introduzca la ruta hasta el fichero con el diccionario (txt/fichero.txt) ";
		exit(1);
	}

	ifstream input(argv[1]);
	if (!input){
		cout << "\nError abriendo el fichero" << argv[1];
		exit(1);
	}

	Diccionario<string, string> D, DUnion, Daux, DDifer, Dinter;

	input >> D;
	cout << "\nDiccionario Leido con exito!" << endl << D;

	string a;

	cout << "Introduce una palabra" << endl;
	cin >> a;

	list<string> l = D.getInfo_Asoc(a);

	if (l.size() > 0)
		EscribeSigni(l);

	cout << "\nImprimiendo al reves: " << endl;
	ImprimirAlReves(D);

	string palabra = "Auricular";
	string definicion = "m. En los aparatos teléfonicos y, en general, en todos los empleados para percibir sonidos, parte de ellos o pieza aislada que se aplica"
	"a los oidos.";

	list<string> laux;
	laux.insert(laux.end(), definicion);

	Daux.Insertar(palabra, laux);

	cout << "\nEl nuevo diccionario con una palabra es: " << endl << Daux << endl;
	cout << "\nLa Union de ambos diccionarios es: " << endl;
	DUnion = D + Daux;

	cout << DUnion << endl;

	DDifer = DUnion - D;

	cout << "\nLa Diferencia de ambos diccionarios es: " << endl;
	cout << DDifer;

	string palabra1 = "Auricular";
	string palabra2 = "Programa";
	cout << "\nRango desde : " <<  palabra1 << " hasta " << palabra2 << endl;
	DUnion.IntervaloPalabras(palabra1,palabra2);

	cout << "\nInvirtiendo la Union: ";
	DUnion.invierte_Diccionario();
	cout << DUnion;


}
