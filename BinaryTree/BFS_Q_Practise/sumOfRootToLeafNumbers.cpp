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
    void helper(TreeNode *root, vector<int> &arr, vector<vector<int>> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        arr.push_back(root->val);

        if (!root->left && !root->right)
        {
            reverse(arr.begin(), arr.end());
            ans.push_back(arr);
            reverse(arr.begin(), arr.end());
        }

        helper(root->left, arr, ans);
        helper(root->right, arr, ans);

        arr.pop_back();
    }

    void Sum(vector<vector<int>> ans, int &sum)
    {
        int n = ans.size();

        for (int i = 0; i < n; i++)
        {
            long long power = 1;
            int digit = 0;

            int m = ans[i].size();

            for (int j = 0; j < m; j++)
            {
                digit += ans[i][j] * power;
                power *= 10;
            }

            sum += digit;
        }
    }

    int sumNumbers(TreeNode *root)
    {
        int sum = 0;

        vector<int> arr;
        vector<vector<int>> ans;

        helper(root, arr, ans);
        Sum(ans, sum);

        return sum;
    }
};

int main()
{
    // Example tree:
    //       1
    //      / \
    //     2   3
    //
    // Root-to-leaf numbers: 12 + 13 = 25

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution obj;

    cout << obj.sumNumbers(root) << endl;

    return 0;
}