#include <iostream>
#include <vector>

using namespace std;

//Dado un vector y un entero, reordena el vector alrededor de un indice k
int stablepartition(int x, vector<int> &A){
    int i = 0;
    int j = 0, k=0;
    vector<int> aux, mayor;
    while (i < A.size()){
        if (A[i] <= x){
           int num = A[i];
           aux.push_back(num);
        }
        i++;  
    }

    if (aux.size() != 0){
        return aux.size()-1;
    }
    else
    {
        return -1;
    }
    
}

int main(){
    vector<int> uno = {1,10,2,5};
    int x = 10;

    int res = stablepartition(x, uno);

    cout << endl << res << endl;

    for (int i = 0; i < uno.size(); i++)
        cout << uno[i] << " ";

    
    cout << "\n\n";
}