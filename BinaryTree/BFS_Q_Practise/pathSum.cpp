#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
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
    bool helper(TreeNode *root, int target, int sum)
    {
        bool flag = false;

        if (root == NULL)
        {
            return flag;
        }

        sum += root->val;

        // Check only at leaf node
        if (sum == target && !root->left && !root->right)
        {
            flag = true;
            return flag;
        }

        bool l = helper(root->left, target, sum);
        bool r = helper(root->right, target, sum);

        return l || r;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return helper(root, targetSum, 0);
    }
};

int main()
{
    /*
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

        Target = 22

        Path: 5 -> 4 -> 11 -> 2
        Sum = 22
    */

    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution obj;

    int targetSum = 22;

    if (obj.hasPathSum(root, targetSum))
    {
        cout << "Path exists" << endl;
    }
    else
    {
        cout << "Path does not exist" << endl;
    }

    return 0;
}