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
    int binaryGap(int n) {
        vector<int> nums(32, 0);
        for (int i = 0; i < 32; ++i) {
            nums[i] = (n >> i) & 1;
        }
        int left = -1;
        int maxLength = 0;
        for (int right = 0; right < 32; ++right) {
            if (nums[right] == 1) {
                if (left != -1) {
                    maxLength = max(maxLength, right - left);
                }
                left = right;
            }
        }
        return maxLength;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
