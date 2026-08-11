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
    void leftBoundary(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        Node *temp = root;

        while (temp)
        {
            // Don't add leaf nodes
            if (temp->left || temp->right)
            {
                ans.push_back(temp->data);
            }

            // Follow actual left boundary
            if (temp->left)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
    }

    void leaf(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        // Leaf node
        if (!root->left && !root->right)
        {
            ans.push_back(root->data);
            return;
        }

        leaf(root->left, ans);
        leaf(root->right, ans);
    }

    void rightBoundary(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        Node *temp = root;
        vector<int> arr;

        while (temp)
        {
            // Don't add leaf nodes
            if (temp->left || temp->right)
            {
                arr.push_back(temp->data);
            }

            // Follow actual right boundary
            if (temp->right)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }

        // Right boundary: bottom to top
        reverse(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            ans.push_back(arr[i]);
        }
    }

    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        // Single node
        if (!root->left && !root->right)
        {
            ans.push_back(root->data);
            return ans;
        }

        // Root
        ans.push_back(root->data);

        // Left boundary
        leftBoundary(root->left, ans);

        // Leaf nodes
        leaf(root, ans);

        // Right boundary
        rightBoundary(root->right, ans);

        return ans;
    }
};

int main()
{
    /*
              1
             / \
            2   3
           / \ / \
          4  5 6  7
             / \
            8   9

        Boundary:
        1 2 4 5 8 9 6 7 3
    */

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    Solution obj;

    vector<int> ans = obj.boundaryTraversal(root);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}