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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {

        if (root == NULL)
        {
            return NULL;
        }

        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode *> q;
        q.push(root);

        int count = 1;

        while (q.size())
        {

            int n = q.size();

            for (int i = 0; i < n; i++)
            {

                TreeNode *temp = q.front();
                q.pop();

                if (count == depth - 1)
                {

                    TreeNode *oldtemp = temp->left;
                    TreeNode *nleft = temp;

                    nleft->left = new TreeNode(val);
                    nleft->left->left = oldtemp;

                    TreeNode *oldtemp2 = temp->right;
                    TreeNode *nright = temp;

                    nright->right = new TreeNode(val);
                    nright->right->right = oldtemp2;
                }
                else
                {

                    if (temp->left)
                    {
                        q.push(temp->left);
                    }

                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                }
            }

            count++;
        }

        return root;
    }
};

// Level Order Traversal
void levelOrder(TreeNode *root)
{

    if (root == NULL)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {

        int n = q.size();

        while (n--)
        {

            TreeNode *temp = q.front();
            q.pop();

            cout << temp->val << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        cout << endl;
    }
}

int main()
{

    /*
            Original Tree

                 4
                / \
               2   6
              / \   \
             3   1   5

            val = 1
            depth = 3

            Result:

                 4
                / \
               2   6
              / \ / \
             1  1 1  1
            / \   \   \
           3   1   5

    */

    TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);

    root->right->right = new TreeNode(5);

    int val = 1;
    int depth = 3;

    Solution obj;

    root = obj.addOneRow(root, val, depth);

    cout << "Level Order:" << endl;
    levelOrder(root);

    return 0;
}