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
    TreeNode *helper(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->val == val)
        {
            return root;
        }
        else if (root->val < val)
        {
            return helper(root->right, val);
        }
        else
        {
            return helper(root->left, val);
        }
    }

    TreeNode *searchBST(TreeNode *root, int val)
    {
        return helper(root, val);
    }
};