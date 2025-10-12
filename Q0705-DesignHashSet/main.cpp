#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <list>

using namespace std;

class MyHashSet {
private:
    const int BASE = 769;
    vector<list<int>> buckets;

    int hash(int key) {
        return key % BASE;
    }

public:
    MyHashSet() : buckets(BASE) {

    }

    void add(int key) {
        int h = hash(key);
        for (int num: buckets[h]) {
            if (num == key) {
                return;
            }
        }
        buckets[h].emplace_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        if (buckets[h].empty()) {
            return;
        }
        for (auto it = buckets[h].begin(); it != buckets[h].end(); ++it) {
            if (*it == key) {
                buckets[h].erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int h = hash(key);
        if (buckets[h].empty()) {
            return false;
        }
        for (int num: buckets[h]) {
            if (key == num) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
