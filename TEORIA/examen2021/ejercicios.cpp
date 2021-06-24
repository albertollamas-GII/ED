#include <list>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct enfrentamiento{
    unsigned char eq1, eq2;
    unsigned int puntos_eq1, puntos_eq2;
};

class liga{
    private:
        list<enfrentamiento> res;
    public:

        int enfrentamientosganados(unsigned char codigo){
            list<enfrentamiento>::const_iterator it;
            int victorias = 0;
            for (it = res.cbegin(); it != res.cend(); ++it){
                if (it->eq1 == codigo){
                    if (it->puntos_eq1 > it->puntos_eq2){
                        victorias++;
                    }
                }else if (it->eq2 == codigo){
                    if(it->puntos_eq2 > it->puntos_eq1)
                        victorias++;
                }
            }
            return victorias;
        }

        class iterator{
            private:
                list<enfrentamiento>::iterator it, fin;
            public:
                bool operator==(const iterator &i) const{
                    return i.it == it;
                }
                bool operator != (const iterator &i) const{
                    return i.it!= it;
                }
                iterator& operator++(){
                    bool esEmpate = false;
                    while (it != fin && !esEmpate){
                        if (it->puntos_eq1 == it->puntos_eq2)
                            esEmpate = true;;
                        else ++it;
                    }
                    return *this;
                }
                enfrentamiento& operator*(){
                    return *it;
                }
                friend class liga;
        };
        iterator begin(){
            iterator i;
            i.it=res.begin();
            i.fin = res.end();
            if (i.it->puntos_eq1 != i.it->puntos_eq2) ++i;
            return i;
        }
        iterator end(){
            iterator i;
            i.it = res.end();
            i.fin = res.end();
            return i;
        }
};

// 3
int orden(const list<int> &L){
    list<int>::const_iterator it, it2;
    int orden = 0;
    it = it2 = L.begin();
    if (L.empty()) return 0;
    ++it2; bool ascendiente = true; bool descendiente = true;
    while (it2 != L.end() && (ascendiente || descendiente)){
        if (*it < *it2){
            descendiente = false;
        } else if (*it > *it2){
            descendiente = false;
        }
        ++it;++it2;
    }
    if (ascendiente){
        orden = 1;
    } else if (descendiente)
        orden = 2;

    return orden;
}

//5
int sumanodos(bintree<int> ab){
    return sumanodos(ab.root());
}

int sumanodos(bintree<int>::node n){
    if (!n.null()){
        return *n + sumanodos(n.left()) + sumanodos(n.right());
    } else {
        return 0;
    }
}

template<typename T>
class contenedor{
    private:
        unordered_map<T, bintree<int>> datos;
    public:
        class iterator{
            private:
                unordered_map<T, bintree<int>>::iterator it, fin;
            public:
                bool operator==(const iterator &i) const{
                    return i.it == it;
                }

                bool operator !=(const iterator &i) const{
                    return i.it != it;
                }

                pair<T,bintree<T>> operator*(){
                    return *it;
                }

                iterator& operator++(){
                    ++it;
                    while (it != fin && sumanodos(it->second) % 2 != 0)
                    {
                            ++it;
                    }
                    return *this;
                }
                friend class contenedor;
        };

        iterator begin()
        {
            iterator i;
            i.it = datos.begin();
            i.fin = datos.end();
            if (sumanodos(i.it->second) % 2 != 0)
                ++i;
            return i;
        }
        iterator end()
        {
            iterator i;
            i.it = datos.end();
            i.fin = datos.end();
            return i;
        }
};


//
             4
        /        \
       32        25
      /  \       / \
     16   5     15  10
    /\    /\    /\  /\
   18 23 30 12 17


//Febrero 2017-18

struct palabra {
    string pal;
    unsigned int pos;
};

class libro{
    private:
        list<palabra> datos;
    public:

