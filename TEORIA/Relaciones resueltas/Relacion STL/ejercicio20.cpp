#include <map>
#include<list>
using namespace std;

void apply_map(const list<int> &L, const map<int,int> &M, list<int> &ML){
    list<int>::const_iterator it;

    for(it=L.begin(); it != L.end();++it){
        if(M.find(*it) != M.end())
            ML.insert(ML.end(), M.find(*it)->second);
    }
}