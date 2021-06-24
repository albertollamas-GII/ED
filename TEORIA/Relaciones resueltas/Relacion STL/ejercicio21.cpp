#include <iostream>
#include <map>
#include <list>

using namespace std;

class Traductor{
    private:
        map<string, list<string>> datos;
    public:

    void insertar(const string &palabra, list<string> traduccion){
        pair<string, list<string>> p(palabra,traduccion);
        datos.insert(p);
    }

    list<string> consultar (const string &palabra){
        map<string,list<string>>::iterator i;
        list<string> consulta;
        consulta.clear();
        if((i=datos.find(palabra)) == datos.end()){
            break;
        } else
        {
            consulta.insert(i->second);
        }
        return consulta;   
    }

    class iterator{
        private:
            map<string,list<string>>::iterator it;
        public:
            iterator(){}

            iterator& operator++(){
                ++it;
                return *this;
            }

            iterator& operator--(){
                --it;
                return *this;
            }

            pair<const string, list<string>> &operator*(){
                return *it;
            }

            bool operator== (const iterator& i){
                return i.it == it;
            }
            bool operator!= (const iterator& i){
                return i.it != it;
            }
            iterator& operator= (const iterator &i){
                it = i.it;
                return *this;
            }
            friend class Traductor;
    };
};