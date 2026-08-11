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

    int maxDepth(TreeNode *root)
    {
        return level(root);
    }
};

int main()
{
    /*
              1
             / \
            2   3
           / \
          4   5

        Maximum Depth = 3
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    cout << "Maximum Depth: " << obj.maxDepth(root) << endl;

    return 0;
}