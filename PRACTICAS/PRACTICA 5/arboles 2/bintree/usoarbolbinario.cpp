#include <iostream>
#include "bintree.h"
#include<queue>

using namespace std;

/**
//Ejercicio 2 Funcion que cuente hojas.
template <class T>
int ContarHojas( bintree<T>& a){
	int hojas;
	int  cont=0;
	for ( bintree<int>::preorder_iterator i = a.begin_preorder(); i!=a.end_preorder(); ++i){
		if(esHoja(a,*i))
			cont++;	
	}
	return cont;
	
}
*/
//Ejercicio 4 Hacer que funcione Esquema.
template <class T>
void Esquema(const bintree<T>& a, 
             const typename bintree<T>::node n, string& pre){
  int i;
  
  if (n.null())
    cout << pre << "-- x" << endl;
  else {
    cout << pre << "-- " << *n << endl;
    if (n.right()!=0 || n.left()!=0) {// Si no es una hoja
      pre += "   |";
      Esquema(a, n.right(), pre);
      pre.replace(pre.size()-4, 4, "    ");
      Esquema (a, n.left(), pre);
      pre.erase(pre.size()-4, 4);    
    }
  }
}
//Ejercicio 3 Hacer que funcione Altura.
template <class T>
int Altura(const bintree<T>& a, 
           const typename bintree<T>::node n){
  int iz,de;
  if (n.null())
    return -1;
  else {
    iz= Altura(a,n.left());
    de= Altura(a,n.right());
    return 1+(iz>de?iz:de);
  }
}

template <class T>
bool esHoja(const bintree<T> & A, const typename bintree<T>::node &v)
{
  return ( v.left().null()  && v.right().null() );
}

template <class T>
bool esInterno(const bintree<T> & A, const typename bintree<T>::node &v)
{
  return ( !v.left().null() || !v.right().null() );
}

template <class T>
void PreordenBinario(const bintree<T> & A,
typename bintree<T>::node v) {
  if (!v.null()) {
       cout << *v; // acción sobre el nodo v.
       PreordenBinario(A, v.left());
       PreordenBinario(A, v.right());
  }
}

template <class T>
void InordenBinario(const bintree<T> & A,
 typename bintree<T>::node v)
{
  if (!v.null()) {
       InordenBinario(A, v.left());
       cout << *v; //acción sobre el nodo v.
       InordenBinario(A, v.right());
  }
}

template <class T>
void PostordenBinario(const bintree<T> & A,
 typename bintree<T>::node v)
{
  if (!v.null()) {
       PostordenBinario(A, v.left());
       PostordenBinario(A, v.right());
       cout << *v; // acción sobre el nodo v.
  }
}

template <class T>
void ListarPostNiveles(const bintree<T> &A, typename bintree<T>::node n) {
  queue<typename bintree<T>::node> nodos;
  if (!n.null()) {
    nodos.push(n);
    while (!nodos.empty()) {
      n = nodos.front(); nodos.pop();
      cout << *n;
      if (!n.left().null()) nodos.push(n.left());
      if (!n.right().null())
         nodos.push(n.right());
    }
  }
}


template <class T>
ostream & operator << (ostream & os, bintree<T> &arb)
{
  
cout << "Preorden:";

for (typename bintree<T>::preorder_iterator i = arb.begin_preorder(); i!=arb.end_preorder(); ++i)
  cout << *i << " ";

cout << endl;
}

int main()
{  // Creamos el árbol:
  //        7
  //     /    \
  //    1      9
  //  /  \    /
  // 6    8  5
  //       \
  //       4
// Ejercicio 1 Crear otro arbol para leer.
  //Creamos el árbol:
  //        3
  //      /  \
  //     6    8
  //     \   / \
  //     8  5   4
  //    /   \
  //   2    4       
typedef bintree<int> bti;
bintree<int> Arb(3);
Arb.insert_left(Arb.root(), 6);
Arb.insert_right(Arb.root(), 8);
Arb.insert_right(Arb.root().left(), 8);
Arb.insert_left(Arb.root().left().right(), 2);
Arb.insert_left(Arb.root().right(), 5);
Arb.insert_right(Arb.root().right(),4);
Arb.insert_right(Arb.root().right().left(),4);

cout << "Altura: "<<Altura(Arb,Arb.root())<< endl;

string pre= " ";
Esquema(Arb,Arb.root(),pre);

cout << "Preorden:";

for (bintree<int>::preorder_iterator i = Arb.begin_preorder(); i!=Arb.end_preorder(); ++i)
  cout << *i << " ";

cout << endl;


cout << "Inorden:";

for (bintree<int>::inorder_iterator i = Arb.begin_inorder(); i!=Arb.end_inorder(); ++i)
  cout << *i << " ";

cout << endl;


cout << "Postorden:";

for (bintree<int>::postorder_iterator i = Arb.begin_postorder(); i!=Arb.end_postorder(); ++i)
  cout << *i << " ";

cout << endl;


cout << "Por Niveles:";

for (bintree<int>::level_iterator i = Arb.begin_level(); i!=Arb.end_level(); ++i)
  cout << *i << " ";

cout << endl;


//cout << Arb;

//cout << "El numero de hojas son: "<< ContarHojas(Arb) << endl; 










}

