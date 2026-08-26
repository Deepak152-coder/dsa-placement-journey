#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

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
    void makeArr(TreeNode *root, vector<TreeNode *> &arr, ListNode *head)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->val == head->val)
        {
            arr.push_back(root);
        }

        makeArr(root->left, arr, head);
        makeArr(root->right, arr, head);
    }

    bool solve(TreeNode *root, ListNode *head)
    {
        if (head == NULL)
        {
            return true;
        }

        if (root == NULL)
        {
            return false;
        }

        if (root->val != head->val)
        {
            return false;
        }

        bool left = solve(root->left, head->next);
        bool right = solve(root->right, head->next);

        return left || right;
    }

    bool isSubPath(ListNode *head, TreeNode *root)
    {
        vector<TreeNode *> arr;

        makeArr(root, arr, head);

        for (int i = 0; i < arr.size(); i++)
        {
            bool flag = solve(arr[i], head);

            if (flag)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{

    /*
              Tree:

                 1
                / \
               4   4
              /   / \
             2   2   5
            /
           6

              Linked List:

              4 -> 2 -> 6

              Answer: true
    */

    // Create Tree
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(4);
    root->right = new TreeNode(4);

    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(6);

    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);

    // Create Linked List
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);

    Solution obj;

    cout << boolalpha << obj.isSubPath(head, root) << endl;

    return 0;
}