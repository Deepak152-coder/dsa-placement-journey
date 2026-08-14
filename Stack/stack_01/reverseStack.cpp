#include <bits/stdc++.h>
using namespace std;
void display(stack<int> st)
{
    while (st.size())
    {
        int temp = st.top();
        cout << temp << " ";
        st.pop();
    }
    cout << endl;
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

    vector<int> arr;

    display(st);

    while (st.size())
    {
        int temp = st.top();
        st.pop();
        arr.push_back(temp);
    }

    display(st);

    for (int i = 0; i < arr.size(); i++)
    {
        st.push(arr[i]);
    }
    display(st);

    return 0;
}