#include <iostream>
#include <vector>
#include <algorithm>
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
    void makeList(vector<int> &brr, ListNode *&mhead)
    {

        ListNode *tail = NULL;

        for (int i = 0; i < brr.size(); i++)
        {

            ListNode *temp = new ListNode(brr[i]);

            if (!mhead)
            {
                mhead = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
    }

    void makeArr(ListNode *head, ListNode *&mhead)
    {

        vector<int> arr;

        while (head)
        {
            arr.push_back(head->val);
            head = head->next;
        }

        int n = arr.size();

        vector<int> brr;

        int maxRight = -1;

        for (int i = n - 1; i >= 0; i--)
        {

            if (arr[i] >= maxRight)
            {
                brr.push_back(arr[i]);
                maxRight = arr[i];
            }
        }

        reverse(brr.begin(), brr.end());

        makeList(brr, mhead);
    }

    ListNode *removeNodes(ListNode *head)
    {

        ListNode *mhead = NULL;

        makeArr(head, mhead);

        return mhead;
    }
};

void printList(ListNode *head)
{

    while (head)
    {
        cout << head->val;

        if (head->next)
        {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

int main()
{

    /*
        Input:
        5 -> 2 -> 13 -> 3 -> 8

        Nodes removed:
        5, 2, 3

        Output:
        13 -> 8
    */

    ListNode *head = new ListNode(5);

    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    Solution obj;

    ListNode *ans = obj.removeNodes(head);

    cout << "Original List: ";
    printList(head);

    cout << "After Removing Nodes: ";
    printList(ans);

    return 0;
}