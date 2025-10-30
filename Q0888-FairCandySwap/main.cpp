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
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes) {
        int aliceCount = 0;
        int bobCount = 0;
        for (int num: aliceSizes) {
            aliceCount += num;
        }
        for (int num: bobSizes) {
            bobCount += num;
        }
        for (int i = 0; i < aliceSizes.size(); ++i) {
            for (int j = 0; j < bobSizes.size(); ++j) {
                if (aliceCount - aliceSizes[i] + bobSizes[j] ==
                    bobCount - bobSizes[j] + aliceSizes[i]) {
                    return {aliceSizes[i], bobSizes[j]};
                }
            }
        }
        // never reach
        return {-1, -1};
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
