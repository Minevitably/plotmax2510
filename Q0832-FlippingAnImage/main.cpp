#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>

using std::vector;
using std::string;
using std::min;
using std::stringstream;
using std::getline;
using std::unordered_set;
using std::unordered_map;


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
        int row = image.size();
        int col = row > 0 ? image[0].size() : 0;
        for (int i = 0; i < row; ++i) {
            int left = 0;
            int right = col - 1;
            while (left < right) {
                int temp = image[i][left];
                image[i][left] = image[i][right];
                image[i][right] = temp;
                ++left;
                --right;
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                image[i][j] = !image[i][j];
            }
        }
        return image;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
