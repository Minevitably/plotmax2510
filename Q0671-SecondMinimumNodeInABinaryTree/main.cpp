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
    bool hasChildren(TreeNode *root) {
        return root->left != nullptr || root->right != nullptr;
    }
public:
    int findSecondMinimumValue(TreeNode *root) {
        if (root == nullptr) {
            return -1;
        }
        int secMinVal = -1;
        if (hasChildren(root)) {
            bool isCandidate = root->val != max(root->left->val, root->right->val);
            if (isCandidate) {
                secMinVal = max(root->left->val, root->right->val);
            }
            int l = findSecondMinimumValue(root->left);
            if (l != -1) {
                if (isCandidate) {
                    secMinVal = min(secMinVal, l);
                } else {
                    secMinVal = l;
                }
            }
            int r = findSecondMinimumValue(root->right);
            if (r != -1) {
                if (isCandidate) {
                    secMinVal = min(secMinVal, r);
                } else {
                    secMinVal = r;
                }
            }

        }
        return secMinVal;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
