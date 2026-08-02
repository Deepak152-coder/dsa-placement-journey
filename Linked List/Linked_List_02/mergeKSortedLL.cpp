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
        next = NULL;
    }
};

// Function to merge two sorted linked lists
ListNode* merge(ListNode* list1, ListNode* list2) {
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

// Function to merge K sorted linked lists
ListNode* mergeKLists(vector<ListNode*>& arr) {
    if (arr.size() == 0)
        return NULL;

    while (arr.size() > 1) {
        ListNode* a = arr[0];
        arr.erase(arr.begin());

        ListNode* b = arr[0];
        arr.erase(arr.begin());

        ListNode* c = merge(a, b);
        arr.push_back(c);
    }

    return arr[0];
}

// Create linked list
ListNode* createList(vector<int> arr) {
    if (arr.empty())
        return NULL;

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
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> a = {1, 4, 5};
    vector<int> b = {1, 3, 4};
    vector<int> c = {2, 6};

    ListNode* list1 = createList(a);
    ListNode* list2 = createList(b);
    ListNode* list3 = createList(c);

    vector<ListNode*> lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    ListNode* ans = mergeKLists(lists);

    cout << "Merged K Sorted Lists: ";
    printList(ans);

    return 0;
}