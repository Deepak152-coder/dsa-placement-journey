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
    TreeNode *makeTree(TreeNode *p, TreeNode *q)
    {

        if (!p)
        {
            return q;
        }

        if (!q)
        {
            return p;
        }

        TreeNode *root = new TreeNode(p->val + q->val);

        root->left = makeTree(p->left, q->left);
        root->right = makeTree(p->right, q->right);

        return root;
    }

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return makeTree(root1, root2);
    }
};

// Inorder traversal
void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{

    /*
        Tree 1:          Tree 2:

           1                2
          / \              / \
         3   2            1   3
        /                  \   \
       5                    4   7


        Merged Tree:

             3
            / \
           4   5
          / \   \
         5   4   7
    */

    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    Solution obj;

    TreeNode *result = obj.mergeTrees(root1, root2);

    cout << "Inorder: ";
    inorder(result);
    cout << endl;

    return 0;
}