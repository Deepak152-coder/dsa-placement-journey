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
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        TreeNode *temp = root;

        if (root == NULL)
        {
            return NULL;
        }

        temp->left = removeLeafNodes(temp->left, target);
        temp->right = removeLeafNodes(temp->right, target);

        if (!temp->left && !temp->right && temp->val == target)
        {
            return NULL;
        }

        return root;
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
              1
             / \
            2   3
           / \   \
          2   2   4

        target = 2
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(2);

    root->right->right = new TreeNode(4);

    int target = 2;

    Solution obj;

    root = obj.removeLeafNodes(root, target);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}