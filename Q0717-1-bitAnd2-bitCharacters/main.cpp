#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (int i = 0; i < bits.size(); ++i) {
            if (bits[i] == 1) {
                ++i;
            } else if (i == bits.size() - 1) {
                return true;
            }
        }
        return false;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
