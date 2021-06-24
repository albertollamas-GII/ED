#include <iostream>
#include <set>
#include <ctime>

using namespace std;

bool maspares(set<int> &s){
    set<int>::iterator it;
    set<int> cpar;
    set<int> cimpar;

    for (it=s.begin(); it != s.end(); ++it){
        if ((*it)%2 == 0)
            cpar.insert(*it);
        else
            cimpar.insert(*it);
    }

    return (cpar.size() > cimpar.size());

}
int main(){
    srand(time(0));
    set<int> myset;
    for (int i = 0; i < 10; i++){
        myset.insert(rand() % 10);
    }
    cout << "\nMi set random: ";
    set<int>::iterator it;
    for (it = myset.begin(); it != myset.end(); ++it)
        cout << *it << " ";
    cout << endl;

    if (maspares(myset))
        cout << "\nmayor pares";
    else 
        cout << "\nmayor impares";
}