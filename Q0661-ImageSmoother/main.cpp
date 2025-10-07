#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;


class Solution {
private:
    int smooth(vector<vector<int>>& img, int i, int j) {
        int m = img.size();
        int n = img[0].size();
        int sum = 0;
        int count = 0;
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                int row = i + k - 1;
                int col = j + l - 1;
                if ((row >= 0 && row < m) && (col >= 0 && col < n)) {
                    sum += img[row][col];
                    count++;
                }
            }
        }
        return sum / count;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = smooth(img, i, j);
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
