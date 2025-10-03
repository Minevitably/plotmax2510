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
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }

        TreeNode *root = new TreeNode();
        int lVal = (root1 == nullptr ? 0 : root1->val);
        int rVal = (root2 == nullptr ? 0 : root2->val);
        TreeNode * l1 = (root1 == nullptr ? nullptr : root1->left);
        TreeNode * r1 = (root1 == nullptr ? nullptr : root1->right);
        TreeNode * l2 = (root2 == nullptr ? nullptr : root2->left);
        TreeNode * r2 = (root2 == nullptr ? nullptr : root2->right);

        root->val = lVal + rVal;
        root->left = mergeTrees(l1, l2);
        root->right = mergeTrees(r1, r2);
        return root;
    }

public:
    void destructTree(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        destructTree(root->left);
        destructTree(root->right);
        delete root;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
