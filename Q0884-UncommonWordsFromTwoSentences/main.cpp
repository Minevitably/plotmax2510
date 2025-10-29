#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>


using std::pair;
using std::vector;
using std::string;
using std::stringstream;
using std::unordered_set;
using std::unordered_map;
using std::stack;

using std::max;
using std::min;
using std::getline;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss(s1);
        vector<string> v1;
        vector<string> v2;
        vector<string> ans;
        string token;
        while (ss >> token) {
            v1.emplace_back(token);
        }
        ss.str(s2);
        ss.clear();
        while (ss >> token) {
            v2.emplace_back(token);
        }
        for (const string &s: v1) {
            if (std::count(v1.begin(), v1.end(), s) == 1 &&
                std::count(v2.begin(), v2.end(), s) == 0) {
                ans.emplace_back(s);
            }
        }
        for (const string &s: v2) {
            if (std::count(v2.begin(), v2.end(), s) == 1 &&
                std::count(v1.begin(), v1.end(), s) == 0) {
                ans.emplace_back(s);
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
