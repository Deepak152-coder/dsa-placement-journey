#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
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
    void helper(TreeNode *root, int target, int sum,
                vector<int> &arr, vector<vector<int>> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        sum += root->val;
        arr.push_back(root->val);

        // Check only at leaf node
        if (sum == target && !root->left && !root->right)
        {
            ans.push_back(arr);
        }

        helper(root->left, target, sum, arr, ans);
        helper(root->right, target, sum, arr, ans);

        // Backtracking
        arr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> arr;

        helper(root, targetSum, 0, arr, ans);

        return ans;
    }
};

int main()
{
    /*
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

        Target = 22

        Path:
        5 -> 4 -> 11 -> 2
        Sum = 22
    */

    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution obj;

    int targetSum = 22;

    vector<vector<int>> ans = obj.pathSum(root, targetSum);

    cout << "Paths with sum " << targetSum << ":" << endl;

    for (vector<int> path : ans)
    {
        for (int x : path)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}