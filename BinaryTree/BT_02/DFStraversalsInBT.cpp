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

void PreOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " "; // KAAM
    PreOrder(root->left);     // CALL 1
    PreOrder(root->right);    // CALL 2
}
void InOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);      // CALL 1
    cout << root->val << " "; // KAAM
    InOrder(root->right);     // CALL 2
}
void PostOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);    // CALL 1
    PostOrder(root->right);   // CALL 2
    cout << root->val << " "; // KAAM
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

    cout << "PreOrder : ";
    PreOrder(a);
    cout << endl;
    cout << "InOrder : ";
    InOrder(a);
    cout << endl;
    cout << "PostOrder : ";
    PostOrder(a);

    return 0;
}