#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && nums[i] == nums[i + 1]) {
                ans.emplace_back(nums[i]);
            } else {
                sum += nums[i];
            }
        }
        int Sn = n * (n + 1) / 2;
        ans.emplace_back(Sn - sum);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
