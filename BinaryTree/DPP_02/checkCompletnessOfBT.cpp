#include <iostream>
#include <queue>
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
    void solve(TreeNode *root, bool &flag)
    {

        if (root == NULL)
        {
            return;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {

            TreeNode *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                flag = true;
            }
            else
            {

                q.push(temp->left);
                q.push(temp->right);

                if (flag)
                {
                    flag = false;
                    return;
                }
            }
        }

        flag = true;
    }

    bool isCompleteTree(TreeNode *root)
    {

        bool flag = false;

        solve(root, flag);

        return flag;
    }
};

int main()
{

    /*
            1
           / \
          2   3
         / \  /
        4   5 6

        This is a Complete Binary Tree.
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);

    Solution obj;

    if (obj.isCompleteTree(root))
    {
        cout << "Tree is Complete" << endl;
    }
    else
    {
        cout << "Tree is NOT Complete" << endl;
    }

    return 0;
}