#include <iostream>
#include <vector>
#include <string>
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
    void getAns(vector<string> &v, string &ans)
    {
        ans = v[0];

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] < ans)
            {
                ans = v[i];
            }
        }
    }

    void getArr(TreeNode *root, string &s, vector<string> &v)
    {
        if (root == NULL)
        {
            return;
        }

        // 0 -> a, 1 -> b, 2 -> c, ..., 25 -> z
        s.push_back(root->val + 'a');

        // Leaf node
        if (root->left == NULL && root->right == NULL)
        {

            // Convert root -> leaf into leaf -> root
            reverse(s.begin(), s.end());

            v.push_back(s);

            // Restore original string
            reverse(s.begin(), s.end());

            s.pop_back();
            return;
        }

        getArr(root->left, s, v);
        getArr(root->right, s, v);

        s.pop_back();
    }

    string smallestFromLeaf(TreeNode *root)
    {
        vector<string> v;
        string s = "";
        string ans = "";

        getArr(root, s, v);

        getAns(v, ans);

        return ans;
    }
};

int main()
{

    /*
             0
            / \
           1   2
          / \ / \
         3  4 3  4
    */

    TreeNode *root = new TreeNode(0);

    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    Solution obj;

    string ans = obj.smallestFromLeaf(root);

    cout << "Smallest string: " << ans << endl;

    return 0;
}