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

void display(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->val << " ";

    display(root->left);
    display(root->right);
}

TreeNode *construct(vector<int> arr, int n)
{
    if (n == 0)
    {
        return NULL;
    }

    queue<TreeNode *> q;

    TreeNode *root = new TreeNode(arr[0]);
    q.push(root);

    int i = 1;
    int j = 2;

    while (q.size() && j < n)
    {
        TreeNode *temp = q.front();
        q.pop();

        TreeNode *l;
        TreeNode *r;

        if (arr[i] != INT_MIN)
        {
            l = new TreeNode(arr[i]);
        }
        else
        {
            l = NULL;
        }

        if (arr[j] != INT_MIN)
        {
            r = new TreeNode(arr[j]);
        }
        else
        {
            r = NULL;
        }

        temp->left = l;
        temp->right = r;

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }

        i += 2;
        j += 2;
    }

    return root;
}

int main()
{
    vector<int> arr = {
        1, 2, 3, 4, 5, 6, INT_MIN, 6, INT_MIN, 7, 8, 9};

    int n = arr.size();

    TreeNode *root = construct(arr, n);

    display(root);

    return 0;
}