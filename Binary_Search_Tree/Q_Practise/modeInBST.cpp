#include <iostream>
#include <vector>
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
    void helper(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
        {
            return;
        }

        helper(root->left, arr);
        arr.push_back(root->val);
        helper(root->right, arr);
    }

    vector<int> findMode(TreeNode *root)
    {
        vector<int> arr;
        helper(root, arr);

        vector<int> ans;
        int maxFreq = 0;
        int count = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (i == 0 || arr[i] == arr[i - 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }

            if (count > maxFreq)
            {
                maxFreq = count;
                ans.clear();
                ans.push_back(arr[i]);
            }
            else if (count == maxFreq)
            {
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};

int main()
{
    // Example BST
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    Solution obj;

    vector<int> ans = obj.findMode(root);

    cout << "Mode: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}