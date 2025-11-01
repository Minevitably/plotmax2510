#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int right = n - 1;
        while (left < right) {
            // find a odd
            while (left < right && (nums[left] & 1) == 0) {
                left++;
            }
            // find a even
            while (left < right && (nums[right] & 1) == 1) {
                right--;
            }
            // swap
            if (left < right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }
        return nums;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
