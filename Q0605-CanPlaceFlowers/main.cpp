#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    bool plant(vector<int>& flowerbed, int i) {
        if (flowerbed[i] == 1) {
            return false;
        }
        bool l = (i - 1 < 0 || flowerbed[i - 1] == 0);
        bool r = (flowerbed.size() <= i + 1 || flowerbed[i + 1] == 0);
        return l && r;
    }
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size() && n > 0; i++) {
            if(plant(flowerbed, i)) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n == 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
