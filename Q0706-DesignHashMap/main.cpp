#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <list>

using namespace std;

class MyHashMap {
private:
    const int BASE = 769;
    vector<list<pair<int, int>>> buckets;
public:
    MyHashMap() : buckets(BASE) {

    }

    void put(int key, int value) {
        int h = hash(key);
        list<pair<int, int>>& bucket = buckets[h];
        // if key exist, update value and return
        // else just insert (key, value).
        for (auto& entry: bucket) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }
        bucket.emplace_back(key, value);
    }

    int get(int key) {
        int h = hash(key);
        list<pair<int, int>>& bucket = buckets[h];
        if (bucket.empty()) {
            return -1;
        }
        for (auto& entry: bucket) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        // notice this is exception
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        list<pair<int, int>>& bucket = buckets[h];
        if (bucket.empty()) {
            return;
        }
        for (auto it = bucket.begin(); it != bucket
        .end(); ++it) {
            if ((*it).first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
private:
    int hash(int key) {
        return key % BASE;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
