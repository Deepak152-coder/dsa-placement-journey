#include <iostream>
#include <unordered_set>
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
    void makeSet(ListNode *head, unordered_set<int> &st)
    {

        ListNode *temp = head;

        while (temp->next)
        {

            if (temp->val == temp->next->val)
            {
                st.insert(temp->val);
            }

            temp = temp->next;
        }
    }

    void makeList(ListNode *head, unordered_set<int> &st, ListNode *&mhead)
    {

        ListNode *temp = head;
        ListNode *mtail = NULL;

        while (temp)
        {

            ListNode *nextNode = temp->next;

            if (st.find(temp->val) == st.end())
            {

                if (!mhead)
                {
                    mhead = temp;
                    mtail = temp;
                }
                else
                {
                    mtail->next = temp;
                    mtail = temp;
                }
            }

            temp = nextNode;
        }

        if (mtail)
        {
            mtail->next = NULL;
        }
    }

    ListNode *deleteDuplicates(ListNode *head)
    {

        if (head == NULL)
        {
            return NULL;
        }

        unordered_set<int> st;

        makeSet(head, st);

        ListNode *mhead = NULL;

        makeList(head, st, mhead);

        if (mhead == NULL)
        {
            return NULL;
        }

        return mhead;
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

    // 1 -> 1 -> 2 -> 3 -> 3 -> 4
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);

    Solution obj;

    ListNode *ans = obj.deleteDuplicates(head);

    cout << "Result: ";
    printList(ans);

    return 0;
}