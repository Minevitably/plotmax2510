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
        int p = 0;
        int q = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                q++;
            } else {
                p++;
            }
        }
        if (q >= 2) {
            bool flag = nums[0] * nums[1] > nums[n - 3] * nums[n - 2];
            if ((p > 0 && p < 3) || (p >= 3 && flag)) {
                return nums[0] * nums[1] * nums[n - 1];
            }
        }
        return nums[n - 3] * nums[n - 2] * nums[n - 1];
    }
};


int main() {
    vector<int> t = {-1,-2,-3,-4};
    (new Solution())->maximumProduct(t);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
