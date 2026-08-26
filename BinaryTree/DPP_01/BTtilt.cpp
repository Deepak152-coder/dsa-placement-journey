#include <iostream>
#include <cmath>
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
    int getAns(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = getAns(root->left, ans);
        int right = getAns(root->right, ans);

        ans += abs(left - right);

        return root->val + left + right;
    }

    int findTilt(TreeNode *root)
    {
        int ans = 0;

        getAns(root, ans);

        return ans;
    }
};

int main()
{
    // Example tree:
    //
    //        4
    //       / \
    //      2   9
    //     / \
    //    3   5

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution obj;

    cout << "Tilt of tree: " << obj.findTilt(root) << endl;

    return 0;
}