#include <iostream>
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
    bool isSame(TreeNode *p, TreeNode *q)
    {

        if (p == NULL && q == NULL)
        {
            return true;
        }

        if (p == NULL || q == NULL)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        bool ans = isSame(p->left, q->left) &&
                   isSame(p->right, q->right);

        return ans;
    }

    void traversal(TreeNode *root, TreeNode *sr, bool &ans)
    {

        if (root == NULL || ans == true)
        {
            return;
        }

        if (isSame(root, sr))
        {
            ans = true;
            return;
        }

        traversal(root->left, sr, ans);
        traversal(root->right, sr, ans);
    }

    bool isSubtree(TreeNode *root, TreeNode *sr)
    {

        bool ans = false;

        traversal(root, sr, ans);

        return ans;
    }
};

int main()
{

    /*
            Main Tree

                3
               / \
              4   5
             / \
            1   2
    */

    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(4);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    /*
            Subtree

                4
               / \
              1   2
    */

    TreeNode *sr = new TreeNode(4);

    sr->left = new TreeNode(1);
    sr->right = new TreeNode(2);

    Solution obj;

    bool ans = obj.isSubtree(root, sr);

    cout << boolalpha << ans << endl;

    return 0;
}