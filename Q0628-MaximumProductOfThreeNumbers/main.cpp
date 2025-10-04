#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = nums[n - 3] * nums[n - 2] * nums[n - 1];
        int b = nums[0] * nums[1] * nums[n - 1];
        return std::max(a, b);
    }
};


int main() {
    vector<int> t = {-1,-2,-3,-4};
    (new Solution())->maximumProduct(t);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
