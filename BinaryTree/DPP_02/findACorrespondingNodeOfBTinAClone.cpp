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
    void solve(TreeNode *root, TreeNode *k, TreeNode *&ans)
    {

        if (root == NULL)
        {
            return;
        }

        if (root->val == k->val)
        {
            ans = root;
            return;
        }

        solve(root->left, k, ans);
        solve(root->right, k, ans);
    }

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                            TreeNode *target)
    {

        TreeNode *ans = NULL;

        solve(cloned, target, ans);

        return ans;
    }
};

int main()
{

    /*
              Original Tree

                   7
                  / \
                 4   3
                / \   \
               6   5   2

              Target = 5

              Cloned tree is an identical copy.
    */

    // Original tree
    TreeNode *original = new TreeNode(7);

    original->left = new TreeNode(4);
    original->right = new TreeNode(3);

    original->left->left = new TreeNode(6);
    original->left->right = new TreeNode(5);

    original->right->right = new TreeNode(2);

    // Cloned tree
    TreeNode *cloned = new TreeNode(7);

    cloned->left = new TreeNode(4);
    cloned->right = new TreeNode(3);

    cloned->left->left = new TreeNode(6);
    cloned->left->right = new TreeNode(5);

    cloned->right->right = new TreeNode(2);

    // Target node from original tree
    TreeNode *target = original->left->right;

    Solution obj;

    TreeNode *result = obj.getTargetCopy(original, cloned, target);

    if (result != NULL)
    {
        cout << "Target found in cloned tree: "
             << result->val << endl;
    }
    else
    {
        cout << "Target not found" << endl;
    }

    return 0;
}