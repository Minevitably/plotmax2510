#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};


class Solution {
private:
    void inOrder(TreeNode *root, vector<TreeNode *> &arr) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, arr);
        arr.emplace_back(root);
        inOrder(root->right, arr);
    }

public:
    TreeNode *increasingBST(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        vector<TreeNode *> arr;
        inOrder(root, arr);
        TreeNode *newRoot = new TreeNode(arr[0]->val);
        TreeNode *tail = newRoot;
        for (int i = 1; i < arr.size(); ++i) {
            tail->right = new TreeNode(arr[i]->val);
            tail = tail->right;
        }
        return newRoot;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
