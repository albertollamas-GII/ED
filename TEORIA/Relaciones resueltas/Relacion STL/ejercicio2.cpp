#include <iostream>
#include <vector>

using namespace std;


//a)
bool esmatrizbiordenada(vector<vector<int>> &M){
    bool es_biordenada = true;
    for (int i = 0; i < M.size() && es_biordenada; i++){
        int minimo = M[i][0];
        for (int j = 1; j < M[i].size() && es_biordenada; j++){
            if (minimo > M[i][j]){
                es_biordenada = false;
            }
        }
    }

    for (int j = 0; j < M[j].size() && es_biordenada; j++){
        int minimo = M[0][j];
        for (int i = 0; i < M.size() && es_biordenada; i++){
            if (minimo > M[i][j]){
                es_biordenada = false;
            }
        }
    }
    return es_biordenada;
}

//b
bool buscaenmatrizbiordenada(int x, vector<vector<int>> &B){
    
}


int main(){

    vector<vector<int>> M;
    const int FILAS = 3;
    const int COLUMNAS = 3;

    for (int i = 0; i < FILAS; i++){
        vector <int> fila;
        for (int j = 0; j < COLUMNAS; j++){
            int num; cin >> num;
            fila.push_back(num);
        }
        M.push_back(fila);
    }

    bool biordenada = esmatrizbiordenada(M);
    if (biordenada)
    {
        for (int i = 0; i < M.size(); i++)
        {
            for (int j = 0; j < M[i].size(); j++)
            {
                cout << M[i][j] << "\t";
            }
            cout << endl;
        }
    } else
    {
        cout << "no" << endl;
    }
    
}