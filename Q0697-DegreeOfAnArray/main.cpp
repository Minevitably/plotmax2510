#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

struct Info {
    int count;
    int minIndex;
    int maxIndex;

    Info() : count(0), minIndex(-1), maxIndex(-1) {}

    Info(int count, int minIndex, int maxIndex) : count(count),
                                                  minIndex(minIndex),
                                                  maxIndex(maxIndex) {}
};

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        int maxCount = 0;
        int minLength = nums.size();
        map<int, Info> infoMap;
        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i];
            if (infoMap.count(key) == 0) {
                infoMap[key] = Info(1, i, i);
            } else {
                infoMap[key].maxIndex = i;
                infoMap[key].count++;
            }
            maxCount = std::max(maxCount, infoMap[key].count);
        }

        for (pair<int, Info> item: infoMap) {
            Info &info = item.second;
            if (info.count == maxCount) {
                int len = info.maxIndex - info.minIndex + 1;
                minLength = std::min(minLength, len);
            }
        }
        return minLength;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
