#include <iostream>
#include <stack>
#include <list>

using namespace std;

void imprime(stack<int> &S){
    stack<int> aux;
    int i;
    while(!S.empty()){
        i = S.top();
        aux.push(i);
        S.pop();
    }

    cout << "Pila S: ";
    while(!aux.empty()){
        i = aux.top();
        cout << i << " ";
        S.push(i);
        aux.pop();
    }
    cout << endl;
}
void subsecuencias_ordenadas(int &n){
    stack<int> S;
    S.push(1);
    int i;
    while(!S.empty()){
        imprime(S);
        i = S.top();
        if (n > i)
            S.push(i+1);
        else{
            S.pop();
            if (!S.empty()){
                i = S.top();
                S.pop();
                S.push(i+1);
            }
        }
    }

}

int main(){
    int n = 4;
    subsecuencias_ordenadas(n);
}