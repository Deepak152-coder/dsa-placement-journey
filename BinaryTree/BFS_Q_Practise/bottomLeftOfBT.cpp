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
    int level(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = level(root->left);
        int right = level(root->right);

        return 1 + max(left, right);
    }

    void levelOrder(TreeNode *root, int curr, int dest, int &ans)
    {
        if (root == NULL)
        {
            return;
        }

        if (curr == dest)
        {
            ans = root->val;
            return;
        }

        levelOrder(root->left, curr + 1, dest, ans);

        if (ans != -10)
        {
            return;
        }

        levelOrder(root->right, curr + 1, dest, ans);
    }

    int findBottomLeftValue(TreeNode *root)
    {
        int ans = -10;

        int n = level(root);

        levelOrder(root, 1, n, ans);

        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(2);

    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution s;

    cout << s.findBottomLeftValue(root) << endl;

    return 0;
}