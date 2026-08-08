#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void helper(TreeNode* root, string s, vector<string>& ans) {
        if (root == NULL) {
            return;
        }

        string a = to_string(root->val);

        if (s == "") {
            s += a;
        } else {
            s += "->" + a;
        }

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(s);
            return;
        }

        helper(root->left, s, ans);
        helper(root->right, s, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
};

int main() {

    // Tree: [1,2,3,null,5]
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);

    Solution obj;

    vector<string> ans = obj.binaryTreePaths(root);

    cout << "Binary Tree Paths:" << endl;

    for (string path : ans) {
        cout << path << endl;
    }

    return 0;
}