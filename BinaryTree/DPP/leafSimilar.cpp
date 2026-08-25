#include <iostream>
#include <vector>
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
    void makeArr(TreeNode *root, vector<int> &arr)
    {

        if (root == NULL)
        {
            return;
        }

        if (!root->left && !root->right)
        {
            arr.push_back(root->val);
        }

        makeArr(root->left, arr);
        makeArr(root->right, arr);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {

        vector<int> a;
        vector<int> b;

        makeArr(root1, a);
        makeArr(root2, b);

        return a == b;
    }
};

int main()
{

    /*
            Tree 1
               3
              / \
             5   1
            / \ / \
           6  2 9  8
        */

    TreeNode *root1 = new TreeNode(3);

    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);

    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);

    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);

    /*
            Tree 2
               7
              / \
             2   4
            / \ / \
           6  9 8  1
        */

    TreeNode *root2 = new TreeNode(7);

    root2->left = new TreeNode(2);
    root2->right = new TreeNode(4);

    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(9);

    root2->right->left = new TreeNode(8);
    root2->right->right = new TreeNode(1);

    Solution obj;

    if (obj.leafSimilar(root1, root2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}