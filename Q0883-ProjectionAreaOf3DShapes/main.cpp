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
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m > 0 ? grid[0].size() : 0;
        int area = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    ++area;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            int rowMax = 0;
            for (int j = 0; j < n; ++j) {
                rowMax = max(rowMax, grid[i][j]);
            }
            area += rowMax;
        }
        for (int j = 0; j < n; ++j) {
            int colMax = 0;
            for (int i = 0; i < m; ++i) {
                colMax = max(colMax, grid[i][j]);
            }
            area += colMax;
        }
        return area;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
