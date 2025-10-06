#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;


class Solution {
private:
    pair<int, int> move(char ch) {
        switch (ch) {
            case 'U':
                return {0, 1};
            case 'D':
                return {0, -1};
            case 'L':
                return {-1, 0};
            case 'R':
                return {1, 0};
            default:
                break;
        }
        return {0, 0};
    }

public:
    bool judgeCircle(string moves) {
        pair<int, int> pos = {0, 0};
        for (char ch: moves) {
            pair<int, int> m = move(ch);
            pos.first += m.first;
            pos.second += m.second;
        }
        return pos.first == 0 && pos.second == 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
