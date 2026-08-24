#include <iostream>
#include <vector>
#include <queue>
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
    void Solve(TreeNode *root, vector<long long> &ans)
    {

        if (root == NULL)
        {
            return;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {

            int n = q.size();
            long long sum = 0;

            for (int i = 0; i < n; i++)
            {

                TreeNode *temp = q.front();
                q.pop();

                sum += temp->val;

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            ans.push_back(sum);
        }

        sort(ans.begin(), ans.end());
    }

    long long kthLargestLevelSum(TreeNode *root, int k)
    {

        vector<long long> ans;

        Solve(root, ans);

        int n = ans.size();

        if (k > n)
        {
            return -1;
        }

        return ans[n - k];
    }
};

int main()
{

    /*
            5
           / \
          8   9
         / \   \
        2   1   7
    */

    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(8);
    root->right = new TreeNode(9);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);

    root->right->right = new TreeNode(7);

    int k = 2;

    Solution obj;

    long long result = obj.kthLargestLevelSum(root, k);

    cout << "Kth largest level sum: " << result << endl;

    return 0;
}