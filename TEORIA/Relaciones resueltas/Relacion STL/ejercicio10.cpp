#include <iostream>
#include <list>

using namespace std;

void agrupar_elemento(list<int> & entrada, int k){

    list<int> aux, aux2;
    bool k_encontrado= false;
    aux = entrada;
    entrada.clear();
    while(!aux.empty()){
        if (aux.front() == k && !k_encontrado){
            entrada.push_back(aux.front());
            aux.pop_front();
            aux2 = aux;
            while(!aux2.empty()){
                if (aux2.front() != k){
                    aux2.pop_front();
                } else{
                    entrada.push_back(aux2.front());
                    k_encontrado = true;
                    aux2.pop_front();
                }
            }
        } else if (aux.front() != k){
            entrada.push_back(aux.front());
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

    cout << "\nIntroduzca el elemento a agrupar: ";
    cin >> k;

    agrupar_elemento(entrada, k);

    cout << "\nSale de agrupar" << endl;
    while (entrada.size() != 0){
        cout << entrada.front() << " ";
        entrada.pop_front();
    }
    cout << endl;
}