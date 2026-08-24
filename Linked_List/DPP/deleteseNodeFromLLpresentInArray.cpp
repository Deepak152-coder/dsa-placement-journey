#include <iostream>
#include <vector>
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
    void makeSet(vector<int> &arr, unordered_set<int> &st)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            st.insert(arr[i]);
        }
    }

    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {

        unordered_set<int> st;

        makeSet(nums, st);

        ListNode *temp = head;
        ListNode *mhead = NULL;
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

                mtail->next = NULL;
            }

            temp = nextNode;
        }

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

    // nums = [9, 2, 5]
    vector<int> nums = {9, 2, 5};

    // head = [2, 10, 9]
    ListNode *head = new ListNode(2);
    head->next = new ListNode(10);
    head->next->next = new ListNode(9);

    Solution obj;

    ListNode *ans = obj.modifiedList(nums, head);

    cout << "Result: ";
    printList(ans);

    return 0;
}