#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
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
    int solve(TreeNode *root, TreeNode *parent, TreeNode *grandParent)
    {
        if (root == NULL)
        {
            return 0;
        }

        int sum = 0;

        if (grandParent != NULL && grandParent->val % 2 == 0)
        {
            sum += root->val;
        }

        sum += solve(root->left, root, parent);
        sum += solve(root->right, root, parent);

        return sum;
    }

    int sumEvenGrandparent(TreeNode *root)
    {
        return solve(root, NULL, NULL);
    }
};

int main()
{

    /*
             6
            / \
           7   8
          / \ / \
         2  7 1  3
    */

    TreeNode *root = new TreeNode(6);

    root->left = new TreeNode(7);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(3);

    Solution obj;

    cout << "Sum = " << obj.sumEvenGrandparent(root) << endl;

    return 0;
}