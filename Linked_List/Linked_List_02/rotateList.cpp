#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int size = 1;

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        while (temp->next != nullptr) {
            size++;
            temp = temp->next;
        }

        int a = k % size;
        if (a == 0)
            return head;

        int m = size - a - 1;

        ListNode* t = head;
        for (int i = 1; i <= m; i++) {
            t = t->next;
        }

        ListNode* nhead = t->next;
        temp->next = head;
        t->next = nullptr;

        return nhead;
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

// Print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}