#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class KthLargest {
private:
    int kth;
    vector<int> nums;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (int num: nums) {
            add(num);
        }
    }

    // [1, 2, 3, 5] 4
    int add(int val) {
        int n = nums.size();
        int i;
        for (i = 0; i < n; i++) {
            if (nums[i] > val) {
                break;
            }
        }
        nums.insert(nums.begin() + i, val);
        n++;
        if (n >= kth) {
            return nums[n - kth];
        }
        return -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
