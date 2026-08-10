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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            int n = q.size();
            int maxVal = INT_MIN;

            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->val > maxVal)
                {
                    maxVal = temp->val;
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

            ans.push_back(maxVal);
        }

        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(9);

    Solution s;

    vector<int> ans = s.largestValues(root);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}