#include <iostream>
#include <vector>
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
    void getVal(vector<int> arr, int &sum)
    {
        reverse(arr.begin(), arr.end());

        int power = 1;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i] * power;
            power *= 2;
        }
    }

    void solve(TreeNode *root, vector<int> &arr, int &sum)
    {

        if (root == NULL)
        {
            return;
        }

        arr.push_back(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            getVal(arr, sum);
        }

        solve(root->left, arr, sum);
        solve(root->right, arr, sum);

        arr.pop_back();
    }

    int sumRootToLeaf(TreeNode *root)
    {

        int sum = 0;
        vector<int> arr;

        solve(root, arr, sum);

        return sum;
    }
};

int main()
{

    /*
            1
           / \
          0   1
         / \ / \
        0  1 0  1

        Paths:
        100 = 4
        101 = 5
        110 = 6
        111 = 7

        Sum = 22
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(0);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    Solution obj;

    cout << "Sum of Root-to-Leaf Binary Numbers: "
         << obj.sumRootToLeaf(root) << endl;

    return 0;
}