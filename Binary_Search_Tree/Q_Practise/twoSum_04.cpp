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
    void getAns(vector<int> &arr, bool &flag, int k)
    {
        int i = 0;
        int j = arr.size() - 1;

        while (i < j)
        {
            if (arr[i] + arr[j] == k)
            {
                flag = true;
                return;
            }
            else if (arr[i] + arr[j] > k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }

    void makeArr(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
        {
            return;
        }

        makeArr(root->left, arr);
        arr.push_back(root->val);
        makeArr(root->right, arr);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> arr;
        bool flag = false;

        makeArr(root, arr);
        getAns(arr, flag, k);

        return flag;
    }
};

int main()
{
    // Creating BST:
    //        5
    //       / \
    //      3   6
    //     / \   \
    //    2   4   7

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k = 9;

    Solution obj;

    cout << boolalpha << obj.findTarget(root, k) << endl;

    return 0;
}