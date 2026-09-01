#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
    }
};

class Solution
{
public:
    void makeArr(ListNode *list1, int a, int b, ListNode *list2,
                 ListNode *&nhead)
    {

        ListNode *tail = NULL;
        int count = 0;

        while (list1)
        {

            if (count < a)
            {

                if (!nhead)
                {
                    nhead = list1;
                    tail = list1;
                }
                else
                {
                    tail->next = list1;
                    tail = list1;
                }
            }

            if (count == a)
            {

                while (list2)
                {
                    tail->next = list2;
                    tail = list2;
                    list2 = list2->next;
                }
            }

            if (count > b)
            {
                tail->next = list1;
                tail = list1;
            }

            list1 = list1->next;
            count++;
        }
    }

    ListNode *mergeInBetween(ListNode *list1, int a, int b,
                             ListNode *list2)
    {

        ListNode *nhead = NULL;

        makeArr(list1, a, b, list2, nhead);

        return nhead;
    }
};

int main()
{

    ListNode *list1 = new ListNode(0);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(4);
    list1->next->next->next->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(100);
    list2->next = new ListNode(101);

    int a = 3;
    int b = 4;

    Solution obj;

    ListNode *ans = obj.mergeInBetween(list1, a, b, list2);

    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}
