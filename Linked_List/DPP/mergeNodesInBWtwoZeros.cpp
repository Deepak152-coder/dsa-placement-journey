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
    void makeArr(ListNode *head, ListNode *&nhead)
    {
        int sum = 0;
        ListNode *tail = NULL;

        while (head)
        {
            if (head->val != 0)
            {
                sum += head->val;
            }
            else
            {
                ListNode *val = new ListNode(sum);

                if (!nhead)
                {
                    nhead = val;
                    tail = val;
                }
                else
                {
                    tail->next = val;
                    tail = val;
                }

                sum = 0;
            }

            head = head->next;
        }
    }

    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *nhead = NULL;

        makeArr(head, nhead);

        return nhead->next;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0
    ListNode *head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(0);

    Solution obj;

    ListNode *result = obj.mergeNodes(head);

    printList(result);

    return 0;
}