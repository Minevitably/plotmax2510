#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxCount = 0;
        std::sort(nums.begin(), nums.end());
        int prevCount = 0;
        int prev = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            int curr = nums[i];
            while (i < nums.size() && nums[i] == curr) {
                count++;
                i++;
            }
            i--;

            if (prev != INT_MIN && curr - prev == 1) {
                maxCount = std::max(maxCount, count + prevCount);
            }
            prev = curr;
            prevCount = count;
        }
        return maxCount;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
