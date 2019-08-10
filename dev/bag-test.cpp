// #include <msgpack.hpp>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <cassert>
#include <gecko/msgpack/msgs.hpp>
#include <map>
#include <any>

using namespace std;


class BagIt {
public:
    BagIt(){}

    template<class MSG>
    void push(string key, const MSG& m){
        if (db.count(key) > 0){
            db[key].push_back(m);
        }
        else {
            vector<MSG> v{m};
            db[key] = v;
            // db[key].push_back(m);
        }
    }

protected:
    std::map<std::string, std::vector<std::any>> db;
};

int main(){
    BagIt bag;

    for (int i=0; i<100; i++) {
        vec_t a(i/10,200,-i);
        cout << ">> i: " << i << endl;
        bag.push<vec_t>("hi", a);
    }

    return 0;
}
