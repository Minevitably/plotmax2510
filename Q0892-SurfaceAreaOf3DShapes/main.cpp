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
private:
    int calcAdjacentArea(vector<vector<int>> &grid, int i, int j) {
        if (grid[i][j] <= 0) {
            return 0;
        }
        int n = grid.size();
        int area = 2;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int k = 0; k < 4; ++k) {
            int i1 = i + dir[k][0];
            int j1 = j + dir[k][1];
            if (i1 < 0 || i1 >= n || j1 < 0 || j1 >= n) {
                // out of bound
                area += grid[i][j];
            } else {
                area += max(grid[i][j] - grid[i1][j1], 0);
            }
        }
        return area;
    }
public:
    int surfaceArea(vector<vector<int>> &grid) {
        int area = 0;
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                area += calcAdjacentArea(grid, i, j);
            }
        }
        return area;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
