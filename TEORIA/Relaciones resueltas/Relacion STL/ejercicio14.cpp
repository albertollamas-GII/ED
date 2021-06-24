#include <iostream>
#include <list>

using namespace std;

void subsecuencia(list<int> &L){

    list<int> aux;
    aux = L;
    int maximo = aux.front();
    L.clear();
    L.push_back(maximo);
    aux.pop_front();
    while(!aux.empty()){
        if (maximo < aux.front()){
            maximo = aux.front();
            L.push_back(maximo);
            aux.pop_front();
        } else {
            aux.pop_front();
        }
    }
}
int main(){
    list<int> entrada;
    string aux;
    int k = 0;
    cout << "Introduce los elementos de la lista" << endl;
    cout << "@ para finalizar" << endl;
    do
    {
        cin >> aux;
        if (aux != "@")
            entrada.push_back(stoi(aux));
    } while (aux != "@");

    subsecuencia(entrada);

    while (entrada.size() != 0){
        cout << entrada.front() << " ";
        entrada.pop_front();
    }
    cout << endl;
}