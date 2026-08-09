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
void nthLevel(TreeNode *root, int curr, int dest)
{
    if (root == NULL)
    {
        return;
    }
    if (curr == dest)
    {
        cout << root->val << " "; // KAAM
        return;
    }
    nthLevel(root->left, curr + 1, dest);  // CALL 1
    nthLevel(root->right, curr + 1, dest); // CALL 2
}
void levelOrder(TreeNode *root)
{
    int n = level(root);
    for (int i = 1; i <= n; i++)
    {
        nthLevel(root, 1, i);
    }
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

    cout << "Element and Desired Level is : ";
    nthLevel(a, 1, 2);
    cout << endl;
    cout << "Level Order is : ";
    levelOrder(a);

    return 0;
}