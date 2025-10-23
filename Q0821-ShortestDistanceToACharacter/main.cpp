#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>

using std::vector;
using std::string;
using std::min;


class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        int left = -n;
        int right = s.find(c);
        vector<int> answer(n);

        for (int i = 0; i < n; ++i) {
            if (i > right) {
                left = right;
                right = s.find(c, i);
                if (right == string::npos) {
                    right = 2 * n;
                }
            }
            answer[i] = min(i - left, right - i);
        }
        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
