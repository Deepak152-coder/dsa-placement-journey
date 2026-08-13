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
    void helper(TreeNode *&root, TreeNode *&a, TreeNode *&b, TreeNode *&prev)
    {
        if (root == NULL)
        {
            return;
        }

        helper(root->left, a, b, prev);

        if (prev && prev->val > root->val)
        {
            if (a == NULL)
                a = prev;

            b = root;
        }

        prev = root;

        helper(root->right, a, b, prev);
    }

    void recoverTree(TreeNode *root)
    {
        TreeNode *a = NULL;
        TreeNode *b = NULL;
        TreeNode *prev = NULL;

        helper(root, a, b, prev);

        swap(a->val, b->val);
    }
};