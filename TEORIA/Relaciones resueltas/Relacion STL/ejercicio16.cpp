#include <iostream>
#include <set>
#include <ctime>

using namespace std;

multiset<int> multi_interseccion (const multiset<int> & m1, const multiset<int> & m2){
    multiset<int> salida;
    multiset<int>::iterator it1 = m1.begin(),it2 = m2.begin();

    while(it1 != m1.end() && it2 != m2.end()){
        if (*it1 < *it2){
            ++it1;
        } else if(*it1 > *it2){
            ++it2;
        } else{
            salida.insert(*it1);
            ++it1; ++it2;
        }
    }
    return salida;
}

int main(){
    srand(time(0));
    multiset<int> myset1;
    for (int i = 0; i < 10; i++){
        myset1.insert(rand() % 10);
    }
    cout << "\nMi set1 random: ";
    multiset<int>::iterator it;
    for (it = myset1.begin(); it != myset1.end(); ++it)
        cout << *it << " ";
    cout << endl;
    multiset<int> myset2;
    for (int i = 0; i < 10; i++){
        myset2.insert(rand() % 10);
    }
    cout << "\nMi set2 random: ";
    for (it = myset2.begin(); it != myset2.end(); ++it)
        cout << *it << " ";
    cout << endl;

    multiset<int> salida = multi_interseccion(myset1,myset2);

    for (it = salida.begin(); it != salida.end(); ++it)
        cout << *it << " ";
    cout << endl;
}