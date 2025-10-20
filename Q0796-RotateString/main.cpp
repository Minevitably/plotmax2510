#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    bool equalsAfterRotate(const string &s, int k, const string &goal) {
        int n = goal.size();
        for (int i = 0; i < n; ++i) {
            if (s[(i + k) % n] != goal[i]) {
                return false;
            }
        }
        return true;
    }

public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        for (int i = 0; i < goal.size(); ++i) {
            if (equalsAfterRotate(s, i, goal)) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
