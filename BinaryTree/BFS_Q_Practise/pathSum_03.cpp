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
    void helper(TreeNode *root, int target, long long sum, int &count)
    {
        if (root == NULL)
        {
            return;
        }

        sum += root->val;

        if (sum == target)
        {
            count++;
        }

        helper(root->left, target, sum, count);
        helper(root->right, target, sum, count);
    }

    void travel(TreeNode *root, int target, int &count)
    {
        if (root == NULL)
        {
            return;
        }

        helper(root, target, 0, count);

        travel(root->left, target, count);
        travel(root->right, target, count);
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        int count = 0;

        travel(root, targetSum, count);

        return count;
    }
};

int main()
{
    /*
             10
            /  \
           5   -3
          / \    \
         3   2    11
        / \   \
       3  -2   1
    */

    TreeNode *root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    root->right->right = new TreeNode(11);

    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);

    root->left->right->right = new TreeNode(1);

    Solution obj;

    int targetSum = 8;

    cout << "Number of paths: "
         << obj.pathSum(root, targetSum) << endl;

    return 0;
}