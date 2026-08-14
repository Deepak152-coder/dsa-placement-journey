#include <bits/stdc++.h>
using namespace std;

void display(stack<int> &st)
{
    if (!st.size())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    display(st);

    st.push(temp);
    cout << st.top() << " ";
}

void pushAtBottom(stack<int> &st, int val)
{
    if (!st.size())
    {
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();

    pushAtBottom(st, val);

    st.push(temp);
}

void reverseStack(stack<int> &st)
{
    if (!st.size())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    reverseStack(st);

    pushAtBottom(st, temp);
}

int main()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout << "Original stack: ";
    display(st);
    cout << endl;

    pushAtBottom(st, 10);

    cout << "After pushing 10 at bottom: ";
    display(st);
    cout << endl;

    reverseStack(st);

    cout << "After reversing: ";
    display(st);
    cout << endl;

    return 0;
}