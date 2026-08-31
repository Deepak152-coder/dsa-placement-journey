#include <iostream>
#include <climits>
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
    void getCount(TreeNode *root, int &count, int maxi)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->val >= maxi)
        {
            count++;
            maxi = root->val;
        }

        getCount(root->left, count, maxi);
        getCount(root->right, count, maxi);
    }

    int goodNodes(TreeNode *root)
    {
        int count = 0;

        getCount(root, count, root->val);

        return count;
    }
};

int main()
{
    /*
            3
           / \
          1   4
         /     \
        3       5
    */

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(5);

    Solution obj;

    cout << "Number of Good Nodes: "
         << obj.goodNodes(root) << endl;

    return 0;
}