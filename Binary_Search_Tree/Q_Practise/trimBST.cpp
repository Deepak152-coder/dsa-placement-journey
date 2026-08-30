#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    TreeNode *makeBST(TreeNode *root, int lo, int hi)
    {

        if (root == NULL)
        {
            return NULL;
        }

        if (root->val < lo)
        {
            return makeBST(root->right, lo, hi);
        }

        if (root->val > hi)
        {
            return makeBST(root->left, lo, hi);
        }

        root->left = makeBST(root->left, lo, hi);
        root->right = makeBST(root->right, lo, hi);

        return root;
    }

    TreeNode *trimBST(TreeNode *root, int lo, int hi)
    {
        return makeBST(root, lo, hi);
    }
};

int main()
{

    // Example BST:
    //          4
    //        /   \
    //       2     7
    //      / \   / \
    //     1   3 6   9

    TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    int lo = 3;
    int hi = 7;

    Solution obj;

    root = obj.trimBST(root, lo, hi);

    // Inorder traversal to print the trimmed BST
    function<void(TreeNode *)> inorder = [&](TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    };

    inorder(root);

    return 0;
}