#include <iostream>
using namespace std;

// Definition of TreeNode
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
    bool checkTree(TreeNode *root)
    {
        if (root->val == (root->left->val + root->right->val))
        {
            return true;
        }

        return false;
    }
};

int main()
{

    // Creating the tree
    //
    //        10
    //       /  \
    //      4    6
    //
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);

    Solution obj;

    bool ans = obj.checkTree(root);

    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}