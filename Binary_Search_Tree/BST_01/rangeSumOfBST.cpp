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
    void helper(TreeNode *root, int low, int high, int &sum)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->val >= low && root->val <= high)
        {
            sum += root->val;
        }

        helper(root->left, low, high, sum);
        helper(root->right, low, high, sum);
    }

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum = 0;
        helper(root, low, high, sum);
        return sum;
    }
};