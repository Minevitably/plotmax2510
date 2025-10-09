#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        int tryTimes = 0;
        int recLeft = -1;
        int recRight = -1;
        while (left < right) {
            if (s[left] != s[right]) { // encounter exception
                // secure the scene
                // don't touch anything
                if (tryTimes == 0) {
                    recLeft = left;
                    recRight = right;
                }
                tryTimes++;
                // can't recover from exception
                if (tryTimes > 2) {
                    return false;
                }
                // try to delete left char
                if (tryTimes == 1) {
                    left = recLeft;
                    right = recRight;
                    left++;
                }
                // try to delete right char
                if (tryTimes == 2) {
                    left = recLeft;
                    right = recRight;
                    right--;
                }
            } else {
                left++;
                right--;
            }
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
