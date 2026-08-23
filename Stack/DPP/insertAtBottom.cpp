#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    stack<int> insertAtBottom(stack<int> &st, int x)
    {
        stack<int> temp;

        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }

        st.push(x);

        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }

        return st;
    }
};

int main()
{
    int n;
    cin >> n;

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    int x;
    cin >> x;

    Solution obj;
    st = obj.insertAtBottom(st, x);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}