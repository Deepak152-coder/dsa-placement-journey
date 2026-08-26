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
    bool isUnivalTree(TreeNode *root)
    {

        bool flag = true;

        if (root == NULL)
        {
            return flag;
        }

        if (root->left && root->val != root->left->val)
        {
            flag = false;
            return flag;
        }

        if (root->right && root->val != root->right->val)
        {
            flag = false;
            return flag;
        }

        bool l = isUnivalTree(root->left);
        bool r = isUnivalTree(root->right);

        return l && r;
    }
};

int main()
{

    /*
            1
           / \
          1   1
         / \
        1   1
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(1);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);

    Solution obj;

    if (obj.isUnivalTree(root))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}