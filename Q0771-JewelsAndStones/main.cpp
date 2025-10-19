#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelsSet;
        for (char &jewel: jewels) {
            jewelsSet.insert(jewel);
        }
        int count = 0;
        for (char &stone: stones) {
            if (jewelsSet.count(stone) > 0) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
