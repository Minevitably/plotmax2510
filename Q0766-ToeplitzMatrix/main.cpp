#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
private:
    bool isDiagonalSame(vector<vector<int>> &matrix, int m, int n, int i, int j) {
        int val = matrix[i][j];
        ++i;
        ++j;
        while (i < m && j < n) {
            if (matrix[i][j] != val) {
                return false;
            }
            ++i;
            ++j;
        }
        return true;
    }

public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        // column diagonal
        for (int i = 0; i < n; ++i) {
            if (!isDiagonalSame(matrix, m, n, 0, i)) {
                return false;
            }
        }
        // row diagonal
        for (int i = 1; i < m; ++i) {
            if (!isDiagonalSame(matrix, m, n, i, 0)) {
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
