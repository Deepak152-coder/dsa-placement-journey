#include <iostream>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
private:
    bool detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

public:
    bool hasCycle(ListNode* head) {
        return detectCycle(head);
    }
};

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Create a cycle
    head->next->next->next->next = head->next; // 4 -> 2

    Solution obj;

    if (obj.hasCycle(head))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}