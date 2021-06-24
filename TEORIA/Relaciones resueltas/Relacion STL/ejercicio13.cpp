#include <iostream>
#include <list>

using namespace std;

void expand(list<int> &L, int m){
    list<int>::iterator it = L.begin();
    while (it != L.end())
    {
        int a_poner = *it;
        it = L.erase(it);
        while(a_poner > 0){
            int val;
            if (a_poner>m)
                val = m;
            else 
                val = a_poner;
                
            it = L.insert(it,val);
            a_poner = a_poner-val;
            it++;
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

    expand(entrada, k);

    while (entrada.size() != 0){
        cout << entrada.front() << " ";
        entrada.pop_front();
    }
    cout << endl;
}
