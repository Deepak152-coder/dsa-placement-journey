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
    void helper(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
        {
            return;
        }

        helper(root->left, arr);
        arr.push_back(root->val);
        helper(root->right, arr);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> arr;

        helper(root, arr);

        return arr[k - 1];
    }
};