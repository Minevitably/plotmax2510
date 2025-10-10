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
            if (infoMap.count(nums[i]) == 0) {
                Info info(1, i, i);
                infoMap[nums[i]] = info;
            } else {
                infoMap[nums[i]].maxIndex = i;
                infoMap[nums[i]].count++;
            }
            maxCount = std::max(maxCount, infoMap[nums[i]].count);
        }

        for (auto element: infoMap) {
            Info &info = element.second;
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
