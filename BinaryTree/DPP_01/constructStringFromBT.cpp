#include <iostream>
#include <string>
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
    void makeStr(TreeNode *root, string &s)
    {
        if (root == NULL)
        {
            return;
        }

        s += to_string(root->val);

        if (root->left || root->right)
        {
            s += "(";
            makeStr(root->left, s);
            s += ")";

            if (root->right)
            {
                s += "(";
                makeStr(root->right, s);
                s += ")";
            }
        }
    }

    string tree2str(TreeNode *root)
    {
        string s = "";

        makeStr(root, s);

        return s;
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
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    cout << obj.tree2str(root) << endl;

    return 0;
}