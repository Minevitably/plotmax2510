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
    int dominantIndex(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        int n = nums.size();
        int max = INT_MIN;
        int maxIndex = -1;
        int second = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > max) {
                max = nums[i];
                maxIndex = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > second && nums[i] != max) {
                second = nums[i];
            }
        }
        if (max >= second * 2) {
            return maxIndex;
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
