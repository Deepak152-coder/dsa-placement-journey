#include <iostream>
#include <vector>
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
    void makeArr(TreeNode *root, vector<int> &arr)
    {

        if (root == NULL)
        {
            return;
        }

        makeArr(root->left, arr);

        arr.push_back(root->val);

        makeArr(root->right, arr);
    }

    int minDiffInBST(TreeNode *root)
    {

        vector<int> arr;

        makeArr(root, arr);

        int val = INT_MAX;

        for (int i = 1; i < arr.size(); i++)
        {
            val = min(val, arr[i] - arr[i - 1]);
        }

        return val;
    }
};

int main()
{

    /*
            4
           / \
          2   6
         / \
        1   3

        Inorder:
        1 2 3 4 6

        Differences:
        1, 1, 1, 2

        Answer = 1
    */

    TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;

    cout << "Minimum Difference: "
         << obj.minDiffInBST(root) << endl;

    return 0;
}