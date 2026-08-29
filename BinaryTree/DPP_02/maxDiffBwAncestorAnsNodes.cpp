#include <iostream>
#include <algorithm>
#include <cmath>
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
    void solve(TreeNode *root, int &ans, int mn, int mx)
    {
        if (root == NULL)
        {
            return;
        }

        ans = max(ans, max(abs(root->val - mn),
                           abs(root->val - mx)));

        mn = min(mn, root->val);
        mx = max(mx, root->val);

        solve(root->left, ans, mn, mx);
        solve(root->right, ans, mn, mx);
    }

    int maxAncestorDiff(TreeNode *root)
    {
        int ans = 0;

        solve(root, ans, root->val, root->val);

        return ans;
    }
};

int main()
{

    /*
            8
           / \
          3   10
         / \
        1   6
    */

    TreeNode *root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    Solution obj;

    cout << "Maximum Ancestor Difference: "
         << obj.maxAncestorDiff(root) << endl;

    return 0;
}