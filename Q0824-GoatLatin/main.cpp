#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_set>

using std::vector;
using std::string;
using std::min;
using std::stringstream;
using std::getline;
using std::unordered_set;
using std::unordered_map;


class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        stringstream ss(sentence);
        string token;
        string ans;
        int i = 1;
        while (getline(ss, token, ' ')) {
            if (!token.empty()) {
                if (vowels.count(tolower(token[0])) > 0) {
                    token += "ma";
                } else {
                    token = token.substr(1, token.size() - 1) + token[0];
                    token += "ma";
                }
                for (int j = 0; j < i; ++j) {
                    token += "a";
                }
                ans += token;
                ans += " ";
                ++i;
            }
        }
        if (!ans.empty()) {
            return ans.substr(0, ans.size() - 1);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
