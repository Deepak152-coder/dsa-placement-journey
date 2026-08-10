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
    int maxLevelSum(TreeNode *root)
    {
        int l = 1;
        int ans = 1;

        if (root == NULL)
        {
            return ans;
        }

        int maxSum = INT_MIN;

        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            int n = q.size();
            int sum = 0;

            for (int i = 1; i <= n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                sum += temp->val;

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            if (maxSum < sum)
            {
                maxSum = sum;
                ans = l;
            }

            l++;
        }

        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(7);
    root->right = new TreeNode(0);

    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    Solution s;

    cout << s.maxLevelSum(root) << endl;

    return 0;
}