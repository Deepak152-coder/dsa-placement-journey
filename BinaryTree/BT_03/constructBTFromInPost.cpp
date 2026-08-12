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
    TreeNode *helper(vector<int> &in, int inLo, int inHi,
                     vector<int> &post, int postLo, int postHi)
    {

        if (inLo > inHi)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(post[postHi]);

        if (inLo == inHi)
        {
            return root;
        }

        int i = inLo;

        while (i <= inHi)
        {
            if (in[i] == post[postHi])
            {
                break;
            }
            i++;
        }

        int left_count = i - inLo;

        root->left = helper(
            in,
            inLo,
            i - 1,
            post,
            postLo,
            postLo + left_count - 1);

        root->right = helper(
            in,
            i + 1,
            inHi,
            post,
            postLo + left_count,
            postHi - 1);

        return root;
    }

    TreeNode *buildTree(vector<int> &in, vector<int> &post)
    {
        int n = in.size();

        return helper(
            in,
            0,
            n - 1,
            post,
            0,
            n - 1);
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

    vector<int> in = {9, 3, 15, 20, 7};
    vector<int> post = {9, 15, 7, 20, 3};

    Solution obj;

    TreeNode *root = obj.buildTree(in, post);

    cout << "Inorder of constructed tree: ";
    inorder(root);

    return 0;
}