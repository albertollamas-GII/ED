#include <iostream>
#include "../include/pila_max.h"

using namespace std;

int main(){
    PilaMax p;

    // p.poner(12);
    // p.poner(5);
    // p.poner(6);
    // p.poner(20);
    // p.poner(2);

    p.poner(3);
    p.poner(0);

    int i;
    for ( i=10; i>=0 ; i--)
    p.poner(i);


    while (!p.esta_vacia() ){
        Elemento x = p.tope();
        cout << x << endl;
        p.quitar();
    }

    return 0;
}
