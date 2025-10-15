#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Solution {
private:
    bool isSelfDivNum(int num) {
        int origin = num;
        while (num > 0) {
            int digit = num % 10;
            if (digit == 0 || (origin % digit != 0)) {
                return false;
            }
            num /= 10;
        }
        return true;
    }

public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; ++i) {
            if (isSelfDivNum(i)) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
