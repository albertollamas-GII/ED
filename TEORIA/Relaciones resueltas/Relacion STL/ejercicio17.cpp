#include <iostream>
#include <set>
#include <ctime>
#include <vector>

using namespace std;

set<int> differencia(set<int> &s1, set<int> &s2)
{
    set<int>::iterator it1 = s1.begin();
    set<int> differencia;
    while (it1 != s1.end())
    {
        if (s2.find(*it1) == s2.end()){
            differencia.insert(*it1);
            ++it1;
        } else 
            ++it1;
    }
    return differencia;
}
//Un subconjunto propio(segun Google) es un subconjunto que esta incluido dentro de otro que tiene al menos un elemento distinto
bool included(vector<set<int>> &VS)
{
    vector<set<int>>::iterator it = VS.begin();
    set<int> aux;

    for (; it != VS.end(); ++it)
    {
        vector<set<int>>::iterator it2 = VS.begin();
        ++it2;
        if (it2 == VS.end())
            break;
        aux = differencia(*it, *it2);
        if (!aux.empty())
            return false;
        aux = differencia(*it2, *it);
        if (aux.empty())
            return false;
        it = it2;
    }
    return true;
}

int main()
{
    srand(time(0));
    vector<set<int>> VS;
    set<int> aux;
    string elem;
    cout << "Introduce el vector de set " << endl;
    cout << "Itroduce & para indicar fin de un set e introduce @ para indicar fin del vector de set" << endl;
    do
    {
        cin >> elem;
        if (elem != "@" && elem != "&")
            aux.insert(stoi(elem));
        if (elem == "&")
        {
            VS.push_back(aux);
            aux.clear();
        }
    } while (elem != "@");
    bool incluido = included(VS);
    if(incluido)
        cout << "\nSon subconjuntos propios";
    else
    {
        cout << "\nNo son subconjuntos";
    }
    
}
