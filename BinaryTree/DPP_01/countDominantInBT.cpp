#include <iostream>
#include <climits>
#include <algorithm>
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
    int solve(TreeNode *root, int &count)
    {
        if (root == NULL)
        {
            return INT_MIN;
        }

        int l = solve(root->left, count);
        int r = solve(root->right, count);

        if (root->val >= l && root->val >= r)
        {
            count++;
        }

        return max(root->val, max(l, r));
    }

    int countDominantNodes(TreeNode *root)
    {
        int count = 0;

        solve(root, count);

        return count;
    }
};

int main()
{

    /*
            10
           /  \
          5    15
         / \
        2   7
    */

    TreeNode *root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);

    Solution obj;

    cout << "Number of dominant nodes: "
         << obj.countDominantNodes(root) << endl;

    return 0;
}