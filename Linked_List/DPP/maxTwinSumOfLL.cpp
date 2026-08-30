#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
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
    void makeArr(ListNode *head, int &ans)
    {
        vector<int> arr;

        while (head)
        {
            arr.push_back(head->val);
            head = head->next;
        }

        int i = 0;
        int j = arr.size() - 1;

        while (i < j)
        {
            ans = max(ans, arr[i] + arr[j]);
            i++;
            j--;
        }
    }

    int pairSum(ListNode *head)
    {
        int ans = INT_MIN;
        makeArr(head, ans);
        return ans;
    }
};

int main()
{
    // Example: [5, 4, 2, 1]
    ListNode *head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution obj;

    cout << "Maximum Twin Sum = " << obj.pairSum(head) << endl;

    return 0;
}