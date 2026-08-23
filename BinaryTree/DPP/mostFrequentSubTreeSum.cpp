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
    int getSum(TreeNode *root, int &sum, unordered_map<int, int> &mp)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = getSum(root->left, sum, mp);
        int right = getSum(root->right, sum, mp);

        sum = root->val + left + right;
        mp[sum]++;

        return sum;
    }

    void getAns(unordered_map<int, int> &mp, vector<int> &ans)
    {
        int freq = INT_MIN;

        for (auto i : mp)
        {
            freq = max(freq, i.second);
        }

        for (auto i : mp)
        {
            if (i.second == freq)
            {
                ans.push_back(i.first);
            }
        }
    }

    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        vector<int> ans;
        unordered_map<int, int> mp;

        int sum = 0;

        getSum(root, sum, mp);
        getAns(mp, ans);

        return ans;
    }
};

int main()
{

    // Tree:
    //       5
    //      / \
    //     2  -5

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-5);

    Solution obj;

    vector<int> ans = obj.findFrequentTreeSum(root);

    cout << "Answer: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}