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

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    stack<TreeNode *> st;
    st.push(root);

    while (st.size())
    {
        TreeNode *temp = st.top();
        st.pop();

        ans.push_back(temp->val);

        if (temp->left)
        {
            st.push(temp->left);
        }

        if (temp->right)
        {
            st.push(temp->right);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> ans = postorderTraversal(root);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}