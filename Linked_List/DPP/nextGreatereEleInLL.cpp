#include <iostream>
#include <vector>
#include <stack>
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
    void makeArr(ListNode *head, vector<int> &arr)
    {
        ListNode *temp = head;

        while (temp)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }

    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> arr;
        makeArr(head, arr);

        vector<int> ans(arr.size(), 0);

        stack<int> st;

        for (int i = 0; i < arr.size(); i++)
        {
            while (st.size() && arr[st.top()] < arr[i])
            {
                ans[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};

int main()
{

    // Linked List: 2 -> 1 -> 5 -> 3 -> 4
    ListNode *head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);

    Solution obj;

    vector<int> ans = obj.nextLargerNodes(head);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}