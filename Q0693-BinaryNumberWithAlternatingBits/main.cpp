#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    bool hasAlternatingBits(int n) {
        int ans = ((n >> 1) ^ n);
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (n >> i) {
                count++;
            }
        }
        for (int i = 0; i < count; i++) {
            if (!((ans >> i) & 1)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
