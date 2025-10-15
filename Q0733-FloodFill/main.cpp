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
    vector<vector<int>>
    floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        int m = image.size();
        int n = m > 0 ? image[0].size() : 0;
        if ((sr < 0 || sr >= m) || (sc < 0 || sc >= n) || image[sr][sc] == color) {
            // out of bound
            return image;
        }
        int originColor = image[sr][sc];
        image[sr][sc] = color;
        if (sr - 1 >= 0 && image[sr - 1][sc] == originColor) {
            floodFill(image, sr - 1, sc, color);
        }
        if (sr + 1 < m && image[sr + 1][sc] == originColor) {
            floodFill(image, sr + 1, sc, color);
        }
        if (sc - 1 >= 0 && image[sr][sc - 1] == originColor) {
            floodFill(image, sr, sc - 1, color);
        }
        if (sc + 1 < n && image[sr][sc + 1] == originColor) {
            floodFill(image, sr, sc + 1, color);
        }
        return image;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
