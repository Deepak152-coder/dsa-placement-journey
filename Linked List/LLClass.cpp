#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size;

    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }

    void InsertAtTail(int val)
    {
        Node *temp = new Node(val);

        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void InsertAtHead(int val)
    {
        Node *temp = new Node(val);

        temp->next = head;
        head = temp;
    }

    void Display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void InsertAtIndex(int idx, int val)
    {
        if (idx == 0)
        {
            InsertAtHead(val);
        }
        else if (idx == size)
        {
            InsertAtTail(val);
        }
        else if (idx < 0 || idx > size)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        else
        {
            Node *t = new Node(val);
            Node *temp = head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }
};

int main()
{
    LinkedList ll;

    ll.InsertAtTail(10);
    ll.Display();

    ll.InsertAtTail(20);
    ll.Display();

    ll.InsertAtTail(30);
    ll.Display();

    ll.InsertAtTail(40);
    ll.Display();
    ll.InsertAtTail(50);
    ll.Display();

    ll.InsertAtTail(60);
    ll.Display();

    ll.InsertAtHead(5);
    ll.Display();

    ll.InsertAtIndex(2, 100);
    ll.Display();

    return 0;
}