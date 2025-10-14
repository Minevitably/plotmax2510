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
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        for (const auto &item: nums) {
            rightSum += item;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i - 1 >= 0) {
                leftSum += nums[i - 1];
            }
            rightSum -= nums[i];
            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
