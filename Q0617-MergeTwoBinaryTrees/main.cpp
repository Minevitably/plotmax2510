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
        int lVal = 0;
        int rVal = 0;
        TreeNode * l1 = nullptr;
        TreeNode * r1 = nullptr;
        TreeNode * l2 = nullptr;
        TreeNode * r2 = nullptr;
        if (root1 != nullptr) {
            lVal = root1->val;
            l1 = root1->left;
            r1 = root1->right;
        }
        if (root2 != nullptr) {
            rVal = root2->val;
            l2 = root2->left;
            r2 = root2->right;
        }
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
