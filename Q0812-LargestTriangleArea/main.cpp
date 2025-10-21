#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = -DBL_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n && j != i; ++j) {
                for (int k = 0; k < n && k != i && k != j; ++k) {
                    int x1 = points[i][0];
                    int y1 = points[i][1];

                    int x2 = points[j][0];
                    int y2 = points[j][1];

                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    double sum1 = (x1 * y2) + (x2 * y3) + (x3 * y1);
                    double sum2 = (y1 * x2) + (y2 * x3) + (y3 * x1);
                    double area = abs(sum1 - sum2) / 2;
                    maxArea = std::max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
