#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>


using std::pair;
using std::vector;
using std::string;
using std::max;
using std::min;
using std::stringstream;
using std::getline;
using std::unordered_set;
using std::unordered_map;
using std::stack;


class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        if (n < 2 || n != goal.size()) {
            return false;
        }
        int count = 0;
        vector<int> indices;
        for (int i = 0; i < n; ++i) {
            if (s[i] != goal[i]) {
                ++count;
                indices.emplace_back(i);
                if (count == 2) {
                    int j = indices[0];
                    int k = indices[1];
                    bool swapTest = s[j] == goal[k] && s[k] == goal[j];
                    if (!swapTest) {
                        return false;
                    }
                }
                if (count > 2) {
                    return false;
                }
            }

        }
        if (count == 2) {
            return true;
        }
        if (count == 1) {
            return false;
        }
        unordered_set<char> charSet;
        for (char ch: s) {
            if (charSet.count(ch) > 0) {
                return true;
            } else {
                charSet.insert(ch);
            }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
