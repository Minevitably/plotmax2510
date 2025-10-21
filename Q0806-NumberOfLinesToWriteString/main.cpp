#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int currWidth = 0;
        int lines = 1;
        for (int i = 0; i < s.size(); ++i) {
            currWidth += widths[s[i] - 'a'];
            if (currWidth > 100) {
                ++lines;
                currWidth = widths[s[i] - 'a'];
            }
        }
        return {lines, currWidth};
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
