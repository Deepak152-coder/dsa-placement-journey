#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

void deleteNode(ListNode* node) {
    node->val = node->next->val;

    ListNode* temp = node->next;
    node->next = node->next->next;

    delete temp;   // Free the deleted node
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original List: ";
    printList(head);

    // Delete node with value 5
    deleteNode(head->next);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}