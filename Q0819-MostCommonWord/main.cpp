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
    string mostCommonWord(string paragraph, vector<string> &banned) {
        std::transform(paragraph.begin(), paragraph.end(), paragraph.begin(),
                       [](char ch) { return ispunct(ch) ? ' ' : tolower(ch); });
        stringstream ss(paragraph);
        string token;
        map<string, int> wordCountMap;
        while (getline(ss, token, ' ')) {
            bool notBanned = std::find(banned.begin(), banned.end(), token) == banned.end();
            if (!token.empty() && notBanned) {
                wordCountMap[token]++;
            }
        }
        const string *ans;
        int maxCount = 0;
        for (const auto &[word, count]: wordCountMap) {
            if (count > maxCount) {
                maxCount = count;
                ans = &word;
            }
        }
        return *ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
