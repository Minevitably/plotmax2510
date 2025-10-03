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

        if (root1 == nullptr) {
            root->val = root2->val;
            root->left = mergeTrees(nullptr, root2->left);
            root->right = mergeTrees(nullptr, root2->right);
            return root;
        }
        if (root2 == nullptr) {
            root->val = root1->val;
            root->left = mergeTrees(root1->left, nullptr);
            root->right = mergeTrees(root1->right, nullptr);
            return root;
        }
        root->val = root1->val + root2->val;

        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
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
