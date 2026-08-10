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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            int n = q.size();
            vector<int> arr;

            for (int i = 1; i <= n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                arr.push_back(temp->val);

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            ans.push_back(arr);
        }

        reverse(ans.begin(), ans.end());

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

    vector<vector<int>> ans = s.levelOrderBottom(root);

    for (auto level : ans)
    {
        for (auto x : level)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}