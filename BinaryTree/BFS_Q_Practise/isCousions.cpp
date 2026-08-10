#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    void helper(TreeNode *root, int target, int &pl, TreeNode *&p)
    {
        if (root == NULL)
        {
            return;
        }

        int l = 1;
        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->left && temp->left->val == target)
                {
                    pl = l;
                    p = temp;
                }

                if (temp->right && temp->right->val == target)
                {
                    pl = l;
                    p = temp;
                }

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            l++;
        }
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        int pl1 = -1;
        int pl2 = -1;

        TreeNode *p1 = NULL;
        TreeNode *p2 = NULL;

        helper(root, x, pl1, p1);
        helper(root, y, pl2, p2);

        cout << pl1 << " " << pl2 << endl;

        if (pl1 == pl2 && p1 != p2)
        {
            return true;
        }

        if (pl1 == pl2 && pl1 == -1)
        {
            return false;
        }

        return false;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution s;

    cout << boolalpha << s.isCousins(root, 4, 5) << endl;

    return 0;
}