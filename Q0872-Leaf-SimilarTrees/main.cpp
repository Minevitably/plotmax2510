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
    void inOrderTraversal(TreeNode *root, vector<int> &arr) {
        if (root == nullptr) {
            return;
        }
        inOrderTraversal(root->left, arr);
        if (root->left == nullptr && root->right == nullptr) {
            arr.emplace_back(root->val);
        }
        inOrderTraversal(root->right, arr);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> arr1;
        vector<int> arr2;
        inOrderTraversal(root1, arr1);
        inOrderTraversal(root2, arr2);
        return arr1 == arr2;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
