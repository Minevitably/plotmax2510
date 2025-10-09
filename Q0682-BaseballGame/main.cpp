#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    int calPoints(vector<string> &operations) {
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                ans.emplace_back(ans[ans.size() - 1] + ans[ans.size() - 2]);
            } else if (operations[i] == "D") {
                ans.emplace_back(ans[ans.size() - 1] * 2);
            } else if (operations[i] == "C") {
                ans.pop_back();
            } else {
                ans.emplace_back(std::stoi(operations[i]));
            }
        }
        for (int num: ans) {
            sum += num;
        }
        return sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
