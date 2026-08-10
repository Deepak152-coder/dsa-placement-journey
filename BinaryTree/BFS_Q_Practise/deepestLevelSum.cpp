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
    int level(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = level(root->left);
        int right = level(root->right);

        return 1 + max(left, right);
    }

    void helper(TreeNode *root, int curr, int dest, int &sum)
    {
        if (root == NULL)
        {
            return;
        }

        if (curr == dest)
        {
            sum += root->val;
        }

        helper(root->left, curr + 1, dest, sum);
        helper(root->right, curr + 1, dest, sum);
    }

    int deepestLeavesSum(TreeNode *root)
    {
        int sum = 0;

        int n = level(root);

        helper(root, 1, n, sum);

        return sum;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    root->left->left->left = new TreeNode(7);

    root->right->right->right = new TreeNode(8);

    Solution s;

    cout << s.deepestLeavesSum(root) << endl;

    return 0;
}