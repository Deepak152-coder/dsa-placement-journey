#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }

        if (p == NULL || q == NULL) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        bool lst = isSameTree(p->left, q->left);

        if (lst == false) {
            return false;
        }

        bool rst = isSameTree(p->right, q->right);

        if (rst == false) {
            return false;
        }

        return true;
    }
};

int main() {

    // Tree 1
    //       1
    //      / \
    //     2   3

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree 2
    //       1
    //      / \
    //     2   3

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;

    if (obj.isSameTree(p, q)) {
        cout << "Both trees are same" << endl;
    }
    else {
        cout << "Both trees are not same" << endl;
    }

    return 0;
}