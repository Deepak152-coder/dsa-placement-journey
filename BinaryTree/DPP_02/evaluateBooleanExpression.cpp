#include <iostream>
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
    void solve(TreeNode *root)
    {

        if (root == NULL)
        {
            return;
        }

        solve(root->left);
        solve(root->right);

        // Leaf node: 0 = False, 1 = True
        if (!root->left && !root->right)
        {
            return;
        }

        // 3 = AND
        if (root->val == 3)
        {

            if (root->left->val == 1 && root->right->val == 1)
            {
                root->val = 1;
            }
            else
            {
                root->val = 0;
            }
        }

        // 2 = OR
        else
        {

            if (root->left->val == 1 || root->right->val == 1)
            {
                root->val = 1;
            }
            else
            {
                root->val = 0;
            }
        }
    }

    bool evaluateTree(TreeNode *root)
    {

        solve(root);

        return root->val;
    }
};

int main()
{

    /*
            3 (AND)
           /      \
        2 (OR)     1 (True)
        /    \
    0(False) 1(True)

    OR:
    False OR True = True

    AND:
    True AND True = True

    Answer = True
    */

    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(2);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    Solution obj;

    bool ans = obj.evaluateTree(root);

    if (ans)
    {
        cout << "Result: True" << endl;
    }
    else
    {
        cout << "Result: False" << endl;
    }

    return 0;
}