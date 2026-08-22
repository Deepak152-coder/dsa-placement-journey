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
    int Solve(TreeNode *root, int &maxi)
    {

        if (root == NULL)
        {
            return 0;
        }

        int left = max(0, Solve(root->left, maxi));
        int right = max(0, Solve(root->right, maxi));

        maxi = max(maxi, root->val + left + right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode *root)
    {

        int maxi = INT_MIN;

        Solve(root, maxi);

        return maxi;
    }
};

int main()
{

    // Example tree:
    //
    //        -10
    //        /  \
    //       9   20
    //          /  \
    //         15   7

    TreeNode *root = new TreeNode(-10);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << obj.maxPathSum(root) << endl;

    return 0;
}