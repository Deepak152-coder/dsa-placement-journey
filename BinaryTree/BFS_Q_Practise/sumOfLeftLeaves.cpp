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
    void helper(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return;
        }

        // Check if left child is a leaf
        if (root->left && !root->left->left && !root->left->right)
        {
            ans += root->left->val;
        }

        if (root->left)
        {
            helper(root->left, ans);
        }

        if (root->right)
        {
            helper(root->right, ans);
        }
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        int ans = 0;

        helper(root, ans);

        return ans;
    }
};

int main()
{
    /*
              3
             / \
            9   20
               /  \
              15   7

        Left Leaves = 9 + 15 = 24
    */

    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Sum of Left Leaves: "
         << obj.sumOfLeftLeaves(root) << endl;

    return 0;
}