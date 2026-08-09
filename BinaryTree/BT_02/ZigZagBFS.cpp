#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    void helper(TreeNode* root, vector<vector<int>>& ans) {

        if (root == NULL) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        int k = 0;

        while (q.size()) {

            int n = q.size();
            vector<int> arr;

            for (int i = 1; i <= n; i++) {

                TreeNode* temp = q.front();
                q.pop();

                arr.push_back(temp->val);

                if (temp->left) {
                    q.push(temp->left);
                }

                if (temp->right) {
                    q.push(temp->right);
                }
            }

            if (k % 2 == 1) {
                reverse(arr.begin(), arr.end());
            }

            ans.push_back(arr);

            k++;
        }

        return;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        helper(root, ans);

        return ans;
    }
};

int main() {

    // Creating tree:
    //
    //        3
    //       / \
    //      9   20
    //          / \
    //         15  7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.zigzagLevelOrder(root);

    for (auto level : ans) {
        for (auto value : level) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}