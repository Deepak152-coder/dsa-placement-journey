#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    void deleteMiddle(ListNode *&head, ListNode *middle)
    {

        ListNode *temp = head;

        while (temp->next != middle)
        {
            temp = temp->next;
        }

        temp->next = middle->next;

        delete middle;
    }

    void getMiddle(ListNode *head, ListNode *&middle)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        middle = slow;
    }

    ListNode *deleteMiddle(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        ListNode *middle = NULL;

        getMiddle(head, middle);
        deleteMiddle(head, middle);

        return head;
    }
};

void printList(ListNode *head)
{

    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{

    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Before: ";
    printList(head);

    Solution obj;

    head = obj.deleteMiddle(head);

    cout << "After: ";
    printList(head);

    return 0;
}