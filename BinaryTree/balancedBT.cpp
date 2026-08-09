#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int level(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = level(root->left);
        int right = level(root->right);

        return 1 + max(left, right);
    }

    bool helper(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int k = abs(level(root->left) - level(root->right));

        if (k > 1) {
            return false;
        }

        return helper(root->left) && helper(root->right);
    }

    bool isBalanced(TreeNode* root) {
        return helper(root);
    }
};

int main() {
    // Creating tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    if (obj.isBalanced(root)) {
        cout << "Tree is Balanced" << endl;
    } else {
        cout << "Tree is Not Balanced" << endl;
    }

    return 0;
}