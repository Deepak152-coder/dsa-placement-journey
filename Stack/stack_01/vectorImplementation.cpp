#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    vector<int> arr;

    void push(int val)
    {
        arr.push_back(val);
    }

    void pop()
    {
        if (arr.size() == 0)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        arr.pop_back();
    }

    int top()
    {
        if (arr.size() == 0)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return arr.back();
    }

    int size()
    {
        return arr.size();
    }

    bool empty()
    {
        return arr.size() == 0;
    }
};

void display(Stack st)
{
    if (!st.size())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    display(st);

    cout << temp << " ";
}

int main()
{
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout << "Stack: ";
    display(st);
    cout << endl;

    cout << "Top element: " << st.top() << endl;

    cout << "Size: " << st.size() << endl;

    st.pop();

    cout << "After pop: ";
    display(st);
    cout << endl;

    cout << "Top element: " << st.top() << endl;

    cout << "Size: " << st.size() << endl;

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