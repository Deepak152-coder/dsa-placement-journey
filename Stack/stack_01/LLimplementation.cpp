#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class Stack
{
public:
    Node *head;
    int count;

    Stack()
    {
        head = NULL;
        count = 0;
    }

    void push(int val)
    {
        Node *temp = new Node(val);

        temp->next = head;
        head = temp;

        count++;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;

        delete temp;
        count--;
    }

    int top()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return head->val;
    }

    int getSize()
    {
        return count;
    }

    bool empty()
    {
        return head == NULL;
    }

    void display(Node *temp)
    {
        if (temp == NULL)
        {
            return;
        }

        display(temp->next);
        cout << temp->val << " ";
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Stack: ";
    st.display(st.head);
    cout << endl;

    cout << "Top: " << st.top() << endl;
    cout << "Size: " << st.getSize() << endl;

    st.pop();

    cout << "After pop: ";
    st.display(st.head);
    cout << endl;

    cout << "Top: " << st.top() << endl;
    cout << "Size: " << st.getSize() << endl;

    if (st.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}