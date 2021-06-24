#include <map>
#include <iostream>
#include <set>
#include <string>
#include <list>
#include <vector>
#include <queue>

using namespace std;

//Funcion auxiliar que calcula la suma desde un nodo dado
int suma_n(bintree<int>::node n){
    int suma = 0;
    if (!n.null()){
        suma+= *n + suma(n.left()) + suma(n.right());
        return suma;
    }else{
        return 0;
    }
}

//Funcion auxiliar que devuelve true si hay un recorrido de manera ascendente
bool camino_ascendente(bintree<int>A, bintree<int>::node n){
    bool camino_izquierda = false, camino_derecha = false;
    if (n.right().null() && n.left().null())
        return true;
    else{
        if (!n.right()).null() && *n.right() > *n){
            camino_derecha = camino_ordenado(A, n.right());
        }
        if (!n.left().null() && *n.left() > *n)
            camino_izquierda = camino_ordenado(A, n.left());
    
        return camino_derecha || camino_izquierda;
    }
}


bool camino_especial (bintree<int> A, bintree<int>::node n, int k){
    bool camino_ascendente = camino_ordenado(A, n);
    bool es_suma = suma_n(n) == k;

    return es_suma && camino_ascendente;

}

