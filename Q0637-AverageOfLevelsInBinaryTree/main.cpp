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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
    void preOrder(TreeNode* root, int level,
                  vector<double> &ans, vector<int> &count) {
        if (root == nullptr) {
            return;
        }
        ans[level] += root->val;
        count[level]++;
        preOrder(root->left, level + 1, ans, count);
        preOrder(root->right, level + 1, ans, count);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        int h = height(root);
        vector<double> ans(h, 0.0f);
        vector<int> count(h, 0);
        preOrder(root, 0, ans, count);
        for (int i = 0; i < h; i++) {
            ans[i] /= count[i];
        }
        return ans;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
