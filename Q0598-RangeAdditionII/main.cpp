#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        if (ops.empty()) {
            return m * n;
        }
        vector<int> minOp = {INT_MAX, INT_MAX};
        for (vector<int> &op: ops) {
            for (int i = 0; i < op.size(); i++) {
                minOp[i] = std::min(minOp[i], op[i]);
            }
        }
        return minOp[0] * minOp[1];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
