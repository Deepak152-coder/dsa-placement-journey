#include <iostream>
#include <algorithm>
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
    int helper(TreeNode* root, int& maxDia) {
        if (root == NULL) {
            return 0;
        }

        int left = helper(root->left, maxDia);
        int right = helper(root->right, maxDia);

        maxDia = max(maxDia, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root, maxDia);
        return maxDia;
    }
};

int main() {

    // Creating the tree
    //
    //          1
    //         / \
    //        2   3
    //       / \
    //      4   5

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    int diameter = obj.diameterOfBinaryTree(root);

    cout << "Diameter of Binary Tree = " << diameter << endl;

    return 0;
}