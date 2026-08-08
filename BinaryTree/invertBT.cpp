#include <iostream>
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
    void helper(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        helper(root->left);
        helper(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};

void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Creating tree
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution obj;

    cout << "Before Invert: ";
    inorder(root);

    obj.invertTree(root);

    cout << "\nAfter Invert: ";
    inorder(root);

    return 0;
}