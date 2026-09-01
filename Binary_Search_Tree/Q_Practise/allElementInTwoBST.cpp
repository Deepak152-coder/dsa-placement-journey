#include <bits/stdc++.h>
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
    void getAns(vector<int> &arr, vector<int> &brr, vector<int> &ans)
    {
        int i = 0;
        int j = 0;

        while (i < arr.size() && j < brr.size())
        {
            if (arr[i] < brr[j])
            {
                ans.push_back(arr[i]);
                i++;
            }
            else
            {
                ans.push_back(brr[j]);
                j++;
            }
        }

        while (i < arr.size())
        {
            ans.push_back(arr[i]);
            i++;
        }

        while (j < brr.size())
        {
            ans.push_back(brr[j]);
            j++;
        }
    }

    void makeArr(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        makeArr(root->left, ans);
        ans.push_back(root->val);
        makeArr(root->right, ans);
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> arr;
        vector<int> brr;
        vector<int> ans;

        makeArr(root1, arr);
        makeArr(root2, brr);

        getAns(arr, brr, ans);

        return ans;
    }
};

int main()
{

    // First BST
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    // Second BST
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    Solution obj;

    vector<int> ans = obj.getAllElements(root1, root2);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}