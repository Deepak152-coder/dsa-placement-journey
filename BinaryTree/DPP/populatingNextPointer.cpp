#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Solution
{
public:
    Node *connect(Node *root)
    {

        if (root == NULL)
        {
            return NULL;
        }

        queue<Node *> q;
        q.push(root);

        while (q.size())
        {

            int n = q.size();
            Node *prev = NULL;

            for (int i = 0; i < n; i++)
            {

                Node *temp = q.front();
                q.pop();

                if (prev)
                {
                    prev->next = temp;
                }

                prev = temp;

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            prev->next = NULL;
        }

        return root;
    }
};

int main()
{

    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    obj.connect(root);

    // Print using next pointers
    Node *level = root;

    while (level)
    {

        Node *temp = level;

        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;

        level = level->left;
    }

    return 0;
}