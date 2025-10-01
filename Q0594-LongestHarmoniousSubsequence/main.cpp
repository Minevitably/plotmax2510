#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {

private:
    int countFrom(vector<int>& nums, int i, int curr) {
        int count = 0;
        while (i < nums.size() && nums[i] == curr) {
            count++;
            i++;
        }
        return count;
    }
public:
    int findLHS(vector<int>& nums) {
        int maxCount = 0;
        std::sort(nums.begin(), nums.end());
        int prev = INT_MIN;
        int curr;
        int prevCount = 0;
        int currCount = 0;
        for (int i = 0; i < nums.size(); i += currCount) {
            curr = nums[i];
            currCount = countFrom(nums, i, curr);
            if (prev != INT_MIN && curr - prev == 1) {
                maxCount = std::max(maxCount, currCount + prevCount);
            }
            prevCount = currCount;
            prev = curr;
        }
        return maxCount;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
