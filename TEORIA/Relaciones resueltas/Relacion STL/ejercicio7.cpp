#include <iostream>
#include <queue>

using namespace std;

void rotacion(queue<int> &C){
    int contador = 0; bool par = false;
    while (!par && contador < C.size()){
        if (C.front() % 2 != 0){
            C.push(C.front());
            C.pop();
            contador++;
        } else
        {
            par= true;
        }
        
    }

}

int main (){

    queue<int> micola;

    int miint;

    cout << "\nIntroduce numeros para añadir a la cola: " ;
    cin >> miint;
    while (miint >= 0){
        micola.push(miint);
        cin >> miint;
    }

    rotacion(micola);
    cout << "\nCola aplicada la rotacion: " << endl;
    while (!micola.empty())
    {
        cout << ' ' << micola.front();
        micola.pop();
    }
    cout << '\n';
}