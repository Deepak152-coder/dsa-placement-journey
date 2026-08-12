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
                     vector<int> &post, int postLo, int postHi)
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

        int i = postLo;

        while (i <= postHi)
        {
            if (post[i] == pre[preLo + 1])
            {
                break;
            }
            i++;
        }

        int left_count = i - postLo + 1;
        int right_count = postHi - i - 1;

        root->left = helper(
            pre,
            preLo + 1,
            preLo + left_count,
            post,
            postLo,
            i);

        root->right = helper(
            pre,
            preLo + left_count + 1,
            preHi,
            post,
            i + 1,
            postHi - 1);

        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        int n = pre.size();

        return helper(
            pre,
            0,
            n - 1,
            post,
            0,
            n - 1);
    }
};

// Preorder traversal
void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main()
{

    vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    vector<int> post = {4, 5, 2, 6, 7, 3, 1};

    Solution obj;

    TreeNode *root = obj.constructFromPrePost(pre, post);

    cout << "Preorder: ";
    preorder(root);

    cout << endl;

    cout << "Postorder: ";
    postorder(root);

    return 0;
}