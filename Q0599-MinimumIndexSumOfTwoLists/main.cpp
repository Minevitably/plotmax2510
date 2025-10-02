#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int min = INT_MAX;
        for (int i = 0; i < list1.size(); i++) {
            for (int j = 0; j < list2.size(); j++) {
                if (list1[i] != list2[j]) {
                    continue;
                }
                if (i + j == min) {
                    ans.emplace_back(list1[i]);
                    break;
                } else if (i + j < min) {
                    min = i + j;
                    ans.clear();
                    ans.emplace_back(list1[i]);
                    break;
                }

            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
