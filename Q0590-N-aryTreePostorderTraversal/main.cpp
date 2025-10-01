#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    void doPostOrder(Node *root, vector<int> &ans) {
        if (root == nullptr) {
            return;
        }
        for (Node *item: root->children) {
            doPostOrder(item, ans);
        }
        ans.emplace_back(root->val);
    }

public:
    vector<int> postorder(Node *root) {
        vector<int> ans;
        doPostOrder(root, ans);
        return ans;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
