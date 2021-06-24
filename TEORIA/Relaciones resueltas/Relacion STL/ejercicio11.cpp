/**
 *  Entrada: 
 * 1 2 3 & 4 5 6 & 7 8 & @
 * 7 8 4 5 6 1 2 3 @
 * */


#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool iscomb(vector<list<int>> VL, list<int> L);

bool ispref(list<int> Lpref, list<int> L);

int main()
{
    vector<list<int>> VL;
    list<int> L, aux;
    string elem;
    bool retorno;

    cout << "Introduce el vector de listas " << endl;
    cout << "Itroduce & para indicar fin de una lista e introduce @ para indicar fin de la lista de listas" << endl;
    do
    {
        cin >> elem;
        if (elem != "@" && elem != "&")
            aux.push_back(stoi(elem));
        if (elem == "&")
        {
            VL.push_back(aux);
            aux.clear();
        }
    } while (elem != "@");

    cout << "Introduce los elementos de la lista " << endl;
    cout << "Introduce @ para fin de la lista" << endl;
    do
    {
        cin >> elem;
        if (elem != "@")
            L.push_back(stoi(elem));
    } while (elem != "@");

    retorno = iscomb(VL, L);

    if (retorno)
        cout << "True " << endl;
    else
        cout << "False" << endl;

    return 0;
}

bool iscomb(vector<list<int>> VL, list<int> L)
{
    list<int> aux;
    int longitudVL = 0;
    static bool is_comb;
    //Miro si la suma de las longitudes de VL es igual a la de L
    for (int i = 0; i < VL.size(); i++){
        aux = VL[i];
        longitudVL+= aux.size();
    }

    if (longitudVL != L.size())
        return false;
    
    //Empiezo recursividad
    if (VL.size() == 1){ //Caso base
        if(VL[0] == L) is_comb = true;
        else is_comb = false;
    }

    for (int i = 0; i < VL.size(); i++){
        if (ispref(VL[i], L)){
            for (int j = 0; j < VL[i].size(); j++)
                L.pop_front();
            VL.erase(VL.begin()+i);
            iscomb(VL,L);
        }
    }
    return is_comb;
}

bool ispref(list<int> Lpref, list<int> L)
{
    while (!Lpref.empty())
    {
        if (Lpref.front() != L.front())
            return false;
        else
        {
            L.pop_front();
            Lpref.pop_front();
        }
    }
    return true;
}