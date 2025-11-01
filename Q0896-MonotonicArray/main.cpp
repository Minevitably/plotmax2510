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
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool monotonicInc = true;
        bool monotonicDec = true;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                monotonicInc = false;
                break;
            }
        }
        if (monotonicInc) {
            return true;
        }
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                monotonicDec = false;
                break;
            }
        }
        return monotonicDec;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
