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
    string doubleString(string s)
    {
        int carry = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            int x = (s[i] - '0') * 2 + carry;

            s[i] = (x % 10) + '0';
            carry = x / 10;
        }

        if (carry)
            s = char(carry + '0') + s;

        return s;
    }

    void makeStr(ListNode *head, string &s2)
    {
        ListNode *temp = head;
        string s = "";

        while (temp)
        {
            s += to_string(temp->val);
            temp = temp->next;
        }

        s2 = doubleString(s);
    }

    void makeList(string s, ListNode *&head)
    {
        ListNode *tail = NULL;

        for (int i = 0; i < s.size(); i++)
        {
            ListNode *thead = new ListNode(s[i] - '0');

            if (!head)
            {
                head = thead;
                tail = thead;
            }
            else
            {
                tail->next = thead;
                tail = thead;
            }
        }
    }

    ListNode *doubleIt(ListNode *head)
    {
        string s = "";

        makeStr(head, s);

        ListNode *mhead = NULL;

        makeList(s, mhead);

        return mhead;
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
    int n;
    cin >> n;

    ListNode *head = NULL;
    ListNode *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        ListNode *newNode = new ListNode(x);

        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Solution obj;

    ListNode *result = obj.doubleIt(head);

    printList(result);

    return 0;
}