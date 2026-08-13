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

        while (in[i] != pre[preLo])
        {
            i++;
        }

        int left_count = i - inLo;
        int right_count = inHi - i;

        root->left = helper(
            pre,
            preLo + 1,
            preLo + left_count,
            in,
            inLo,
            i - 1);

        root->right = helper(
            pre,
            preHi - right_count + 1,
            preHi,
            in,
            i + 1,
            inHi);

        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &pre)
    {
        vector<int> in = pre;

        sort(in.begin(), in.end());

        int n = pre.size();

        return helper(pre, 0, n - 1, in, 0, n - 1);
    }
};