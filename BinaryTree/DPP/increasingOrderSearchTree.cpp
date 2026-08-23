#include <iostream>
#include <vector>
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
    void helper(TreeNode *root, vector<TreeNode *> &arr)
    {
        if (root == NULL)
        {
            return;
        }

        helper(root->left, arr);
        arr.push_back(root);
        helper(root->right, arr);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        vector<TreeNode *> arr;
        helper(root, arr);

        TreeNode *head = arr[0];
        TreeNode *temp = head;

        for (int i = 1; i < arr.size(); i++)
        {
            temp->left = NULL;
            temp->right = arr[i];
            temp = temp->right;
        }

        temp->left = NULL;
        temp->right = NULL;

        return head;
    }
};

void printTree(TreeNode *root)
{
    while (root != NULL)
    {
        cout << root->val << " ";
        root = root->right;
    }
}

int main()
{
    // Example BST
    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(8);

    Solution obj;

    TreeNode *result = obj.increasingBST(root);

    cout << "Increasing BST: ";
    printTree(result);

    return 0;
}