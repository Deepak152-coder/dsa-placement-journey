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
    vector<TreeNode *> Solve(int i, int j)
    {

        vector<TreeNode *> ans;

        if (i > j)
        {
            ans.push_back(NULL);
            return ans;
        }

        for (int k = i; k <= j; k++)
        {

            vector<TreeNode *> left = Solve(i, k - 1);
            vector<TreeNode *> right = Solve(k + 1, j);

            for (auto l : left)
            {

                for (auto r : right)
                {

                    TreeNode *root = new TreeNode(k);

                    root->left = l;
                    root->right = r;

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        return Solve(1, n);
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<TreeNode *> ans = obj.generateTrees(n);

    cout << "Total Trees: " << ans.size() << endl;

    return 0;
}