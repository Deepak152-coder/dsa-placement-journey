#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int minr = 0;
        int maxr = m - 1;
        int minc = 0;
        int maxc = n - 1;

        ListNode* temp = head;

        while (minr <= maxr && minc <= maxc) {

            // Right
            for (int i = minc; i <= maxc; i++) {
                if (temp != nullptr) {
                    matrix[minr][i] = temp->val;
                    temp = temp->next;
                } else {
                    return matrix;
                }
            }
            minr++;

            if (minr > maxr || minc > maxc)
                break;

            // Down
            for (int j = minr; j <= maxr; j++) {
                if (temp != nullptr) {
                    matrix[j][maxc] = temp->val;
                    temp = temp->next;
                } else {
                    return matrix;
                }
            }
            maxc--;

            if (minr > maxr || minc > maxc)
                break;

            // Left
            for (int i = maxc; i >= minc; i--) {
                if (temp != nullptr) {
                    matrix[maxr][i] = temp->val;
                    temp = temp->next;
                } else {
                    return matrix;
                }
            }
            maxr--;

            if (minr > maxr || minc > maxc)
                break;

            // Up
            for (int j = maxr; j >= minr; j--) {
                if (temp != nullptr) {
                    matrix[j][minc] = temp->val;
                    temp = temp->next;
                } else {
                    return matrix;
                }
            }
            minc++;
        }

        return matrix;
    }
};

// Create linked list
ListNode* createList(vector<int>& arr) {
    if (arr.empty())
        return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print matrix
void printMatrix(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    int m = 3;
    int n = 5;

    vector<int> arr = {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0};

    ListNode* head = createList(arr);

    Solution obj;
    vector<vector<int>> ans = obj.spiralMatrix(m, n, head);

    cout << "Spiral Matrix:\n";
    printMatrix(ans);

    return 0;
}