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
        vector<bool> flag(n,false);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (flag[nums[i] - 1]) {
                ans.emplace_back(nums[i]);
            }
            flag[nums[i] - 1] = true;
        }
        for (int i = 0; i < n; i++) {
            if (!flag[i]) {
                ans.emplace_back(i + 1);
                break;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
