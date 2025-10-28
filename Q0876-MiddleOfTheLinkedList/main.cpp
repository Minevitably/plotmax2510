#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>


using std::pair;
using std::vector;
using std::string;
using std::stringstream;
using std::unordered_set;
using std::unordered_map;
using std::stack;

using std::max;
using std::min;
using std::getline;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        int len = 0;
        ListNode *dummy = new ListNode(0, head);
        while (dummy->next != nullptr) {
            ++len;
            dummy->next = dummy->next->next;
        }
        int mid = len / 2;
        dummy->next = head;
        for (int i = 0; i < mid; ++i) {
            dummy->next = dummy->next->next;
        }
        return dummy->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
