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

class Solution
{
public:
    TreeNode *helper(vector<int> &pre, int preLo, int preHi,
                     vector<int> &in, int inLo, int inHi)
    {
        if (preLo > preHi)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(pre[preLo]);

        if (preLo == preHi)
        {
            return root;
        }

        int i = inLo;

        while (i <= inHi)
        {
            if (in[i] == pre[preLo])
            {
                break;
            }
            i++;
        }

        int leftCount = i - inLo;
        int rightCount = inHi - i;

        root->left = helper(
            pre,
            preLo + 1,
            preLo + leftCount,
            in,
            inLo,
            i - 1);

        root->right = helper(
            pre,
            preLo + leftCount + 1,
            preHi,
            in,
            i + 1,
            inHi);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();

        return helper(
            preorder,
            0,
            n - 1,
            inorder,
            0,
            n - 1);
    }
};

// Inorder traversal to verify the tree
void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;

    TreeNode *root = obj.buildTree(preorder, inorder);

    cout << "Inorder of constructed tree: ";
    inorderTraversal(root);

    return 0;
}