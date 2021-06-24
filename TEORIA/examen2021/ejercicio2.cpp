#include <map>
#include <iostream>
#include <set>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class MatrizSesgada
{
private:
    vector<list<int>> datos;
    int filas;
    int cols;

public:
  
  //a. Si lo encuentra devuelve el numero y sino -1 (suponemos que todos los datos introducidos>0)
    const int& operator()(int fil, int col) const
    {
        if (fil < this->filas && col < this->cols){
            vector<list<int>>::const_iterator itV;
            list<int>::const_iterator itL;
            int contador_filas = 0;
            for (itV = datos.cbegin(); itV != datos.cend(); ++itV){
                int contador_cols = 0;
                for(itL = (*itV).cbegin(); itL != (*itV).cend(); ++itL){
                    if (contador_filas == fil && contador_cols == col) 
                        return *itL;
                }
                contador_filas++;
            }

        } else{
            return -1;
        }

    }


    class iterator
    {
    private:
        vector<list<int>>::iterator itRow;
        vector<list<int>>::iterator itRowFin;
        list<int>::iterator itCol;
        vector<list<int>>::iterator itRowBegin;

    bool esPar (const list<int> &l){
        list<int>::const_iterator it;
        for (it = l.begin(); it != l.end(); ++it){
            if (*it % 2 == 0)
                return true;
        }
        return false;
    }
    public:
        list<int> operator*() const
        {
            return *itCol;
        }
        bool operator==(const iterator &i) const
        {
            return (i.itRow == itRow) && (i.itCol == itCol);
        }
        bool operator!=(const iterator &i) const
        {
            return !(i.itRow == itRow) && (i.itCol == itCol);
        }

        iterator& operator++(){
            ++itCol;
            if ((*itRow).end() == itCol)
                ++itRow;
            while(!(esPar(*itCol))){
                ++itCol;
                if (itRow != itRowFin)
                    itCol = (*itRow).begin();
                else
                    itCol = (*itRowBegin).end();
            }

            return *this;
        }
        
        friend class MatrizSesgada;
    };

    iterator begin(){
        
    }

    iterator end(){
        iterator i;
        i.itRow = datos.end();
        i.itCol = (*datos.begin()).end();
        i.itRowFin = datos.end();
        i.itRowBegin = datos.begin();

        return i;
    }
};