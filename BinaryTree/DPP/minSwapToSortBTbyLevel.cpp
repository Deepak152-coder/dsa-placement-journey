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
    void solve(vector<int> &arr, int &count)
    {

        int n = arr.size();

        vector<pair<int, int>> temp;

        for (int i = 0; i < n; i++)
        {
            temp.push_back({arr[i], i});
        }

        sort(temp.begin(), temp.end());

        for (int i = 0; i < n; i++)
        {

            if (temp[i].second != i)
            {

                swap(temp[i], temp[temp[i].second]);

                count++;

                i--;
            }
        }
    }

    void makeArr(TreeNode *root, int &count)
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
            vector<int> arr;

            for (int i = 0; i < n; i++)
            {

                TreeNode *temp = q.front();
                q.pop();

                arr.push_back(temp->val);

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            solve(arr, count);
        }
    }

    int minimumOperations(TreeNode *root)
    {

        int count = 0;

        makeArr(root, count);

        return count;
    }
};

int main()
{

    /*
            1
           / \
          4   3
         / \ / \
        7  6 8  5
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(4);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(5);

    Solution obj;

    int result = obj.minimumOperations(root);

    cout << "Minimum operations: " << result << endl;

    return 0;
}