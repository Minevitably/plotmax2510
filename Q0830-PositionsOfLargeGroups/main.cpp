#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>

using std::vector;
using std::string;
using std::min;
using std::stringstream;
using std::getline;
using std::unordered_set;
using std::unordered_map;


class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int start = 0;
        int end = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) {
                if (end - start + 1 >= 3) {
                    ans.emplace_back(vector{start, end});
                }
                break;
            }

            if (s[i] == s[i + 1]) {
                end = i + 1;
            } else {
                if (end - start + 1 >= 3) {
                    ans.emplace_back(vector{start, end});
                }
                start = i + 1;
                end = i + 1;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
