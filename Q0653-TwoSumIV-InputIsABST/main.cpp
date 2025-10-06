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
    void inOrder(TreeNode *root, vector<int> &arr) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, arr);
        arr.emplace_back(root->val);
        inOrder(root->right, arr);
    }

    int find(vector<int> &arr, int val) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > val) {
                right = mid - 1;
            } else if (arr[mid] < val) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

public:
    bool findTarget(TreeNode *root, int k) {
        if (root == nullptr) {
            return false;
        }
        vector<int> arr;
        inOrder(root, arr);
        for (int i = 0; i < arr.size(); i++) {
            int j = find(arr, k - arr[i]);
            if (j != -1 && j != i) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
