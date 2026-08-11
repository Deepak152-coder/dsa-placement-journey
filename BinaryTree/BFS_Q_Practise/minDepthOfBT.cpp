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

        // If left subtree doesn't exist
        if (!root->left)
        {
            return 1 + right;
        }

        // If right subtree doesn't exist
        if (!root->right)
        {
            return 1 + left;
        }

        // Both subtrees exist
        return 1 + min(left, right);
    }

    int minDepth(TreeNode *root)
    {
        int n = level(root);
        return n;
    }
};

int main()
{
    /*
              1
             / \
            2   3
           /     \
          4       5

        Minimum Depth = 3
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution obj;

    cout << "Minimum Depth: " << obj.minDepth(root) << endl;

    return 0;
}