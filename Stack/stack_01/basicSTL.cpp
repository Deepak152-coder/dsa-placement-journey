#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // Top element
    cout << "Top element: " << st.top() << endl;

    // Size
    cout << "Size: " << st.size() << endl;

    // Pop element
    st.pop();

    cout << "After pop, top element: " << st.top() << endl;

    // Check if stack is empty
    if (st.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    // Print all elements
    cout << "Stack elements: ";

    while (st.size())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;

    return 0;
}