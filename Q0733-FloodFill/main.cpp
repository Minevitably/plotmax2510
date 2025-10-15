#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Solution {
private:
    void
    floodFillDfs(vector<vector<int>> &image, int sr, int sc, int color,
                 int originColor) {
        int m = image.size();
        int n = m > 0 ? image[0].size() : 0;
        if ((sr < 0 || sr >= m) || (sc < 0 || sc >= n) ||
            image[sr][sc] == color || image[sr][sc] != originColor) {
            // out of bound
            return;
        }
        image[sr][sc] = color;
        floodFillDfs(image, sr - 1, sc, color, originColor);
        floodFillDfs(image, sr + 1, sc, color, originColor);
        floodFillDfs(image, sr, sc - 1, color, originColor);
        floodFillDfs(image, sr, sc + 1, color, originColor);
    }

public:
    vector<vector<int>>
    floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        floodFillDfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
