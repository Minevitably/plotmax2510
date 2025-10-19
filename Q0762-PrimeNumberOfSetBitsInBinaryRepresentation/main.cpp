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
    static const int n = 32;
    bool isPrime[n + 1];
private:
    int countBits(int num) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            count += (num >> i) & 1;
        }
        return count;
    }
public:
    Solution() {
        int stop = n / 2;
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i < n + 1; ++i) {
            isPrime[i] = true;
        }
        for (int a = 2; a <=  stop; ++a) {
            for (int b = 2; b <= stop; ++b) {
                if (a * b > n) {
                    break;
                }
                isPrime[a * b] = false;
            }
        }
    }

    int countPrimeSetBits(int left, int right) {
        int count = 0;
        while (left <= right) {
            if (isPrime[countBits(left)]) {
                ++count;
            }
            ++left;
        }
        return count;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
