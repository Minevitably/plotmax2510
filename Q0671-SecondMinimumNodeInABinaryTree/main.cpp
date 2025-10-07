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
    int getMin(int a, int b) {
        if (a == -1 || b == -1) {
            return max(a, b);
        }
        return min(a, b);
    }
public:
    int findSecondMinimumValue(TreeNode *root) {
        if (root == nullptr || !hasChildren(root)) {
            return -1;
        }
        int ans = -1;
        if (root->left->val != root->right->val) {
            ans = max(root->left->val, root->right->val);
        }
        int l = findSecondMinimumValue(root->left);
        ans = getMin(ans, l);
        int r = findSecondMinimumValue(root->right);
        ans = getMin(ans, r);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
