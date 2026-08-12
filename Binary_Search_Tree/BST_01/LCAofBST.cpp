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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root == p || root == q)
        {
            return root;
        }

        if ((root->val > p->val && root->val < q->val) ||
            (root->val < p->val && root->val > q->val))
        {
            return root;
        }
        else if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};