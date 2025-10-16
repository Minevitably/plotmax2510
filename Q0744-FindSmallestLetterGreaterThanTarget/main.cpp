#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.empty()) {
            return '\0';
        }
        int n = letters.size();
        if (target >= letters[n - 1]) {
            return letters[0];
        }
        for (int i = 0; i < n; ++i) {
            if (letters[i] > target) {
                return letters[i];
            }
        }
        // exception
        return '\0';
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
