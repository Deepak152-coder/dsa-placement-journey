#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *temp = new TreeNode(val);

        if (root == NULL)
        {
            root = temp;
            return root;
        }

        if (root->val > val && !root->left)
        {
            root->left = temp;
        }

        if (root->val < val && !root->right)
        {
            root->right = temp;
        }

        if (root->val > val)
        {
            insertIntoBST(root->left, val);
        }
        else if (root->val < val)
        {
            insertIntoBST(root->right, val);
        }

        return root;
    }
};