#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>

using namespace std;


class RandomizedSet {
public:

    set<int> s;
    vector<int> v;
    RandomizedSet() {}
    
    bool insert(int val) {
        if(s.find(val) == s.end()){
            s.insert(val);
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(s.find(val) == s.end()){
            return false;
        }
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIdx = rand() % s.size();
        auto it = s.begin();
        advance(it, randomIdx);
        return *it;
    }
};


int main() {
    RandomizedSet* r = new RandomizedSet();

    cout << r->insert(1) << endl;
    cout << r->insert(10) << endl;
    cout << r->insert(20) << endl;
    cout << r->insert(30) << endl;
    cout << r->getRandom() << endl;
    cout << r->getRandom() << endl;
    cout << r->getRandom() << endl;
    cout << r->getRandom() << endl;
    cout << r->getRandom() << endl;
    cout << r->getRandom() << endl;
    cout << r->getRandom() << endl;
    cout << r->getRandom() << endl;
    cout << r->getRandom() << endl;
    cout << r->getRandom() << endl;
    cout << r->getRandom() << endl;
    cout << r->getRandom() << endl;
}

/*
"insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"
[], [1], [2], [2], [], [1], [2], []
*/