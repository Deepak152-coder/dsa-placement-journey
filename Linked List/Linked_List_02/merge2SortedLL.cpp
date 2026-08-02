#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tempa = list1;
        ListNode* tempb = list2;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (tempa != NULL && tempb != NULL) {
            if (tempa->val <= tempb->val) {
                temp->next = tempa;
                tempa = tempa->next;
            } else {
                temp->next = tempb;
                tempb = tempb->next;
            }
            temp = temp->next;
        }

        while (tempa != NULL) {
            temp->next = tempa;
            tempa = tempa->next;
            temp = temp->next;
        }

        while (tempb != NULL) {
            temp->next = tempb;
            tempb = tempb->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};

// Function to create a linked list
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> a = {1, 2, 4};
    vector<int> b = {1, 3, 4};

    ListNode* list1 = createList(a);
    ListNode* list2 = createList(b);

    Solution obj;
    ListNode* ans = obj.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(ans);

    return 0;
}