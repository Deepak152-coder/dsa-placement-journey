#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    stack<TreeNode *> st;
    TreeNode *node = root;

    while (st.size() || node)
    {
        if (node)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            TreeNode *temp = st.top();
            st.pop();

            ans.push_back(temp->val);

            node = temp->right;
        }
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> ans = inorderTraversal(root);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}