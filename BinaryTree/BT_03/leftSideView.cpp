#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<int> leftView(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        queue<Node *> q;
        q.push(root);

        while (q.size())
        {
            int n = q.size();
            int k = -1;

            for (int i = 1; i <= n; i++)
            {
                Node *temp = q.front();
                q.pop();

                if (i == 1)
                {
                    k = temp->data;
                }

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            ans.push_back(k);
        }

        return ans;
    }
};

int main()
{
    /*
              1
             / \
            2   3
           / \   \
          4   5   6

        Left View:
        1 2 4
    */

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    Solution obj;

    vector<int> ans = obj.leftView(root);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}