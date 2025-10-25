#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>

using std::pair;
using std::vector;
using std::string;
using std::max;
using std::min;
using std::stringstream;
using std::getline;
using std::unordered_set;
using std::unordered_map;


class Solution {
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
        if (rec1 == rec2) {
            return true;
        }
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];

        int X1 = rec2[0];
        int Y1 = rec2[1];
        int X2 = rec2[2];
        int Y2 = rec2[3];

        bool overlapX = max(x1, X1) < min(x2, X2);
        bool overlapY = max(y1, Y1) < min(y2, Y2);
        return overlapX && overlapY;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
