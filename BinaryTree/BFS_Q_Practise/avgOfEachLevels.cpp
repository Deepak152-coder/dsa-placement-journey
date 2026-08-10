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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;

        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            int n = q.size();

            double s = 0;

            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                s += temp->val;

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            double k = s / n;
            ans.push_back(k);
        }

        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;

    vector<double> ans = s.averageOfLevels(root);

    for (double x : ans)
    {
        cout << x << " ";
    }

    return 0;
}