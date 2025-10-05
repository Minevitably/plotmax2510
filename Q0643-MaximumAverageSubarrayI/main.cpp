#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum = 0.0f;
        for (int i = 0; i < k; i++) {
            maxSum += nums[i];
        }

        int n = nums.size();
        double sum = maxSum;
        for (int i = 1; i < n - k + 1; i++) {
            sum = sum - nums[i - 1] + nums[i + k - 1];
            maxSum = std::max(maxSum, sum);
        }
        return maxSum / k;
    }
};


int main() {
    vector<int> a = {0,4,0,3,2};
    (new Solution())->findMaxAverage(a, 1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
