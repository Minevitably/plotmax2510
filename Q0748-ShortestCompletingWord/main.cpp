#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
private:
    bool isCompletingWord(const string &word,
                          const unordered_map<char, int> &licensePlateMap) {
        unordered_map<char, int> wordMap;
        for (char letter: word) {
            wordMap[letter]++;
        }
        for (const auto &[key, value]: licensePlateMap) {
            if (wordMap[key] < value) {
                return false;
            }
        }
        return true;
    }

public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        unordered_map<char, int> licensePlateMap;
        for (char ch: licensePlate) {
            if (isalpha(ch)) {
                licensePlateMap[tolower(ch)]++;
            }
        }
        int minLength = INT_MAX;
        int minIndex = -1;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i].size() < minLength &&
                isCompletingWord(words[i], licensePlateMap)) {
                minLength = words[i].size();
                minIndex = i;
            }
        }
        if (minIndex == -1) {
            return "";
        }
        return words[minIndex];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
