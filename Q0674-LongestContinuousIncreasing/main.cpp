#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLength = 1;
        int count = 1;
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] < nums[i + 1]) {
                count++;
            } else {
                maxLength = max(maxLength, count);
                count = 1;
            }
        }
        maxLength = max(maxLength, count);
        return maxLength;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7};
    (new Solution())->findLengthOfLCIS(nums);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
