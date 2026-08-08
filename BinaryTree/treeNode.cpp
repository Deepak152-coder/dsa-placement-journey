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

int sum(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (root->val + sum(root->left) + sum(root->right));
}

int size(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (1 + size(root->left) + size(root->right));
}

int maxNode(TreeNode *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->val, max(maxNode(root->left), maxNode(root->right)));
}

int minNode(TreeNode *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->val, min(minNode(root->left), minNode(root->right)));
}

int product(TreeNode *root)
{
    if (root == NULL)
    {
        return 1;
    }
    return root->val * (product(root->left)) * (product(root->right));
}

int levels(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(levels(root->left), levels(root->right));
}

int height(TreeNode *root)
{
    return levels(root) - 1;
}

int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    display(a);
    cout << endl;
    cout << "sum is : " << sum(a) << endl;
    cout << "product is : " << product(a) << endl;
    cout << "size is : " << size(a) << endl;
    cout << "node with max val is : " << maxNode(a) << endl;
    cout << "node with min val is : " << minNode(a) << endl;
    cout << "No. of level is : " << levels(a) << endl;
    cout << "height is : " << height(a) << endl;

    return 0;
}