        list<int> posiciones (const string &palabra){
            list<int> salida;
            list<palabra>::const_iterator it;
            for (it = datos.cbegin(); it != datos.cend(); ++it){
                if ((*it).pal == palabra) salida.push_back(it->pos);
            }
            return salida;
        }
        //pereza entera
        class iterator{
            private:
                list<palabra>::iterator it, fin;
            public:
                iterator& operator ++(){
                    bool salir = false;
                    while(it != fin && !salir){
                        if ((it->pal[0] == 'z' || it->pal[0] == 'Z') && it->pos % 2 == 0 )
                            salir = true;
                        else 
                            ++it;
                    }
                    return it;
                }
        };

        iterator beginz(){
            iterator i;
            i.it = datos.begin();
            i.fin = datos.end();
            if(i.it->pal[0] == 'z' || i.it->pal[0] == 'Z') && i.it->pos % 2 == 0 ) ++i;
            return i;
        }
};

vector<list<string>> palabrasCap(const map<string, list<pair<int,int> > > &libro){
    map<string, list<pair<int, int>>>::const_iterator itM;
    vector<list<string>> salida;
    int i = 1;

    for (itM = libro.cbegin(); itM != libro.cend(); ++itM){
        if ()
    }

}



//2020
int sumalista(const list<int> &L){
    int suma = 0;
    list<int>::const_iterator it; it = L.cbegin();
    for (; it!= L.cend(); ++it){
        suma+= *it;
    }
    return suma;
}

int minsum(const list<int> &L){

    int minimo= L.front();
    int suma = 0;
    list<int> aux;
    list<int>::iterator it1, it2;

    for (it1 = L.begin(); it1 != L.end(); ++it1){
        for (it2 = it1; it2 != L.end(); ++it2){
            aux.push_back(*it2);
            suma = sumalista(aux);
            if (suma < minimo)
                minimo = suma;
        }
        aux.clear();
    }

    return minimo;
}

{
    8, 16, 12, 41, 10, 62, 27, 65, 13
}

k     |8    16    12    41    10    62    27    65    13    
------|-----------------------------------------------------
h(k)  |8     3     12    2    10     10    1    0      0   
------|-----------------------------------------------------
// h_o(k)|8     5     6     1     7     9     6     6    8    
// ------|-----------------------------------------------------

h(k) = k % 13
h_0(k) = k % 11
h_i(k) = (hi-1(k)+h0(k)) % 13

//Colision en h(62) y h(13)
h_0(13) = 2
h2(13) = (2+0) % 13 = 2
h3(13) = (2+2) % 13 = 4

h_0(62) = 7
h2(62) = (7+10) % 13 = 4
h3(62) = (7+4) % 13 = 11

//Tabla Hash
k     |65    27    41   16   13        51          8       *10   62   12       
------|---------------------------------------------------------------
      |0     1     2    3    4    5    6    7    8    9    10    11   12
------|---------------------------------------------------------------


* == borrado 
h(51) = 12
h0(51) = 7
h2(51) = (7+12) % 13 = 6


{
    8, 16, 12, 41, 10, 62, 27, 65, 13
}

8
\
16
/
12

//Caso B: RSD + RSI

12
/\
8 16
\   \
10  41
     \
     62

//Caso D: rsd

 12
/  \
8  41
\  /\
10 16 62
   /\   \
   13 27 65


int suma_n(bintree<int>::node n){
    int suma = 0;
    if (!n.null()){
        suma+= *n + suma(n.left()) + suma(n.right());
        return suma;
    }else{
        return 0;
    }
}

void prune_to_level(bintree<int> & A, int level){
    typedef pair<bintree<int>::node, int > minfo;
    minfo aux;
    queue <minfo> cola;
    bintree<int> subarbol;
    cola.emplace(A.root(), 0);

    while(!cola.empty()){
        aux = cola.front();
        cola.pop();

        if (aux.second == level){
            aux.first = suma_n(aux.first);

            A.prune_left(aux.first, subarbol);
            A.prune_right(aux.first, subarbol);
        }else{
            if (!aux.first.left().null())
                cola.emplace((aux.first).left(), aux.second);
            if (!aux.first.right().null())
                cola.emplace((aux.first).right(), aux.second);
        } 
    }
}






