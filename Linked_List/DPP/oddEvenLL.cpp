#include <iostream>
#include <vector>
using namespace std;

// Definition of ListNode
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
    void makeList(ListNode *&temp, vector<int> odd)
    {
        ListNode *tail = NULL;

        for (int i = 0; i < odd.size(); i++)
        {
            ListNode *val = new ListNode(odd[i]);

            if (!temp)
            {
                temp = val;
                tail = val;
            }
            else
            {
                tail->next = val;
                tail = val;
            }
        }
    }

    void makeArr(ListNode *head, vector<int> &odd)
    {
        vector<int> arr;
        vector<int> even;

        while (head)
        {
            arr.push_back(head->val);
            head = head->next;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (i % 2 == 0)
            {
                odd.push_back(arr[i]);
            }
            else
            {
                even.push_back(arr[i]);
            }
        }

        for (int i = 0; i < even.size(); i++)
        {
            odd.push_back(even[i]);
        }
    }

    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *temp = NULL;

        vector<int> odd;
        makeArr(head, odd);
        makeList(temp, odd);

        return temp;
    }
};

// Function to insert a node at the end
void insertAtTail(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);

    if (!head)
    {
        head = newNode;
        return;
    }

    ListNode *temp = head;

    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print linked list
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

    ListNode *head = NULL;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insertAtTail(head, value);
    }

    Solution obj;

    ListNode *ans = obj.oddEvenList(head);

    cout << "Odd-Even Linked List: ";
    printList(ans);

    return 0;
}