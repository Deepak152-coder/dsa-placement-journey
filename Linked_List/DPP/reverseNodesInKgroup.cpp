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
    void makeList(vector<int> &brr, ListNode *&nhead)
    {
        ListNode *tail = NULL;

        for (int i = 0; i < brr.size(); i++)
        {
            ListNode *val = new ListNode(brr[i]);

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
        }
    }

    void makeArr(ListNode *head, vector<int> &brr, int k)
    {
        vector<int> arr;

        while (head)
        {
            arr.push_back(head->val);
            head = head->next;
        }

        int n = arr.size();
        int r = 0;

        for (int i = 0; i < n; i += k)
        {
            int val = n - i;

            if (val >= k)
            {
                reverse(arr.begin() + i, arr.begin() + i + k);

                brr.insert(
                    brr.end(),
                    arr.begin() + i,
                    arr.begin() + i + k);
            }
            else
            {
                brr.insert(
                    brr.end(),
                    arr.begin() + i,
                    arr.end());
            }
        }
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        vector<int> brr;
        ListNode *nhead = NULL;

        makeArr(head, brr, k);
        makeList(brr, nhead);

        return nhead;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main()
{
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution obj;

    ListNode *result = obj.reverseKGroup(head, k);

    cout << "Result: ";
    printList(result);

    return 0;
}