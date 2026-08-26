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
    void solve(TreeNode *root, int &count, unordered_map<int, int> &mp)
    {
        int odd = 0;

        if (root == NULL)
        {
            return;
        }

        mp[root->val]++;

        if (!root->left && !root->right)
        {
            odd = 0;

            for (auto i : mp)
            {
                if (i.second % 2 == 1)
                {
                    odd++;
                }
            }

            if (odd <= 1)
            {
                count++;
            }
        }

        solve(root->left, count, mp);
        solve(root->right, count, mp);

        mp[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        unordered_map<int, int> mp;
        int count = 0;

        solve(root, count, mp);

        return count;
    }
};

int main()
{

    /*
              2
             / \
            3   1
           / \   \
          3   1   1
         /
        1

        Pseudo-palindromic paths = 2
    */

    TreeNode *root = new TreeNode(2);

    root->left = new TreeNode(3);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);

    root->right->right = new TreeNode(1);

    root->left->left->left = new TreeNode(1);

    Solution obj;

    cout << obj.pseudoPalindromicPaths(root) << endl;

    return 0;
}