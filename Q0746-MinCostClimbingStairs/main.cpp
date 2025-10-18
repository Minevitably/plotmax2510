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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> step(n, 0);
        step[0] = cost[0];
        step[1] = cost[1];

        for (int i = 2; i < n; ++i) {
            step[i] = std::min(step[i - 1], step[i - 2]) + cost[i];
        }
        return std::min(step[n - 1], step[n - 2]);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
