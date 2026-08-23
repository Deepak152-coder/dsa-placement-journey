#include <iostream>
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
    void avg(int &sum, int n)
    {
        if (n == 0)
        {
            return;
        }

        sum = sum / n;
    }

    void avgReturn(TreeNode *root, int &sum, int &n)
    {
        if (root == NULL)
        {
            return;
        }

        sum += root->val;
        n++;

        avgReturn(root->left, sum, n);
        avgReturn(root->right, sum, n);
    }

    void solve(TreeNode *root, int &count)
    {
        int sum = 0;
        int n = 0;

        avgReturn(root, sum, n);
        avg(sum, n);

        if (root == NULL)
        {
            return;
        }

        if (root->val == sum)
        {
            count++;
        }

        solve(root->left, count);
        solve(root->right, count);
    }

    int averageOfSubtree(TreeNode *root)
    {
        int count = 0;

        solve(root, count);

        return count;
    }
};

int main()
{

    // Example:
    //        4
    //       / \
    //      8   5
    //     / \
    //    0   1

    TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(8);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    Solution obj;

    cout << obj.averageOfSubtree(root) << endl;

    return 0;
}