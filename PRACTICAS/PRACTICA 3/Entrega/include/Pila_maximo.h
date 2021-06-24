#include <utility>
#include <stack>
using namespace std;


#ifndef PILA_MAXIMO_H
#define PILA_MAXIMO_H

template<class T>
class Pila_maximo{
    private:
        stack<pair<T,T> > pilamax;
    
    public:
        T Top();
        T maximo();
        bool Empty() const;
        int Size() const;
        void Push(T elemento);
        void Pop();
        
};

#include "Pila_maximo.cpp"

#endif /* PILA_MAXIMO_H */

