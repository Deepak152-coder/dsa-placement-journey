#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

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
    bool isEvenOddTree(TreeNode* root)
    {
        bool flag = true;
        int l = 1;

        if (root == NULL)
        {
            return flag;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (q.size())
        {
            int n = q.size();
            int prev = 0;

            for (int i = 0; i < n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                // Odd level -> values must be odd
                // Even level -> values must be even
                if (l % 2 == 1 && temp->val % 2 != 1)
                {
                    flag = false;
                    return flag;
                }
                else if (l % 2 == 0 && temp->val % 2 != 0)
                {
                    flag = false;
                    return flag;
                }

                // Even level -> strictly decreasing
                if (i > 0 && l % 2 == 0 && prev <= temp->val)
                {
                    flag = false;
                    return flag;
                }

                // Odd level -> strictly increasing
                if (i > 0 && l % 2 == 1 && prev >= temp->val)
                {
                    flag = false;
                    return flag;
                }

                prev = temp->val;

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

        return flag;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(10);
    root->right = new TreeNode(4);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(9);

    Solution s;

    cout << boolalpha << s.isEvenOddTree(root) << endl;

    return 0;
}