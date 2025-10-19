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
    int maxValInBST(TreeNode *root) {
        if (root == nullptr) {
            return INT_MIN;
        }
        return std::max(root->val, maxValInBST(root->right));
    }

    int minValInBST(TreeNode *root) {
        if (root == nullptr) {
            return INT_MAX;
        }
        return std::min(root->val, minValInBST(root->left));
    }

public:
    int minDiffInBST(TreeNode *root) {
        if (root == nullptr) {
            return INT_MAX;
        }
        int ld = INT_MAX;
        int rd = INT_MAX;
        if (root->left != nullptr) {
            ld = abs(root->val - maxValInBST(root->left));
            ld = std::min(ld, minDiffInBST(root->left));
        }
        if (root->right != nullptr) {
            rd = abs(root->val - minValInBST(root->right));
            rd = std::min(rd, minDiffInBST(root->right));
        }
        return std::min(ld, rd);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
