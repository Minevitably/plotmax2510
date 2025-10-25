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
    bool backspaceCompare(string s, string t) {
        stack<char> stackS;
        stack<char> stackT;
        for (char ch: s) {
            if (ch == '#') {
                if (!stackS.empty()) {
                    stackS.pop();
                }
            } else {
                stackS.push(ch);
            }
        }
        for (char ch: t) {
            if (ch == '#') {
                if (!stackT.empty()) {
                    stackT.pop();
                }
            } else {
                stackT.push(ch);
            }
        }
        return stackS == stackT;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
