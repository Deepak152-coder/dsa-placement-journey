#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    vector<Node *> children;

    Node(int x)
    {
        val = x;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {

        if (root == NULL)
        {
            return {};
        }

        queue<Node *> q;
        q.push(root);

        vector<vector<int>> ans;

        while (q.size())
        {

            int n = q.size();
            vector<int> arr;

            for (int i = 0; i < n; i++)
            {

                Node *temp = q.front();
                q.pop();

                arr.push_back(temp->val);

                for (auto child : temp->children)
                {
                    q.push(child);
                }
            }

            ans.push_back(arr);
        }

        return ans;
    }
};

int main()
{

    // Example:
    //
    //        1
    //      / | \
    //     3  2  4
    //    / \
    //   5   6

    Node *root = new Node(1);

    Node *n3 = new Node(3);
    Node *n2 = new Node(2);
    Node *n4 = new Node(4);

    Node *n5 = new Node(5);
    Node *n6 = new Node(6);

    n3->children.push_back(n5);
    n3->children.push_back(n6);

    root->children.push_back(n3);
    root->children.push_back(n2);
    root->children.push_back(n4);

    Solution obj;

    vector<vector<int>> ans = obj.levelOrder(root);

    for (auto level : ans)
    {
        for (auto x : level)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}