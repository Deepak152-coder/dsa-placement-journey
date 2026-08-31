#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *temp = head;

        while (temp && temp->next)
        {
            ListNode *nextNode = temp->next;

            ListNode *val = new ListNode(
                gcd(temp->val, nextNode->val));

            temp->next = val;
            val->next = nextNode;

            temp = nextNode;
        }

        return head;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    // Example: 18 -> 6 -> 10
    ListNode *head = new ListNode(18);
    head->next = new ListNode(6);
    head->next->next = new ListNode(10);

    Solution obj;

    head = obj.insertGreatestCommonDivisors(head);

    printList(head);

    return 0;
}