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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool flag = false;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                flag = true;
                break;
            }
        }

        if (flag == false) {
            return nullptr;
        } else {
            ListNode* temp = head;

            while (temp != slow) {
                temp = temp->next;
                slow = slow->next;
            }

            return temp;
        }
    }
};

// Create linked list
ListNode* createList(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Create cycle at position pos (0-based)
// pos = -1 means no cycle
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;

    ListNode* cycleNode = nullptr;
    ListNode* temp = head;
    int index = 0;

    while (temp->next != nullptr) {
        if (index == pos)
            cycleNode = temp;
        temp = temp->next;
        index++;
    }

    if (index == pos)
        cycleNode = temp;

    temp->next = cycleNode;
}

int main() {
    vector<int> arr = {3, 2, 0, -4};

    ListNode* head = createList(arr);

    // Create a cycle at index 1 (node with value 2)
    createCycle(head, 1);

    Solution obj;
    ListNode* ans = obj.detectCycle(head);

    if (ans != nullptr)
        cout << "Cycle starts at node with value: " << ans->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}