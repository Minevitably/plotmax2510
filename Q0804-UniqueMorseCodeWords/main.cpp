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
    int uniqueMorseRepresentations(vector<string> &words) {
        vector<string> moss = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                               "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                               "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                               "-.--", "--.."};
        unordered_set<string> ans;
        for (const auto &word: words) {
            string wordMoss;
            for (const char &ch: word) {
                int k = ch - 'a';
                wordMoss += moss[k];
            }
            ans.insert(wordMoss);
        }
        return ans.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
