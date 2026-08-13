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
    TreeNode *helper(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->val == key)
        {
            if (!root->left)
                return root->right;

            if (!root->right)
                return root->left;

            TreeNode *temp = root->left;

            while (temp->right)
            {
                temp = temp->right;
            }

            root->val = temp->val;
            root->left = helper(root->left, temp->val);

            return root;
        }

        root->left = helper(root->left, key);
        root->right = helper(root->right, key);

        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        return helper(root, key);
    }
};