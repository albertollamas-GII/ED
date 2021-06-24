#include <iostream>
#include <list>
#include <map>

using namespace std;

class Diccionario{
private:
    map<int,list<string>> datos;
public:
    class iterator{
        private: 
            map<int,list<string>>::iterator it;
            map<int,list<string>>::iterator final, inicio;
        public:
            pair<int,list<string>> &operator*(){
                return *it;
            }
            iterator& operator++(){
                while(true){
                    ++it;
                    if(primo(*it))
                        return *this;
                    else if(it == final)
                        return *this;
                }
            }

            iterator& operator--(){
                while(true){
                    --it;
                    if(primo(*it))
                        return *this;
                    else if(it == inicio)
                        return *this;
                }
            }

            bool operator==(const iterator& i){
                return i.it == it;
            }

            bool operator != (const iterator& i){
                return i.it != it;
            }

            friend class Diccionario;
    };

    iterator begin(){
        iterator i;
        i.it = datos.begin();
        i.inicio = datos.begin();
        i.final = datos.end();
        return i;
    }
    
    iterator end(){
        iterator i;
        i.it = datos.end();
        i.inicio = datos.begin();
        i.final = datos.end();
        return i;
    }
};