#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>


using std::pair;
using std::vector;
using std::string;
using std::stringstream;
using std::unordered_set;
using std::unordered_map;
using std::stack;

using std::max;
using std::min;
using std::getline;

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        unordered_map<int, int> changeCountMap;
        for (const int &bill: bills) {
            int requireChange = bill - 5;
            if (requireChange == 5) {
                changeCountMap[5]--;
            } else if (requireChange == 15) {
                if (changeCountMap[10] > 0) {
                    changeCountMap[10]--;
                    changeCountMap[5]--;
                } else {
                    changeCountMap[5] -= 3;
                }

            }
            if (changeCountMap[5] < 0 || changeCountMap[10] < 0) {
                return false;
            }
            changeCountMap[bill]++;
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
