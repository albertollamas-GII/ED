#include <stack>
#include <iostream>

using namespace std;

void imprime(stack<int> &S){
    stack<int> aux;
    int i;
    cout << "Pila S: ";
    while(!S.empty()){
        i = S.top();
        cout << i << " ";
        S.pop();
    }
    cout << endl;
}

void transformarpila(stack<int> &p){
    stack<int> aux;
    p.swap(aux);
    int tope;
    while(!aux.empty()){
        tope = aux.top();
        if (aux.size() != 1){
            aux.pop();
            while(tope == aux.top() && aux.size() != 1){
                aux.pop();
            }
            p.push(tope);
        } else if (aux.size() == 1){
            if (tope == aux.top())
                aux.pop();
            else
            {
                p.push(tope);
                aux.pop();
            }
            
        }  
    }
}

int main(){
    stack<int> mipila;

    int miint;

    cout << "\nIntroduce numeros para añadir a la pila: " ;
    cin >> miint;
    while (miint >= 0){
        mipila.push(miint);
        cin >> miint;
    }
    transformarpila(mipila);
    imprime(mipila);
}