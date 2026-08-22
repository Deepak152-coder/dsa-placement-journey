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
    void solve(Node *root, vector<int> &ans)
    {

        if (root == NULL)
        {
            return;
        }

        Node *temp = root;

        for (auto i : temp->children)
        {
            solve(i, ans);
        }

        ans.push_back(temp->val);
    }

    vector<int> postorder(Node *root)
    {

        vector<int> ans;

        solve(root, ans);

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
    //
    // Postorder: 5 6 3 2 4 1

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

    vector<int> ans = obj.postorder(root);

    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}