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
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void helper(TreeNode *root, vector<TreeNode *> &arr)
    {
        if (root == NULL)
        {
            return;
        }

        arr.push_back(root);

        helper(root->left, arr);
        helper(root->right, arr);
    }

    void list(TreeNode *&root, vector<TreeNode *> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            root->right = arr[i];
            root->left = NULL;
            root = root->right;
        }
    }

    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        vector<TreeNode *> arr;
        helper(root, arr);

        list(root, arr);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    Solution obj;

    obj.flatten(root);

    TreeNode *temp = root;

    cout << "Flattened tree: ";

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->right;
    }

    cout << endl;

    return 0;
}