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

void Display(Node *head)
{
    int k = 0;
    Node *temp = head;
    cout << "Iterative Display : ";
    while (temp)
    {
        cout << temp->val << " ";
        k++;
        temp = temp->next;
    }
    cout << endl;
    cout << "Size is : " << k << endl;
}

void RecRevDisplay(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    RecRevDisplay(head->next);
    cout << head->val << " ";
}

void RecDisplay(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->val << " ";
    RecDisplay(head->next);
}

int main()
{

    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);

    a->next = b;
    b->next = c;
    c->next = d;

    Node *temp = a;

    Display(a);

    cout << "Recursive Reverse Display : ";
    RecRevDisplay(a);
    cout << endl;

    cout << "Recursive Display : ";
    RecDisplay(a);

    return 0;
}