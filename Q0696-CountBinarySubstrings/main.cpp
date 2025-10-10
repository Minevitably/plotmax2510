#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;


class Solution {
private:
    bool isGroupedConsecutively(const string &s, int i, int count) {
        if ((count & 1) == 1 || i + count > s.size()) {
            return false;
        }
        int left = i;
        int right = i + count - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    int countBinarySubstrings(string s) {
        int count = 0;
        int k = 1;
        for (int i = 0; i < s.size(); i++) {
            while (i + k < s.size() && s[i] == s[i + k]) {
                k++;
            }
            bool outOfBound = (i + 2 * k > s.size());
            bool isTargetStr = isGroupedConsecutively(s, i, 2 * k);
            if (!outOfBound && isTargetStr) {
                count += k;
                i += k - 1;
            }
            k = 1;
        }
        return count;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
