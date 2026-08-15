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
    void helper(TreeNode *&root, int &count)
    {
        if (root == NULL)
        {
            return;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<TreeNode *> arr;

            if (count % 2 == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    TreeNode *temp = q.front();
                    q.pop();

                    if (temp->left)
                    {
                        q.push(temp->left);
                    }

                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    TreeNode *temp = q.front();
                    q.pop();

                    arr.push_back(temp);

                    if (temp->left)
                    {
                        q.push(temp->left);
                    }

                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                }

                int i = 0;
                int j = arr.size() - 1;

                while (i < j)
                {
                    swap(arr[i]->val, arr[j]->val);
                    i++;
                    j--;
                }
            }

            count++;
        }
    }

    TreeNode *reverseOddLevels(TreeNode *root)
    {
        int count = 0;
        helper(root, count);
        return root;
    }
};

// Level order input
TreeNode *buildTree(vector<int> &arr)
{
    if (arr.empty() || arr[0] == -1)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (arr[i] != -1)
        {
            temp->left = new TreeNode(arr[i]);
            q.push(temp->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1)
        {
            temp->right = new TreeNode(arr[i]);
            q.push(temp->right);
        }
        i++;
    }

    return root;
}

void printLevelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        cout << temp->val << " ";

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    TreeNode *root = buildTree(arr);

    Solution obj;

    root = obj.reverseOddLevels(root);

    printLevelOrder(root);

    return 0;
}